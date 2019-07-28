#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
char s[N], t[N];
int p[N];

void manacher()
{
    strcpy(t, s);
    int l = strlen(s);
    for(int i = 0; i < l; ++i)
    {
        t[i * 2] = '#';
        t[i * 2 + 1] = s[i];
    }
    l = l * 2 + 1, t[l - 1] = '#', t[l] = 0;
    puts(t);

    int k = 0;
    for(int i = 0; i < l; ++i)
    {
        p[i] = i > k * 2 ? 1 : min(p[k * 2 - i], k + p[k] - i);
        while(i >= p[i] && t[i - p[i]] == t[i + p[i]]) ++p[i];
        if(i + p[i] > k + p[k]) k = i;
    }

    for(int i = 0; i < l; ++i)
        printf("%d ", p[i]);
    puts("");
}

int main()
{
    while(~scanf("%s", s))
    {
        manacher();
    }
    return 0;
}
//Last modified :  2015-10-06 16:45 CST


