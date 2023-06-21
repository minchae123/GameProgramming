#include <iostream>
#include <map>
#include <set>
#include <unordered_set>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    set<string> s1;
    set<string> s2;
    int n, m;
    string sound, see;
    cin >> n >> m;
    
    for (int i = 0; i < n; i++)
    {
        cin >> sound;
        s1.insert(sound);
    }

    for (int i = 0; i < m; i++)
    {
        cin >> see;
        if (s1.find(see) != s1.end())
        {
            s2.insert(see);
        }
    }

    cout << s2.size() << endl;
    for (auto i : s2)
    {
        cout << i << endl;
    }
}