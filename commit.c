/*
 * Name: Krishiev Reddy
 * SRN: PES1UG24CS235
 */

// commit.c — Commit creation and history traversal

#include "commit.h"
#include "index.h"
#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>

// Forward declarations (implemented in object.c)
int object_write(ObjectType type, const void *data, size_t len, ObjectID *id_out);
int object_read(const ObjectID *id, ObjectType *type_out, void **data_out, size_t *len_out);

// ─── TODO IMPLEMENTATION ───────────────────────────────────────────────────

int commit_create(const char *message, ObjectID *commit_id_out) {
    if (!message || !commit_id_out) return -1;

    Commit commit;
    memset(&commit, 0, sizeof(Commit));

    // 1. Build tree from index
    if (tree_from_index(&commit.tree) != 0) {
        return -1;
    }

    // 2. Read parent (if exists)
    ObjectID parent_id;
    if (head_read(&parent_id) == 0) {
        commit.parent = parent_id;
        commit.has_parent = 1;
    } else {
        commit.has_parent = 0; // first commit
    }

    // 3. Set author (SRN-based)
    snprintf(commit.author, sizeof(commit.author), "PES1UG24CS235");

    // 4. Set timestamp
    commit.timestamp = (uint64_t)time(NULL);

    // 5. Set message (with SRN tag)
    snprintf(commit.message, sizeof(commit.message),
             "[SRN: PES1UG24CS235] %s", message);

    // 6. Serialize commit
    void *data;
    size_t len;
    if (commit_serialize(&commit, &data, &len) != 0) {
        return -1;
    }

    // 7. Write commit object
    if (object_write(OBJ_COMMIT, data, len, commit_id_out) != 0) {
        free(data);
        return -1;
    }

    free(data);

    // 8. Update HEAD
    if (head_update(commit_id_out) != 0) {
        return -1;
    }

    // 9. Debug output (helps in screenshots)
    printf("[INFO] Commit created successfully by PES1UG24CS235\n");

    return 0;
}
