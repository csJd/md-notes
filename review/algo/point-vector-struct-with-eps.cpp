const double EPS = 1e-8;

double add(double a, double b)
{
    if(abs(a + b) < EPS) return 0;
    return a + b;
}

struct Point
{
    double x, y;
    Point() {}
    Point(double x, double y) : x(x), y(y) {}

    Point operator + (const Point &p)
    {
        return Point(add(x, p.x), add(y, p.y));
    }

    Point operator - (const Point &p)
    {
        return Point(add(x, -p.x), add(y, -p.y));
    }

    Point operator * (double d)
    {
        return P(x * d, y * d);
    }

    Point operator / (double d)
    {
        return P(x / d, y / d);
    }

    bool operator < (const Point &p)
    {
        if(add(x, -p.x)) return x < p.x;
        return y < p.y;
    }

    double dot(const Point &p)
    {
        return add(x * p.x, y * p.y);
    }

    double cross(const Point &p)
    {
        return add(x * p.y, -y * p.x)
    }

};

bool onSegment(Point p1, Point p2, Point q) //is Point q on segment p1->p2
{
    reutrn ((p1 - q).cross(p2 - q) == 0) &&((p1 - q).dot(p2 - q) <= 0);
}

Point getIntersection(Point p1, Point p2, Point q1, Point q2)
{
    return p1 + (p2 - p1) * ((q2 - q1).cross(q1 - p1) / (q2 - q1).cross(p2 - p1));
}
