# MY GIT CHEAT SHEET

### Get manual

```sh
git help [-a|--all] [-g|--guide] [-i|--info|-m|--man|-w|--web] [COMMAND|GUIDE]
man git help
```


### Basics

| branch name    | mean                                 |
| -------------- | ------------------------------------ |
| master(origin) | default development(upstream) branch |
| HEAD           | current branch                       |
| HEAD^ (HEAD~1) | parent of HEAD                       |
| HEAD~4         | the great-great grandparent of HEAD  |

```shell
git clone -b branch repo_addr  # Clone specific branch of a repo

git blame $file # Who changed what and when in a file
git show $id[:$file] # A commit identified by $ID [about a specific file]

git rm --cached $file # Unstage and remove $file only from the index
git reset --hard # Return to the last committed state and cannot undo
git revert $id # Revert specific commit and creates a new commit
git checkout $id $file # Checkout the $id version of a file

git merge $b1 # Merge branch $b1 into current branch
git checkout -b $b2 $b1 # Create branch $b2 based on branch $b1 and switch to it

git grep "foo()" # Search working directory for foo()
git tag v1.0 # Mark a version/milestone
```


### Github related
* [Download a single folder or directory from a GitHub repo](https://stackoverflow.com/questions/7106012/download-a-single-folder-or-directory-from-a-github-repo/)

```sh
svn ls https://github.com/csJd/csJd.github.io/branches/master
svn ls https://github.com/csJd/csJd.github.io/branches/hexo/scaffolds
svn co https://github.com/csJd/csJd.github.io/branches/hexo/scaffolds # with .svn folder
svn export https://github.com/csJd/csJd.github.io/branches/hexo/scaffolds # without .svn
```

* Create an empty branch and update to github
```sh
git clone repo-url
git checkout --orphan new-branch-name
git rm -rf .
touch .gitignore
git add .
git commit -m "Add .gitignore"
git push
```


# My Frequently Forgotten Facts (FFFs)
------
### 1. Set my [.gitconfig](https://git-scm.com/docs/git-config#_syntax)
Learn it [here](https://classroom.udacity.com/courses/ud775/lessons/2980038599/concepts/33417185870923)

``` sh
git config --global core.editor "'d:/dsr/sublime-text-3/sublime_text.exe' -n -w"
# Configure Git on Windows to properly handle line endings
# git config --global core.autocrlf true
git config --global push.default upstream
git config --global merge.conflictstyle diff3
git config --global user.name "Deng"
git config --global user.email "scutjd@gmail.com"
git config --global http.proxy 'socks5://127.0.0.1:1080'
# git config --edit --global  # edit config in text editor
```

### 2. `diff`s
cmd|first|second
:---:|:---:|:---:
`git diff`|working directory|staging area
`git diff --staged`|staging area|HEAD
`git diff commit1`|commit1|HEAD
`git diff commit1 commit2`|commit1|commit2
`git show commit1`|commit1's parent|commit1

### 3. branch
* `git branch`  Show branchs
* `git branch new-branch-name`  Create a new branch
* `git checkout branch-name`  Switch to a branch (even a remote branch)
* `git checkout -b new-brach-name`  Create a new branch and switch to it
* `git merge branch1 branch2 ...`  Merge branch1 and branch2 into current branch 
* `git branch -d branch-name`  Delete a branch
* `git checkout --orphan new-brach-name` Create a new unparented branch

### 4. remote
* `git remote`  Show remotes
* `git remote -v`  Show remotes more verbose
* `git remote add <remote-name> <url>`  Adds a remote named `<remote-name>` for the repository at `<url>`
* `git remote rm <remote-name>`  Remove a remote named `<remote-name>`
```sh
 git remote add origin git@github.com:csJd/pl-review.git
 # change remote url, 'origin' is remote name
 git remote set-url origin git@github.com:USERNAME/REPOSITORY.git
```
* `git push <remote-name> <branch-name>`  Push local branch named `<branch-name>` to remote named `<remote-name>`
* `git push -u <remote-name> <local-branch-name>:<remote-branch-name>`  Set default upstream for a local branch
```sh
  git push origin master
  git push -u origin master:master
```
* `git pull <remote-name> <branch-name>`  Pull remote named `<remote-name>` to local branch named `<branch-name>`
``` bash
  git pull origin master
```
which equals
```sh
git fetch origin
git merge master origin/master
```
