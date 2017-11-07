/*
    Description
    获取一个文件的权限
    ./myls
    usage: myls somefile
    ./myls a.txt
    rwx
    ./myls b.txt
    r-x
*/

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
