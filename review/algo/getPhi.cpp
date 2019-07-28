#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int pme[N>>2], vis[N], phi[N];

void getPhi() //get phi[i], i in 2...N
{
	int m = 0;
	for(int i = 2; i < N; ++i)
	{
		if(!vis[i]) pme[m++] = i, phi[i] = i - 1;
		for(int j = 0; j < m && pme[j] * i < N; ++j)
		{
			vis[i * pme[j]] = 1;
			if(i % pme[j] == 0)
			{
				phi[i * pme[j]] = phi[i] * pme[j];
				break;
			}
			phi[i * pme[j]] = phi[i] * (pme[j] - 1);
		}
	}
}


int main()
{
	int n;
	getPhi();
	while(~scanf("%d", &n))
	{
		for(int i = 0; i < n; ++i)
			printf("%d%c",phi[i],  i % 8 < 7 ? ' ' : '\n');
	}
    return 0;
}
//Last modified :  2015-10-09 19:45 CST
