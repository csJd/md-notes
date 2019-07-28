#include <cstdio>
#include <string>
using namespace std;

struct test
{
    char c; //1
    int i;  //4
    char s[10]; //10
};

struct testAgain
{
    char c; //1
    char s[10]; //10
};

int main()
{
    char c;
    printf("%d\n", sizeof(c));
    //output 1

    char s[10] = "hello";
    printf("%d\n", sizeof(s));
    //output 10

    char *p = "hello";
    printf("%d\n", sizeof(p));
    //output 4
    printf("%d\n", sizeof(*p));
    //output 1

    char ca[] = "hello";
    printf("%d\n", sizeof(ca));
    //output 6

    test t;
    printf("%d\n", sizeof(t));
    //output 20

    test ta;
    printf("%d\n", sizeof(t));
    //output 11
    //http://www.cnblogs.com/bewolf/p/4356903.html

    test *pt;
    printf("%d\n", sizeof(pt));
    //output 4

    return 0;
}
