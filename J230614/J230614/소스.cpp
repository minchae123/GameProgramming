#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class member 
{
public:
	string name;
	int age;
};

bool compare(member& a, member& b)
{
	return a.age > b.age; // 내림차순
}

int main() 
{
	vector<int> vt1{ 6,3,4,5,2,1,7 };
	sort(vt1.begin(), vt1.end()); // 오름차순 정렬
	sort(vt1.begin(), vt1.end(), greater<int>()); 
	vector<member> vt2{ {"고라파덕", 8}, {"피카츄", 7}, {"잠만보", 10} };
	sort(vt2.begin(), vt2.end(), compare);
	
}