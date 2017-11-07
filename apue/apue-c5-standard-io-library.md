# 第5章 标准I/O库

## 1. Buf and setbuf P117

> 标准错误是不带缓冲的，打开至终端设备的流是行缓冲的，其他的流是全缓冲的

* `setbuf`函数可以指定缓冲区，`buf`为`NULL`表示关闭缓冲，否则必须指向一个长度为`BUFSIZ`的缓冲区
* `setvbuf`函数可以精确说明缓冲类型，`mode`参数可取`_IOFBF`（全）,`_IOLBF`（行）,`_IONBF`（关）

```c
#include <stdio.h>
void setbuf(FILE *fp, char *buf);
int setvbuf(FILE *fp, char *buf, int mode, size_t size);
// both returns: 0 if OK, nonzero on error
```


## 2. 流和FILE对象 P119 

* 标准输入，标准输出和标准错误

| 流    | 文件描述符`fd`       | 文件指针`fp` | 路径名                    |
| ---- | --------------- | -------- | ---------------------- |
| 标准输入 | `STDIN_FILENO`  | `stdin`  | /dev/stdin, /dev/fd/0  |
| 标准输出 | `STDOUT_FILENO` | `stdout` | /dev/stdout, /dev/fd/1 |
| 标准错误 | `STDERR_FILENO` | `stderr` | /dev/stderr, /dev/fd/2 |

* `fopen`函数打开路径名为`pathname`指定的文件，`freopen`将一个流重定向到指定的文件
* `fclose`函数关闭一个打开的流

```c
#include <stdio.h>
FILE *fopen(const char *pathname, const char *type); // opens a specified file
FILE *freopen(const char *pathname, const char *type, FILE *fp); 
FILE *fdopen(int fd, const char *type); // All return: file pointer if OK, NULL on error
int fclose(FILE *fp); // returns: 0 if OK, EOF on error
```

| `type`                 | description                              | open(2) flags            |
| ---------------------- | ---------------------------------------- | ------------------------ |
| `r` or `rb`            | open for reading                         | O_RDONLY                 |
| `w+` or `w+b` or `wb+` | truncate to 0 length or create for reading and | O_RDWR\|O_CREAT\|O_TRUNC |


## 3. Reading and Writing a Stream  P120

```c
#include <stdio.h>
// read one character at a time
int getc(FILE *fp); // returns: next character if OK, EOF on end of file or error
int putc(int c, FILE *fp); // returns: c if OK, EOF on error

// line at a time I/O
char *fgets(char *buf, int n, FILE *fp); 
// reads up through and including the next newline, but no more than n−1 characters, into the buf, returns: buf if OK, NULL on end of file or error
int fputs(const char *str, FILE *fp); // writes the null-terminated string to the specified stream, without the null byte
```

>We should always use fgets and fputs, and we always have to deal with the newline haracter at the end of each line.

* 二进制I/O，`fwrite`从`ptr`写入`nobj`个大小为`size`的元素写到`fp`指定的流  P125

```c
size_t fread(const void *ptr, size_t size, size_t nobj, FILE *fp);
size_t fwrite(const void *ptr, size_t size, size_t nobj, FILE *fp);
// both return: number of objects read or written
```


## 4. 定位流 P126

* `ftell`函数取得文件的字节位置，`fseek`类似`lseek`，`rewind`将流设置到文件的起始位置
* `fgetpos`函数将文件位置指示器的当前值存入`pos`指向的对象中，`fsetpos`则设置

```c
long ftell(FILE *fp); // returns: current file position indicator if OK, −1L on error
int fseek(FILE *fp, long offset, int whence); // returns: 0 if OK, −1 on error
int fseeko(FILE *fp, off_t offset, int whence); // use off_t like lseek
void rewind(FILE *fp);
int fgetpos(FILE *fp, fpos_t *pos);
int fsetpos(FILE *fp, fpos_t *pos); both return: 0 if OK, nonzero on error
```


## 5. Formatted I/O  P127
* `fprintf`函数将格式化数据写到指定的流，`printf`写到标准输出
* `sprintf`写入数组`buf`，并在数组尾端自动添加null字节，但该字节不包括在返回值计数中

```c
#include <stdio.h>
int printf(char *format, ...);
int fprintf(FILE *fp, char *format, ...)
int dprintf(int fd, char *format, ...);
// all return: number of characters output if OK, negative value if output error 
int sprintf(char *buf, char *format, ); // returns: number of characters stored in array if OK, negative value if encoding error
int snprintf(char *buf, size_t n, const char *format, ...);
// returns: number of characters that would have been stored in array if buffer was large enough, negative value if encoding error

int scanf(const char *format, ...);
int fscanf(FILE *fp, const char *format, ...);
int sscanf(const char *buf, const char *format, ...);
// all three return: number of input items assigned, EOF if input error or end of file before any conversion
```

## 6. 临时文件 P134
* `tmpnam`函数产生一个与现有文件名不同的一个有效路径名字符串，存入ptr并返回
* `tmpfile`函数返回一个临时二进制文件（wb+），关闭该文件或程序结束时自动删除

```c
char *tmpnam(char *ptr); // returns: pointer to unique pathname
FILE *tmpfile(); // returns: file pointer if OK, NULL on error
```

## 7. 课堂作业2
* `getopt`函数用来处理命令行选项 P536
* `options`参数是一个包含该命令支持的选项字符的字符串，若选项字符后面接了一个冒号，则表示该选项需要参数，例：`cmd [-i] [-u username] [-z] filename`对应的`options`应为"iu:z"
* 4个外部变量
    * `optarg`，如果一个选项需要参数，在处理该选项时，`getopt`会设置`optarg`指向该选项的参数字符串
    * `opterr`，如果一个选项发生了错误，`getopt`会默认打印一条出错消息吗，将`opterr`设置为0可以禁止这个行为
    * `optind`，用来存放下一个要处理的字符串在`argv`数组里的下标，它从1开始，每处理一个参数，`getopt`会对其递增1
    * `optopt`，如果处理选项时发生了错误，`getopt`会设置`optopt`指向导致出错的选项字符串

```c
#include <unistd.h>
int getopt(int argc, char *argv[], char *options); 
// returns: the next option character, or −1 when all options have been processed
extern int optind, opterr, optopt;
extern char *optarg;
```

题目：
> 创建一个新文件，用‘c’填充文件。默认文件大小为4K。
>  
> 文件大小通过参数filesize设定。
>  
> ./createFile [-s filesize] filename

My solution
```c
#include <stdio.h>
#include <unistd.h> // for getopt
#include <fcntl.h> // for creat, S_IRWXU
#include <stdlib.h> // for exit, atoi, exit, EXIT_FAILURE

int main(int argc, char *argv[])
{
    int opt;
    int filesize = 4096;
    while ((opt = getopt(argc, argv, "s:")) != -1)
    {
        if (opt == 's')
        {
            filesize = atoi(optarg);
        }
        else
        {
            fprintf(stderr, "Usage: %s [-s filesize] filename\n", argv[0]);
            exit(EXIT_FAILURE);
        }
    }
    char *filename = argv[optind];
    char buf[filesize + 1];
    for (int i = 0; i < filesize; ++i)
    {
        buf[i] = 'c';
    }
    buf[filesize] = '\0';

    /* use file io
    mode_t mode = 0666;
    int fd = creat(filename, mode);
    if (write(fd, buf, filesize) != filesize) {
        fprintf(stderr, "write error");
    }
    close(fd);
    */

    /* use stdio */
    FILE *fp = fopen(filename, "w");
    // fprintf(fp, "%s", buf);
    fputs(buf, fp); // fputs writes the string s to stream, without its terminating null byte
    fclose(fp);

    return 0;
}
```
