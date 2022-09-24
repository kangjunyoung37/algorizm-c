#include<iostream>
#include<queue>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	bool answer = true;
	string s;
	cin >> s;

	if (s[0] == ')')
	{
		answer = false;
		//³¡
	}
	queue<char> q;
	for (int i = 0; i < s.length(); i++)
	{
		if (q.empty())
		{
			q.push(s[i]);
			continue;
		}
		if (q.front() == '(' && q.front() != s[i])
		{
			q.pop();
			continue;
		}
		else if (q.front() == ')')
		{
			answer = false;
		}
		else
		{
			q.push(s[i]);
		}
	}
	if (!q.empty())
	{
		answer = false;
	}
	cout << answer;
}