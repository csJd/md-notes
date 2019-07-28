#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
int a[N], st[N][32], n;

void initST() //st[i][j] = max{a[x], i <= x < i + 2^j}
{
    for(int i = 0; i < n; ++i) st[i][0] = a[i];
    for(int j = 1; 1 << j <= n; ++j)
    {
        for(int i = 0; i + (1 << j) <= n; ++i)
            st[i][j] = max(st[i][j - 1], st[i + (1 << j - 1)][j - 1]);
    }
}

int queryST(int l, int r)
{
    int i = log2(r - l + 1);
    return max(st[l][i], st[r + 1 - (1 << i)][i]);
}

int main()
{
    int q, l, r;
    while(~scanf("%d", &n))
    {
        for(int i = 0; i < n; ++i)
            scanf("%d", &a[i]);
        initST();

        scanf("%d", &q);
        while(q--)
        {
        	scanf("%d%d", &l, &r);
        	printf("%d\n", queryST(l, r));
        }

    }
    return 0;
}
//Last modified :  2015-10-08 19:10 CST

