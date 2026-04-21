# PES Version Control System (PES VCS)

## 📌 Note

The **complete project report with all required screenshots** has been uploaded as a **PDF file in this repository**.
Please refer to that document for detailed execution steps and outputs.

📄 Document Name: **PES1UG24CS235_KrishievReddy_OrangeProblemU4**

---

## 👨‍💻 Author

**Krishiev Reddy**
**SRN: PES1UG24CS235**

---

## 📖 Overview

This project implements a simplified version of a Git-like Version Control System called **PES VCS**.
It demonstrates core filesystem and version control concepts such as:

* Content-addressable storage
* Object-based design (blob, tree, commit)
* Staging area (index)
* Commit history tracking
* Atomic file operations

---

## 🧱 Project Structure

```
.pes_pes1ug24cs235/
├── objects/        # Stores all objects (blob, tree, commit)
├── refs/heads/     # Branch references
├── HEAD            # Points to current branch
├── index           # Staging area
```

---

## ⚙️ Features Implemented

### ✅ Phase 1: Object Storage

* Stores file content as **blob objects**
* Uses SHA-256 hashing for unique identification
* Prevents duplicate storage

---

### ✅ Phase 2: Tree Objects

* Represents directory structure using tree objects
* Supports hierarchical file organization

---

### ✅ Phase 3: Index (Staging Area)

* Tracks files before committing
* Stores metadata: mode, hash, timestamp, size
* Supports:

  * `pes add`
  * `pes status`

---

### ✅ Phase 4: Commits and History

* Creates commit objects linking snapshots
* Maintains commit history using parent references
* Supports:

  * `pes commit`
  * `pes log`

---

## 🚀 How to Run

### 1. Compile

```bash
make clean
make pes
```

---

### 2. Initialize Repository

```bash
./pes init
```

---

### 3. Add Files

```bash
echo "Hello" > hello.txt
./pes add hello.txt
```

---

### 4. Commit Changes

```bash
./pes commit -m "Initial commit"
```

---

### 5. View Status

```bash
./pes status
```

---

### 6. View Commit History

```bash
./pes log
```

---

## 🧠 Key Concepts

### 🔹 Blob

Stores file content.

### 🔹 Tree

Represents directory structure.

### 🔹 Commit

Stores snapshot + metadata + parent reference.

---

## 🔐 Design Highlights

* **Content-addressable storage** ensures integrity
* **Atomic writes (temp + rename)** prevent corruption
* **Hash-based identification** avoids duplication
* **Linked commit history** enables version tracking

---

## 📸 Screenshots

All required screenshots for:

* Object storage
* Tree structure
* Index operations
* Commit history

📄 **are included in the uploaded PDF report.**

---

## 🏁 Conclusion

This project successfully demonstrates the internal working of a version control system, including how files are stored, tracked, and versioned efficiently using hashing and structured object storage.

---

### ✅ SRN used: **PES1UG24CS235**
