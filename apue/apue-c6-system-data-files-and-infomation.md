# 第6章 系统数据文件和信息

## 1. User database `passwd` 结构 P142

* */etc/passwd*文件中的一行：`root:x:0:0:root:/root:/bin/bash`
* `getpwuid`和`getpwnam`函数分别根据`uid`和`name`参数来获取对应用户在 password database 中的记录
* `getpwent`函数返回 password database 中的下一个记录项，`setpwent`倒回到 password database 的开始，`endpwent`关闭所有前两个函数打开的相关文件

```c
#include <pwd.h>
struct passwd {
    char   *pw_name;       /* username */
    char   *pw_passwd;     /* user password */
    uid_t   pw_uid;        /* user ID */
    gid_t   pw_gid;        /* group ID */
    char   *pw_gecos;      /* user information */
    char   *pw_dir;        /* home directory */
    char   *pw_shell;      /* shell program */
};
struct passwd *getpwuid(uid_t uid);
struct passwd *getpwnam(char *name); // both return: pointer if OK, NULL on error
struct passwd *getpwent(void); //returns: pointer if OK, NULL on error or end of file
void setpwent(void);
void endpwent(void);
```

* 类似上一组函数，下面这组函数用于访问 shadow password 文件

```c
#include <shadow.h>
struct spwd *getspnam(const char *name);
struct spwd *getspent(void); // both return: pointer if OK, NULL on error
void setspent(void);
void endspent(void);
```



## 2. 组文件

