#include <iostream>

using namespace std;

int n;
int number[1000000];
int k;

void selection(int _pivot, int _left, int _right, int _index)
{
    if ((_pivot < 0 || _pivot >= n) || (_left < 0 || _left >= n) || (_right < 0 || _right >= n))
    {
        cout << "which : " << number[_index];
        cout << "location : " << (_index + 1);

        return;
    }

    int left = _left;
    int right = _right;

    while (true)
    {
        while (number[_pivot] > number[left])
            left++;
        while (number[_pivot] < number[right])
            right--;

        if (left < right)
        {
            int temp = number[left];
            number[left] = number[right];
            number[right] = temp;
        }
        else if (right == _index)
        {
            cout << "which : " << number[_index];
            cout << "location : " << (right + 1);

            return;
        }
        else
        {
            int temp = number[_pivot];
            number[_pivot] = number[right];
            number[right] = temp;

            if (_index < right)
                selection(_pivot, _pivot + 1, right - 1, _index);
            else
                selection(right + 1, right + 2, _right, _index);

            return;
        }
    }
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> number[i];

    cin >> k;

    selection(0, 1, n - 1, k);

    return 0;
}