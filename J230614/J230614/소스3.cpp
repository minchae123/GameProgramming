#include <iostream>
#include <algorithm>

using namespace std;
int n, c[100001] = {}, m;
void check(int i)
{
    int left = 0;
    int right = n - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (c[mid] == i)
        {
            cout << "1\n";
            return;
        }
        else if (c[mid] > i)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    cout << "0\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }

    sort(c, c + n);

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int tmp;
        cin >> tmp;
        check(tmp);
    }
    return 0;
}
