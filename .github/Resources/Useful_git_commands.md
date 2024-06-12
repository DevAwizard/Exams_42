## 🛠️ Useful Git Commands

### 📁 Repository Management
- **Clone a repository:**
  ```sh
  git clone <repository-url>

- **Create a new repository:**
```sh
git init
```

### 📄 File Operations

- **Add files to staging area:**

```sh
git add <file-name>
```
- **or add all changes:**

```sh
git add .
```
- **Check the status of files:**

```sh
git status
```

### 💾 Commit Changes

- **Commit staged changes:**

```sh
git commit -m "commit message"
```

- **Amend the last commit:**

```sh
git commit --amend -m "new commit message"
```
### 🔄 Sync with Remote

- **Push changes to the remote repository:**

```sh
git push
```

- **Pull changes from the remote repository:**

```sh
git pull
```

### 🔍 Review Changes

- **Show commit history:**

```sh
git log
```
- **Show changes:**

```sh
git diff
```

### 🌿 Branching and Merging

- **Create a new branch:**

```sh
git checkout -b <branch-name>
```

- **Switch to an existing branch:**

```sh
git checkout <branch-name>
```

- **Merge a branch into the current branch:**

```sh
git merge <branch-name>
```

### 🗑️ Undo Changes

- **Discard changes in working directory:**

```sh
git checkout -- <file-name>
```
- **Revert a commit by creating a new commit:**

```sh
git revert <commit-hash>
```
- **Reset the staging area and working directory to the last commit:**
```sh
git reset --hard
```






---
