#include <bits/stdc++.h>
using namespace std;
const int N = 20005;
int id[N], vs[N], dep[N], k;
int minp[N][32];
vector<int> g[N];

void dfs(int i, int p, int d)
{
    id[i] = k;
    vs[k] = i;
    dep[k++] = d;
    for(int j = 0; j < g[i].size(); ++j)
    {
        if(g[i][j] == p) continue;
        dfs(g[i][j], i, d + 1);
        vs[k] = i;
        dep[k++] = d;
    }
}

void initST()
{
    for(int i = 0; i < k; ++i) minp[i][0] = i;
    for(int j = 1; 1 << j <= k; ++j)
    {
        for(int i = 0; i + (1 << j) <= k; ++i)
        {
            int l = minp[i][j - 1], r = minp[i + (1 << j - 1)][j - 1];
            minp[i][j] = dep[l] < dep[r] ? l : r;
        }
    }
}

int queryST(int l, int r)
{
    if(l > r) swap(l, r);
    int j = log2(r - l + 1);
    if(dep[minp[l][j]] < dep[minp[r + 1 - (1 << j)][j]])
        return minp[l][j];
    return minp[r + 1 - (1 << j)][j];
}

int main()
{
    int n, m, a, b, q, root;
    while(~scanf("%d%d", &n, &m))
    {
        for(int i = 0; i < m; ++i)
        {
            scanf("%d%d", &a, &b);
            g[a].push_back(b);
            g[b].push_back(a);
        }


        dfs(root = 1, -1, k = 0);

//        for(int i = 0; i < k; ++i)
//            printf("%d ", vs[i]);
//        puts("");
//        for(int i = 0; i < k; ++i)
//            printf("%d ", dep[i]);
//        puts("");

        initST();

        scanf("%d", &q);
        while(q--)
        {
            scanf("%d%d", &a, &b);
            printf("%d\n", vs[queryST(id[a], id[b])]);
        }

    }
    return 0;
}
//Last modified :  2015-10-07 16:54 CST
/*
8 7
1 2
1 3
2 4
2 5
3 6
5 7
5 8
10
5 6
*/

