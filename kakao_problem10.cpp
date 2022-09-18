#include <string>
#include <vector>

using namespace std;

int PAY[10000];
bool visit[10000];
vector<int> solution(vector<int> fees, vector<string> records) {
	vector<int> answer;

	fill(&PAY[0], &PAY[10000], 0);

	for (int i = 0; i < records.size(); i++)
	{
		int time = (stoi(records[i].substr(0, 2))) * 60 + stoi(records[i].substr(3, 4));
		int carnum = stoi(records[i].substr(6, 9));
		if (records[i][records[i].length() - 1] == 'N')
		{
			visit[carnum] = true;
			PAY[carnum] -= time;
		}
		else
		{
			PAY[carnum] += time;
		}
	}
	int paytime = 0;
	int money;
	for (int i = 0; i <= 9999; i++)
	{
		if (!visit[i])
			continue;
		if (PAY[i] <= 0)
		{
			PAY[i] += 1439;
		}
		if (PAY[i] <= fees[0])
		{
			answer.push_back(fees[1]);
		}
		else
		{
			paytime = PAY[i] - fees[0];
			if (paytime % fees[2] == 0)
			{
				money = (paytime / fees[2]) * fees[3] + fees[1];
			}
			else
			{
				money = ((paytime / fees[2]) + 1) * fees[3] + fees[1];
			}
			answer.push_back(money);
		}
	}

	return answer;
}