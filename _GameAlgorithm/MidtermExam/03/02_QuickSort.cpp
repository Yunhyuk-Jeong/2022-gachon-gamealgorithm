#include <iostream>

using namespace std;

int n;
int m[1000000];

void quickSort(int *data, int start, int end)
{
    if (start >= end)
        return;

    int pivot = start;
    int i = pivot + 1;
    int j = end;
    int tmp;

    while (i <= j)
    {
        while (i <= end && data[i] <= data[pivot])
            i++;
        while (j > start && data[j] >= data[pivot])
            j--;

        if (i > j)
        {
            tmp = data[j];
            data[j] = data[pivot];
            data[pivot] = tmp;
        }
        else
        {
            tmp = data[i];
            data[i] = data[pivot];
            data[pivot] = tmp;
        }
    }

    quickSort(data, start, j - 1);
    quickSort(data, j + 1, end);
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> m[i];

    quickSort(m, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << m[i];

    return 0;
}