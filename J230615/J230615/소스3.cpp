#include<iostream>
#include <unordered_map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    unordered_map<string, int> map;
    int n, m;
    cin >> n >> m;
    string str;
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> str;
        map[str]++;
    }

    for (int i = 0; i < m; i++)
    {
        cin >> str;
        if (map[str] == 1) cnt++;
        map[str]++;
    }

    cout << cnt << '\n';
    for (auto i : map)
    {
        if (i.second >= 2)
        {
            cout << i.first << "\n";
        }
    }
}