#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int pme[N>>2], vis[N], m;

void getPrime()
{
	m = 0;
	for(int i = 2; i < N; ++i)
	{
		if(!vis[i]) pme[m++] = i;
		for(int j = 0; j < m && i * pme[j] < N; ++j)
		{
			vis[i * pme[j]] = 1;
			if(i % pme[j] == 0) break;
		}
	}
}

int main()
{
	getPrime();
	int n;
	while(~scanf("%d", &n))
	{
		for(int i = 0; pme[i] <= n; ++i)
			printf("%d%c", pme[i], i % 8 < 7 ? ' ':'\n');
	}
    
    return 0;
}
//Last modified :  2015-10-09 19:46 CST
