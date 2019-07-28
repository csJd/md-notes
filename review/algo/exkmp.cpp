#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 10005;
char p[N], s[N];
int pex[N], sex[N], lp, ls;

/*
pex[0...i-1]均已经求出  0 < k < i && k + pex[k]最大
p[k, k + pex[k]) == p[0, pex[k]) => p[i, k + pex[k]) == p[i - k, pex[k])
当i + pex[i - k] < k + pex[k]时  显然pex[i] = pex[i - k]
否则 要继续从k + pex[k] - i 匹配
*/

void exkmp()
{
    int k = 0, j = 0;
    pex[0] = lp;
    for(int i = 1; i < lp; ++i) //get pex[]
    {
        if(k) j = pex[i - k];
        if(!k || i + j >= k + pex[k])
        {
            if(!k || k + pex[k] < i) j = 0;
            else j = k + pex[k] - i;
            while(i + j < lp && p[i + j] == p[j]) ++j;
            k = i;
		}
		pex[i] = j;
    }

    j = k = 0;
    for(int i = 0; i < ls; ++i) // get sex[]
    {
        if(k) j = pex[i - k];
        if(!k || i + j >= k + sex[k])
        {
            if(!k || k + sex[k] < i) j = 0;
            else j = k + sex[k] - i;
            while(j < lp && i + j < ls && s[i + j] == p[j]) ++j;
            k = i;
        }
        sex[i] = j;
    }
}

int main()
{
    while(~scanf("%s%s", s, p))
    {
        ls = strlen(s);
        lp = strlen(p);
        exkmp();
        puts("pex:");
        for(int i = 0; i < lp; ++i)
            printf("%d ",  pex[i]);
        puts("\nsex:");
        for(int i = 0; i < ls; ++i)
            printf("%d ",  sex[i]);
        puts("");
    }
    return 0;
}
//Last modified :  2015-09-29 09:58 CST

