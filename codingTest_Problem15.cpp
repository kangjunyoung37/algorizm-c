#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	vector<int> one = { 1,2,3,4,5 };
	vector<int> two = { 2,1,2,3,2,4,2,5 };
	vector<int> three = { 3,3,1,1,2,2,4,4,5,5 };
	int result[3] = { 0,0,0 };
	for (int i = 0; i < answers.size(); i++)
	{
		if (answers[i] == one[i % one.size()])
		{
			result[0] += 1;
		}
		if (answers[i] == two[i % two.size()])
		{
			result[1] += 1;
		}
		if (answers[i] == three[i % three.size()])
		{
			result[2] += 1;
		}

	}
	int Max = 0;
	for (int i = 0; i < 3; i++)
	{
		if (Max < result[i])
		{
			Max = result[i];
		}
	}

	for (int i = 0; i < 3; i++)
	{
		if (Max == result[i])
		{
			answer.push_back(i + 1);
		}
	}

	return answer;
}