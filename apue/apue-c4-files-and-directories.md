# 第4章 文件和目录

## 1. stat, fstat, lstat P74
* `stat`函数执行成功后，`buf`得到`pathname`指定文件有关的信息结构，stat结构定义见P75
* `stat`结构成员`st_size`表示以字节为单位的文件长度
```c
#include <sys/stat.h>
int stat(const char *pathname, struct stat *buf);
int fstat(int fd, struct stat *buf);  // 用fd指定文件
int lstat(const char *pathname, struct stat *buf); 
// 当pathname对应文件为一个符号链接时，得到链接有关信息而不是该链接所引用文件的信息
// all return: 0 on success, -1 on error
```


## 2. 文件类型信息包含在`stat`结构的`st_mode`成员中 P76

| Macro       | Type of file   |
| ----------- | -------------- |
| `S_ISERG()` | regular file   |
| `S_ISDIR()` | directory file |
| `S_ISLNK()` | symbolic link  |

`#define S_ISDIR(mode) (((mode) & S_IFMT) == S_IFDIR) // pre defined in <sys/stat.h>`

Usage：`if (S_ISREG(buf.st_mode)) { // do something if the ralated file is regular file}`



## 3. 文件访问权限 P79

* `st_mode`值包含了对文件的访问权限位，每个文件有9个访问权限位
| `st_mode` mask | Meaning       |
| -------------- | ------------- |
| `S_IRUSR`      | user-read     |
| `S_IWGRP`      | group-write   |
| `S_IXOTH`      | other-execute |

* `access`函数按进程的 real user ID 和 real group ID进行访问权限测试
```c
#include <unistd.h>
int access(const char *pathname, int mode); // mode: F_OK, R_OK, W_OK, X_OK
int faccessat(int fd, const char *pathname, int mode, int flag); // both return: 0 if OK, -1 on error
```

| mode   | 说明       | mode   | 说明     |
| ------ | -------- | ------ | ------ |
| `F_OK` | 测试文件是否存在 | `R_OK` | 测试读权限  |
| `W_OK` | 测试写权限    | `X_OK` | 测试执行权限 |


## 4. `umask` and `chmod` related P83

* `umask`函数为进程设置文件创建屏蔽字为cmask，并返回之前的值
* `chmod`函数更改现有文件的访问权限为`mode`
* `chown`函数更改文件的用户ID和组ID，新ID为-1则表示对应ID不变

```c
#include <sys/stat.h>
mode_t umask(mode_t cmask); // returns: previous file mode creation mask
int chmod(const char *pathname, mode_t mode); // returns: 0 if OK, −1 on error
int chown(const char *pathname, uid_t owner, git_t group);// returns: 0 if OK, −1 on error
```



## 5. 文件截断 P90
* `truncate`函数将`pathname`指定的文件的长度截断为`length`
* 若该文件的长度大于`length`，则超过`length`以外的数据不再能访问
* 若该文件的长度效于`length`，则新旧尾端之间的数据将读作0
```c
#include <unistd.h>
int truncate(const char *pathname, off_t length); // returns: 0 if OK, -1 on error
```



## 6. `link` related P93
* `link`函数创建一个新目录项`newpath`，它引用现有文件`existingpath`
* `unlink`函数删除目录项`pathname`，并将其所引用文件的链接计数减1
* 对于文件，`remove`函数的功能与`unlink`相同，对于目录，与`rmdir`相同
* `symlink`函数创建一个指向`actualpath`的符号链接，并不要求`actualpath`已经存在，不要求同一文件系统
```c
#include <unistd.h>
int link(const char *existingpath, const char *newpath);
int unlink(const char *pathname);
int remove(const char *pathname); 
int symlink(const char *actualpath, const char *sympath); // P99
// all return: 0 if ok, -1 on error
```
* `rename`函数将`oldname`指向的文件或目录重命名为`newname` P96
```c
#include <stdio.h>
int rename(char *oldname, char *newname); // returns: 0 if OK, -1 on error
```



## 7. 文件的时间 P99

* `stat`结构对每个文件维护3个时间字段，字段类型为`struct timespec`
| 字段    | 说明              | 例子        | ls选项 |
| ------- | ---------------- | ----------- | ------- |
| st_atim | 文件数据的最后访问时间      | read        | -u      |
| st_mtim | **文件数据**的最后修改时间  | write       | 默认      |
| st_ctim | **i节点状态**的最后更改时间 | chmod,chown | -c      |

* `futimens`函数可以更改文件的访问和修改时间，`times[0]`为访问时间，`times[1]`为修改时间
```c
int futimens(int fd, timespec times[2]);
```


## 8. 目录相关 P103

* `mkdir`函数用来创建路径名为`pathname`的目录，`mode`指定访问权限
* `opendir`函数打开一个目录，返回指向`pathname`的目录指针
* `readdir`函数读目录，返回目录中第一个目录项到`dirent`结构中
* `chdir`函数切换进程的当前工作目录，即相对路径名的起点
* `getcwd`函数执行成功后，`buf`得到当前工作目录的绝对路径名

```c
#include <sys/stat.h>
int mkdir(char *pathname, mode_t mode); 
#include <stdlib.h>
int rmdir(char *pathname); // both return: 0 if OK, −1 on error
#include <dirent.h>
DIR *opendir(const char *pathname); // returns: pointer if OK, NULL on error
struct dirent *readdir(DIR *dp);
#include <unistd.h>
int chdir(const char *pathname); // returns: 0 if OK, −1 on error
char *getcwd(char *buf, size_t size); // returns: buf if OK, NULL on error
```



## 9. quiz1

> 获取一个文件的权限
> 
> $ ./myls
> 
> usage: myls somefile
> 
> $ ./myls a.txt
> 
> rwx
> 
> $ ./myls b.txt
> 
> r-x

My solution：

```c
#include <stdio.h>
#include <unistd.h> // for access
#include <stdlib.h> // for exit, EXIT_FAILURE

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    char *filename = argv[1];
    if (access(filename, F_OK))
    {
        fprintf(stderr, "File not exists\n");
        exit(EXIT_FAILURE);
    }

    char output[] = "---";
    if (!access(filename, R_OK)) output[0] = 'r';
    if (!access(filename, W_OK)) output[1] = 'w';
    if (!access(filename, X_OK)) output[2] = 'x';
    printf("%s\n", output);

    return 0;
}
```

