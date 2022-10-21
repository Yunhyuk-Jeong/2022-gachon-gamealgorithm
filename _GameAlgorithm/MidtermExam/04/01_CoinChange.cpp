#include <iostream>

using namespace std;

int main()
{
    int n;
    int coinType[5] = {500, 100, 50, 10, 1};
    int count = 0;

    cin >> n;

    for (int i = 0; i < 5; i++)
    {
        count += (n / coinType[i]);
        n %= coinType[i];
    }

    cout << count;
}