#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct stu
{
	int score, chinese, id;
};
vector<stu> students;
bool cmp(stu &a, stu &b)
{
	if (a.score == b.score)
	{ // 如果两个同学总分相同
		if (a.chinese == b.chinese)
		{						// 如果两个同学总分和语文成绩都相同
			return a.id < b.id; // 规定学号小的同学排在前面
		}
		return a.chinese > b.chinese; // 按语文成绩从高到低排序
	}
	return a.score > b.score; // 按总分从高到低排序
}
int main()
{
	int n;
	cin >> n;
	stu tmp;
	int math, english;
	for (int i = 1; i <= n; i++)
	{
		cin >> tmp.chinese >> math >> english;
		tmp.score = tmp.chinese + math + english;
		tmp.id = i;
		students.push_back(tmp);
	}
	sort(students.begin(), students.end(), cmp);
}