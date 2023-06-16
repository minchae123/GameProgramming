#include <iostream>
#include <vector>
using namespace std;

void BinarySearch(vector<int>& age)
{
	int left = 0, right = age.size() - 1;
	while (left <= right)
	{
        int mid = (left + right) / 2;
        string answer;
        cout << age[mid] << "살 입니까?: ";
        cin >> answer;

        if (answer == "YES")
        {
            cout << "WOW~!!";
            return;
        }
        else if (answer == "DOWN")
        {
            right = mid - 1;
        }
        else if (answer == "UP")
        {
            left = mid + 1;
        }
        else
        {
            cout << "제대로 말하세요~^^" << endl;
            return;
        }
	}
}

int main()
{
	vector<int> age;
	int min, max;
	cout << "나이의 최솟값과 최댓값 입력 : ";
	cin >> min >> max;
	for (int i = min; i < max; i++)
	{
		age.push_back(i);
	}

	cout << "나이가 맞다면 YES, 더 많다면 UP, 더 적다면 DOWN을 입력하세요" << endl;
}