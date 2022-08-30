#include<iostream>
#include<queue>
#include<string>
using namespace std;

int alpa[27], N, sum = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> N;
	priority_queue<pair<int, char>> q;
	vector<string> word;
	for (int i = 0; i < N; i++)
	{
		string a;
		cin >> a;
		word.push_back(a);
		for (int j = a.length()-1; j >= 0; j--)
		{
			int num = 1;
			for (int k = 0; k < a.length()-1 - j; k++)
			{
				num *= 10;
			}
			alpa[a[j] - 65] += num;
		}
		
	}
	for (int i = 0; i < 27; i++)
	{
		if (alpa[i] == 0)
		{
			continue;
		}
		q.push({ alpa[i], (char)(i + 65)});
		alpa[i] = 0;
	}
	
	int num = 9;
	while (!q.empty())
	{
		int x = q.top().first;
		char a = q.top().second;

		q.pop();
		sum += (x * num);
		num--;

	}
	cout << sum;

		
}