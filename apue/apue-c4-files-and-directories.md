### 1.  stat, fstat, lstat（P74）

```c
#include <sys/stat.h>
int stat(const char *pathname, struct stat *buf);
//buf得到pathname指定文件有关的信息结构，stat结构定义见P75
int fstat(int fd, struct stat *buf);
//用fd指定文件
int lstat(const char *pathname, struct stat *buf); 
//当pathname对应文件为一个符号链接时，得到链接有关信息而不是该链接所引用文件的信息

//Return: 0 on success, -1 on error
```

### 2. 文件类型信息包含在`stat`结构的`st_mode`成员中（P76）

| Macro       | Type of file   |
| ----------- | -------------- |
| `S_ISERG()` | regular file   |
| `S_ISDIR()` | directory file |
| `S_ISLNK()` | symbolic link  |

`#define S_ISDIR(mode) (((mode) & S_IFMT) == S_IFDIR)  //pre defined in <sys/stat.h>`

Usage：`if (S_ISREG(buf.st_mode)) {//do something if the ralated file is regular file}`



### 3. File Access Permissions （EP99）

| `st_mode` mask | Meaning       |
| -------------- | ------------- |
| `S_IRUSR`      | user-read     |
| `S_IWGRP`      | group-write   |
| `S_IXOTH`      | other-execute |

test access function (EP102)

```c
#include <unistd.h>
int access(const char *pathname, int mode); //mode: F_OK, R_OK, W_OK, X_OK
int faccessat(int fd, const char *pathname, int mode, int flag);
//Both return: 0 if OK, -1 on error
```



### 4. `umask` and `chmod` related (EP104)

```c
#include <sys/stat.h>
mode_t umask(mode_t cmask); //returns: previous file mode creation mask
int chmod(const char *pathname, mode_t mode); //returns: 0 if OK, −1 on error
int chown(const char *pathname, uid_t owner, git_t group);//returns: 0 if OK, −1 on error
```



### 5. File Truncation (EP112)

```c
#include <unistd.h>
int truncate(const char *pathname, off_t length); //returns: 0 if ok, -1 on error
```



### 6. `link` related (EP116) 

```c
#include <unistd.h>
int link(const char *existingpath, const char *newpath);
int unlink(const char *pathname);
int remove(const char *pathname); 
int symlink(const char *actualpath, const char *sympath);//both return: 0 if ok, -1 on error
```

