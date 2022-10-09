#include<iostream>
#include<stack>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string str;
	cin >> str;
	stack<char> st;
	string answer = "";
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			answer += str[i];
		}
		else if (str[i] == '(')
		{
			st.push(str[i]);
		}
		else if (str[i] == '+' || str[i] == '-')
		{
			while (!st.empty() && st.top() != '(')
			{
				answer += st.top();
				st.pop();
			}
			st.push(str[i]);
		}
		else if (str[i] == '*' || str[i] == '/')
		{
			while (!st.empty() && (st.top() == '*' || st.top() == '/'))
			{
				answer += st.top();
				st.pop();
			}
			st.push(str[i]);
		}
		else if (str[i] == ')')
		{
			while (!st.empty() && st.top() != '(')
			{
				answer += st.top();
				st.pop();
			}
			st.pop();
		}
	}
	while (!st.empty())
	{
		answer += st.top();
		st.pop();
	}
	cout << answer;
}