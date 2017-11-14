/*
    Description
    获取一个文件的权限，不能使用access函数
    ./myls
    usage: myls somefile
    ./myls a.txt
    rwx
    ./myls b.txt
    r-x
*/

#include <stdio.h>
#include <sys/stat.h> // for stat
#include <stdlib.h> // for exit, EXIT_FAILURE

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    char *filename = argv[1];
    struct stat buf;
    if (stat(filename, &buf) < 0)
    {
        fprintf(stderr, "Stat error, please check the filename\n");
        exit(EXIT_FAILURE);
    }

    mode_t mode = buf.st_mode;
    char output[] = "---";
    if (mode & S_IRUSR) output[0] = 'r';
    if (mode & S_IWUSR) output[1] = 'w';
    if (mode & S_IXUSR) output[2] = 'x';
    printf("%s\n", output);

    return 0;
}
