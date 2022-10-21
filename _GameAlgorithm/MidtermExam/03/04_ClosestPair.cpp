#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

struct Point
{
    int x;
    int y;

    bool operator<(const Point &b) const
    {
        if (x == b.x)
            return y < b.y;
        else
            return x < b.x;
    }
};

int distance(Point a, Point b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

bool compareY(Point a, Point b)
{
    return a.y < b.y;
}

int searchAll(vector<Point> &v, int s, int e)
{
    int minDist = -1;

    for (int i = s; i <= e - 1; i++)
        for (int j = i + 1; j <= e; j++)
        {
            int dist = distance(v[i], v[j]);

            if (minDist == -1 || minDist > dist)
                minDist = dist;
        }

    return minDist;
}

int searchPoint(vector<Point> &v, int start, int end)
{
    int count = end - start + 1;

    if (count <= 3)
        return searchAll(v, start, end);

    int mid = (start + end) / 2;
    int left = searchPoint(v, start, mid);
    int right = searchPoint(v, mid + 1, end);

    int result;

    if (left > right)
        result = right;
    else
        result = left;

    vector<Point> final;

    for (int i = start; i <= end; i++)
    {
        int xDistance = v[i].x - v[mid].x;

        if (xDistance * xDistance < result)
            final.push_back(v[i]);
    }

    int maxIndex = final.size();

    sort(final.begin(), final.end(), compareY);

    for (int i = 0; i < maxIndex - 1; i++)
        for (int j = i + 1; j < maxIndex; j++)
        {
            int y = final[i].y - final[i].y;

            if (y * y < result)
            {
                int dist = distance(final[j], final[i]);
                if (dist < result)
                    result = dist;
            }
            else
                break;
        }

    return result;
}

int main()
{
    int n;

    cin >> n;

    vector<Point> points(n);

    for (int i = 0; i < n; i++)
        cin >> points[i].x >> points[i].y;

    sort(points.begin(), points.end());

    int result = searchPoint(points, 0, n - 1);

    cout << result;
}