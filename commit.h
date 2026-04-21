/*
 * Name: Krishiev Reddy
 * SRN: PES1UG24CS235
 *
 * File: commit.h
 * Description: Commit object interface for PES Version Control System
 */

#ifndef COMMIT_H
#define COMMIT_H

#include "pes.h"
#include <stdint.h>

/*
 * Commit Structure
 * Each commit represents a snapshot of the project along with metadata.
 * SRN tagging ensures traceability of commits.
 */
typedef struct {
    ObjectID tree;          // Root tree hash (project snapshot)
    ObjectID parent;        // Parent commit hash
    int has_parent;         // 0 for initial commit, 1 otherwise

    char author[256];       // Author (SRN: PES1UG24CS235)
    uint64_t timestamp;     // Unix timestamp of commit creation

    char message[4096];     // Commit message (includes SRN tag)
} Commit;

/*
 * Create a commit from the current index.
 *
 * Steps:
 *   1. Build tree from index
 *   2. Read current HEAD as parent (if exists)
 *   3. Create commit object and store it
 *   4. Update HEAD to new commit
 *
 * SRN Integration:
 *   - Author field uses SRN: PES1UG24CS235
 *   - Message includes [SRN: PES1UG24CS235]
 *
 * Returns:
 *   0 on success, -1 on failure
 */
int commit_create(const char *message, ObjectID *commit_id_out);

/*
 * Parse raw commit data into structured format
 */
int commit_parse(const void *data, size_t len, Commit *commit_out);

/*
 * Serialize commit struct into raw format for storage
 * Caller must free(*data_out)
 */
int commit_serialize(const Commit *commit, void **data_out, size_t *len_out);

/*
 * Walk commit history starting from HEAD
 */
typedef void (*commit_walk_fn)(const ObjectID *id, const Commit *commit, void *ctx);
int commit_walk(commit_walk_fn callback, void *ctx);

/*
 * Read current HEAD commit hash
 */
int head_read(ObjectID *id_out);

/*
 * Update HEAD to new commit (atomic write)
 */
int head_update(const ObjectID *new_commit);

#endif // COMMIT_H
