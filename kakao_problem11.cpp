#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	vector<pair<float, float>> rate(N + 2, { 0,0 });
	vector<pair<float, int>> result;
	for (int i = 0; i < stages.size();i++)
	{
		for (int j = 1; j <= stages[i]; j++)
		{
			rate[j].second += 1;
		}
		rate[stages[i]].first += 1;
	}
	for (int i = 1; i <= N;i++)
	{
		float a = rate[i].first / rate[i].second;
		result.push_back({ -a,i });
	}
	stable_sort(result.begin(), result.end());
	for (int i = 0; i < result.size();i++)
	{
		answer.push_back(result[i].second);
	}
	return answer;
}