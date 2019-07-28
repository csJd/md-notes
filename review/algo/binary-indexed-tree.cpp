#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int a[N], int c[N], n;

void add(int p,int x)
{
	while(p>0) 
		c[p]+=x,p-=(p&-p);
	a[i] += x;
}

int getSum(int p)
{
	int ret = 0;
	for(int i=p; i>0; i-=(i&-i))
		ret += c[i];
	return ret;
}

int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		memset(a, 0, sizeof(a));
		memset(c, 0, sizeof(c));
		for(int i=1; i<=n; ++i)
		{
			scanf("%d",&t);
			add(i,t);
		}

		while(m--)
		{
			scanf("%s%d%d",op,&u,&v);
			if(op[0]=='Q') printf("%d\n",getSum(v) - getSim(u));
			else add(u, v);
		}
	}
    return 0;
}
//Last modified :   2015-04-14 09:46
