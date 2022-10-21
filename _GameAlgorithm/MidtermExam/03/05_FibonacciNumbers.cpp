#include <iostream>

using namespace std;

int d[10000001] = {
    0,
    1,
    1,
    0,
};

int fibonacci(int i)
{
    if (i < 3)
        return d[i];
    if (d[i] != 0)
        return d[i];
    return d[i] = fibonacci(i - 1) + fibonacci(i - 2);
}

int main()
{
    int n;

    cin >> n;

    cout << fibonacci(n);

    return 0;
}