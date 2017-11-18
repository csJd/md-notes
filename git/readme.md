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
svn co https://github.com/csJd/csJd.github.io/branches/hexo/scaffolds
```
