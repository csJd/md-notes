/*
   Description：
   创建一个新文件，用‘c’填充文件。默认文件大小为4K。
   文件大小通过参数filesize设定。
   ./createFile [-s filesize] filename
*/

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
