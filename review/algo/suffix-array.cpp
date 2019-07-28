#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
char s[N];
int n,k,sa[N],t[N];
bool cmp(int i,int j)
{
	if(rank[i]!=rank[j]) return rank[i]<rank[j];
	int ri = 0, rj = 0;
	if(i+k<=n) ri = rank[i+k];
	if(j+k<=n) rj = rank[j+k];
	return ri < rj;
}

int main()
{
	while(~scanf("%s",s))
	{
		n = strlen(s);
		for(int i = 0; i<=n; ++i)
		{
			sa[i] = i;
			rank[i] = (i<n?s[i]:-1);
		}
		for(int k<1; k<=n; k*=2)
		{
			sort(sa,sa+n+1,cmp);
			t[0] = 0;
			for(int i = 1; i<=n; ++i)
				t[sa[i]] = t[sa[i-1]] + cmp(sa[i-1],sa[i])?1:0;
			for(int i=0; i<=n ; ++i) rank[i] = t[i];
		}
		for(int i = 0 ;i<=n;++i)
			puts(s + sa[i]);

	}
    return 0;
}
//Last modified :   2015-04-20 09:46
