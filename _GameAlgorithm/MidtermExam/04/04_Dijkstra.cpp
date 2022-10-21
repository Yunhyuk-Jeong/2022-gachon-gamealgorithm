#include <iostream>

using namespace std;

int INF = 1000000;
int number = 6;

int a[6][6] = {
    {0, 2, 5, 1, INF, INF}, {2, 0, 3, 2, INF, INF}, {5, 3, 0, 3, 1, 5},
    {1, 2, 3, 0, 1, INF},   {INF, INF, 1, 1, 0, 2}, {INF, INF, 5, INF, 2, 0},
};

int d[6];
bool v[6];

int getSmallCurrent()
{
    int min = INF;
    int index = 0;

    for (int i = 0; i < 6; i++)
        if (!v[i] && d[i] < min)
        {
            min = d[i];
            index = i;
        }
    return index;
}

void dijkstra(int start)
{
    for (int i = 0; i < 6; i++)
        d[i] = a[start][i];

    v[start] = true;

    for (int i = 0; i < number - 2; i++)
    {
        int current = getSmallCurrent();
        v[current] = true;

        for (int j = 0; j < 6; j++)
            if (!v[j])
                if (d[j] > d[current] + a[current][j])
                    d[j] = d[current] + a[current][j];
    }
}

int main()
{
    dijkstra(0);

    for (int i = 0; i < 6; i++)
        cout << d[i] << " ";
}