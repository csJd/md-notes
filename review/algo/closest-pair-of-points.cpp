//HDU 1007, ZOJ 2107
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAX_N =  100005;

struct Point
{
    double x, y;
    bool operator< (const Point &p)
    {
        return x < p.x;
    }
} points[MAX_N];

bool cmpy(int i, int j)
{
    return points[i].y < points[j].y;
}

double dist(int i, int j)
{
    double diety = points[i].y - points[j].y;
    double dietx = points[i].x - points[j].x;
    return sqrt(dietx * dietx + diety * diety);
}

double closest(int l, int r)
{
    if (r == l + 1) return dist(l, r);
    else if(r == l + 2) return min(min(dist(l, l + 1), dist(l, l + 2)), dist(l + 1, l + 2));

    int m = (l + r) >> 1;
    double ret = min(closest(l, m), closest(m + 1, r));
    int mid[r - l + 1];
    int cnt = 0;
    for(int i = l; i <= r; ++i)
    {
        if(abs(points[m].x - points[i].x) < ret) mid[cnt++] = i;
    }
    sort(mid, mid + cnt, cmpy);

    for(int i = 0; i < cnt; ++i)
    {
        for(int j = i + 1; j < cnt; ++j)
        {
            if(points[mid[j]].y - points[mid[i]].y > ret) break;
            if(ret > dist(mid[i], mid[j])) ret = dist(mid[i], mid[j]);
        }
    }

    return ret;
}

int main()
{
    int n;
    while(scanf("%d", &n) == 1)
    {
        if(n == 0) break;
        for(int i = 0; i < n; ++i)
        {
            scanf("%lf %lf", &points[i].x, &points[i].y);
        }
        sort(points, points + n);
        printf("%lf\n", closest(0, n - 1));
    }

    return 0;
}
