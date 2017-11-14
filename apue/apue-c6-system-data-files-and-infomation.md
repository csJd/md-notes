# 第6章 系统数据文件和信息

## 1. User database `passwd` 结构 P142

* */etc/passwd* 文件中的一行：`root:x:0:0:root:/root:/bin/bash`
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
* */etc/shadow* 文件中的一行：`root:*:17431:0:99999:7:::`

```c
#include <shadow.h>
struct spwd *getspnam(const char *name);
struct spwd *getspent(void); // both return: pointer if OK, NULL on error
void setspent(void);
void endspent(void);
```



## 2. 组文件 P146

* 类似 passwd 相关函数，下面这组函数用于访问组文件
* */etc/group* 文件中的一行：`sudo:x:27:ubuntu,deng`
```c
#include <grp.h>
struct group *getgrgid(gid_t gid);
struct group *getgrnam(const char *name); // both return: pointer if OK, NULL on error
struct group *getgrent(void); //returns: pointer if OK, NULL on error or end of file
void setgrent(void);
void endgrent(void);
```

* 用户不仅可以属于`passwd`项中`pw_gid`所对应的组，还可属于至多16个另外的组 P147
* `getgroups`将进程所属用户的各附属组ID填写到`grouplist`中

```c
#include <unistd.h>
int getgroups(int gidsetsize, gid_t grouplist[]); // returns: number of supplementary group IDs if OK, −1 on error
int setgroups(int ngroups, const gid_t grouplist[]);
int initgroups(const char *username, gid_t basegid); // both return: 0 if OK, −1 on error
```



## 3. 系统标识 P150

* `uname`返回与主机和操作系统有关的信息
* `gethostname`将主机名写到`name`指定的字符串，`namelen`指定name缓冲区长度

```c
#include <sys/utsname.h>
struct utsname {
    char sysname[]; /* name of the operating system */
    char nodename[]; /* name of this node */
    char release[]; /* current release of operating system */
    char version[]; /* current version of this release */
    char machine[]; /* name of hardware type */
};
int uname(struct utsname *name); // returns: non-negative value if OK, −1 on error

#include <unistd.h>
int gethostname(char *name, int namelen); // returns: 0 if OK, −1 on error
```



## 4. 时间和日期 P151

* `time`返回当前时间和日期
* `clock_gettime`获取指定时钟的时间
* `clock_getres`把参数`tsp`指向的 timespec 结构初始化为与 clock_id 参数对应的时钟精度 P152
* `clock_settime`对特定时钟设定时间
* `gmtime`和`localtime`将日历时间转换为分解的时间，存放在 tm 结构中
* `strftime`通过多个参数来定制产生的字符串，类似于`printf`  P153

```c
#include <time.h>
time_t time(time_t *calptr); //returns: value of time if OK, −1 on error
time_t mktime(struct tm* tmptr);
size_t strftime(char *buf, size_t maxsize, const char *format, const struct tm* restrict tmptr);

#include <sys/time.h>
int clock_gettime(clockid_t clock_id, struct timespec* tsp);
int clock_getres(clockid_t clock_id, struct timespec* tsp);
int clock_settime(clockid_t clock_id, const struct timespec* tsp);
struct tm* gmtime(const time_t* calptr);
struct tm* localtime(const time_t* calptr);
```

