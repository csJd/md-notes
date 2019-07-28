#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int e[N], dn[N], p[N];

void getDiv()
{
	int cnt = 0;
	for(int i = 2; i < N; ++i)
	{
		if(!dn[i])
		{
			dn[i] = 2;
			e[i] = 1;
			p[cnt++] = i;
		}
		for(int j = 0; j < cnt && i * p[j] < N; ++j)
		{
			if(i % p[j] == 0)
			{
				e[i * p[j]] = e[i] + 1;
				dn[i * p[j]] = dn[ i * p[j] / pow(p[j], e[i])] * x;
				break;
			}
			dn[i * p[j]] = dn[i] * 2;
		}

int main()
{
    
    return 0;
}
#include<stdio.h>
#include<string.h>
#define M 10000
int prime[M], e[M], div_num[M];     // e[i]表示第i个素数因子的个数
bool flag[M];
void get_prime()
{
    int i, j, k;
    memset(flag, false, sizeof(flag));
    k = 0;
    for(i = 2; i < M; i++)
    {
        if(!flag[i])
        {
            prime[k++] = i;
            e[i] = 1;
            div_num[i] = 2;                     //素数的约数个数为2
        }
        for(j = 0; j < k && i * prime[j] < M; j++)
        {
            flag[i * prime[j]] = true;
            if(i % prime[j] == 0)
            {
                div_num[i * prime[j]] = div_num[i] / (e[i] + 1) * (e[i] + 2);
                e[i * prime[j]] = e[i] + 1;
                break;
            }
            else
            {
                div_num[i * prime[j]] = div_num[i] * div_num[prime[j]];
                e[i] = 1;
            }
        }
    }
}
int main()
{
    get_prime();
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i = 1; i < n; ++i)
            printf("%d\n", div_num[i]);
    }
    return 0;

}
//Last modified :   2015-07-13 15:05
