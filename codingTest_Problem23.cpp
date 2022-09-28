#include<iostream>
#include<queue>
#include<string>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	vector<string> operations;
	vector<int> answer;
	
	priority_queue <int, vector<int>, greater<int>> gq;
	priority_queue <int, vector<int>, less<int>> lq;
	int n = 0;
	for (int i = 0; i < operations.size(); i++)
	{
		char oper = operations[i][0];
		int num = stoi(operations[i].substr(2));
		if (oper == 'I')
		{
			n++;
			gq.push(num);
			lq.push(num);

		}
		else
		{
			if (num == 1)
			{
				if (!lq.empty())
				{
					lq.pop();
					n--;
				}
			}
			else
			{
				if (!gq.empty())
				{
					gq.pop();
					n--;
				}
			}
			
		}
		if (n == 0)
		{
			gq = priority_queue<int, vector<int>, greater<int>>();
			lq = priority_queue<int, vector<int>, less<int>>();
		}

	}
	if (n <= 0)
	{
		answer.push_back(0);
		answer.push_back(0);

	}
	else
	{
		answer.push_back(lq.top());
		answer.push_back(gq.top());
	}

	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << " ";
	}
	

}