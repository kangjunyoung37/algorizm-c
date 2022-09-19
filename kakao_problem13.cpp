#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
	vector<int> answer;
	int num = 0;
	int zeronum = 0;

	for (int i = 0; i < lottos.size(); i++)
	{
		if (lottos[i] == 0)
		{
			zeronum += 1;
			continue;
		}
		for (int j = 0;j < win_nums.size(); j++)
		{
			if (lottos[i] == win_nums[j])
			{
				num += 1;
				break;
			}
		}
	}

	int result = 1;
	result += (6 - (num + zeronum));
	if (result > 6)
	{
		answer.push_back(6);
	}
	else
	{
		answer.push_back(result);
	}
	result = 1 + (6 - num);

	if (result > 6)
	{
		answer.push_back(6);
	}
	else
	{
		answer.push_back(result);
	}


	return answer;
}