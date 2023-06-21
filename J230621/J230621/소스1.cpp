#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    set<int> s;
    int n, m;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int b = 0;
        cin >> b;
        s.insert(b);
    }

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int b = 0;
        cin >> b;
        cout << s.count(b) << " ";
    }
}