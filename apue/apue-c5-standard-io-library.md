第5章 标准I/O库

## 1. Buf and setbuf P117

> 标准错误是不带缓冲的，打开至终端设备的流是行缓冲的，其他的流是全缓冲的

以下函数可以更改缓冲类型：

```C
#include <stdio.h>
void setbuf(FILE *fp, char *buf);
// buf must point to a buffer of length BUFSIZ or NULL for off
// turn buffering on or off, returns: 0 if OK, nonzero on error
```



## 2. Stream P119 

```C
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

```C
#include <stdio.h>
// read one character at a time
int getc(FILE *fp); // returns: next character if OK, EOF on end of file or error
int putc(int c, FILE *fp); // returns: c if OK, EOF on error

// line at a time I/O
char *fgets(char *buf, int n, FILE *fp); 
// reads up through and including the next newline, but no more than n−1 characters, into the buf, returns: buf if OK, NULL on end of file or error
int fputs(const char *str, FILE *fp); // writes the null-terminated string to the specified stream
```

>We should always use fgets and fputs, and we always have to deal with the newline haracter at the end of each line.

```C
// binary I/O
size_t fread(const void *ptr, size_t size, size_t nobj, FILE *fp);
size_t fwrite(const void *ptr, size_t size, size_t nobj, FILE *fp);
// both return: number of objects read or written
```



## 4. Formatted I/O  P127

```C
#include <stdio.h>
int printf(const char *format, ...);
int dprintf(int fd, const char *format, ...);
// both return: number of characters output if OK, negative value if output error 
int snprintf(char *buf, size_t n, const char *format, ...);
// returns: number of characters that would have been stored in array if buffer was large enough, negative value if encoding error

int scanf(const char *format, ...);
int fscanf(FILE *fp, const char *format, ...);
int sscanf(const char *buf, const char *format, ...);
// all three return: number of input items assigned, EOF if input error or end of file before any conversion
```
