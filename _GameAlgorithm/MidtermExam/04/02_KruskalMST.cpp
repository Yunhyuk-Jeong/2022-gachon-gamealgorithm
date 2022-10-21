#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int check[7];

class Edge
{
  public:
    int node[2];
    int distance;

    Edge(int a, int b, int distance)
    {
        this->node[0] = a;
        this->node[1] = b;
        this->distance = distance;
    }

    bool operator<(Edge &edge)
    {
        return this->distance < edge.distance;
    }
};

int getParent(int node)
{
    if (check[node] == node)
        return node;

    return getParent(check[node]);
}

void unionParent(int node1, int node2)
{
    node1 = getParent(node1);
    node2 = getParent(node2);

    if (node1 < node2)
        check[node2] = node1;
    else
        check[node1] = node2;
}

bool isCycle(int node1, int node2)
{
    node1 = getParent(node1);
    node2 = getParent(node2);

    if (node1 == node2)
        return true;
    else
        return false;
}

int main()
{
    vector<Edge> v;
    v.push_back(Edge(1, 7, 12));
    v.push_back(Edge(1, 4, 23));
    v.push_back(Edge(1, 2, 26));
    v.push_back(Edge(2, 3, 36));
    v.push_back(Edge(2, 4, 21));
    v.push_back(Edge(2, 5, 45));
    v.push_back(Edge(3, 5, 29));
    v.push_back(Edge(3, 6, 37));
    v.push_back(Edge(3, 7, 55));
    v.push_back(Edge(4, 7, 20));
    v.push_back(Edge(5, 6, 30));

    sort(v.begin(), v.end());

    for (int i = 1; i <= 7; ++i)
        check[i] = i;

    int sum = 0;

    for (int i = 0; i < v.size(); ++i)
        if (!isCycle(v[i].node[0], v[i].node[1]))
        {
            sum += v[i].distance;
            unionParent(v[i].node[0], v[i].node[1]);
        }

    cout << sum;

    return 0;
}