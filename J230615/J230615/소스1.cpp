#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    string poket;

    map<int, string> m1;
    map<string, int> m2;

    for (int i = 1; i <= n; i++) {
        cin >> poket;
        m2[poket] = i;
        m1[i] = poket;
    }

    for (int i = 0; i < m; i++) {
        cin >> poket;
        if (isdigit(poket[0]))
            cout << m1[stoi(poket)] << "\n";
        else
            cout << m2[poket] << "\n";
    }
}