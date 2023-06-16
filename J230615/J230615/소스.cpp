#include <map>
#include <iostream>
#include <string>
using namespace std;

map<string, int> m;

int main() 
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		m[s]++;
	}

	int max = 0;
	string answer;
	for (auto p : m)
	{
		if (max < p.second) {
			max = p.second;
			answer = p.first;
		}
	}

	cout << answer;
}