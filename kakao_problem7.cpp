#include <string>
#include <vector>
#include <stack>
using namespace std;

string solution(int n, int t, int m, int p) {
	string answer = "";
	string temp = "";
	int a = 0, c = 0, b;
	stack<int> st;
	while (temp.length() <= t * m)
	{
		if (a < n)
		{
			st.push(a);
			while (!st.empty())
			{
				if (st.top() >= 10)
				{
					char a = st.top() + 55;
					temp += a;
					st.pop();
					continue;
				}
				temp += to_string(st.top());
				st.pop();
			}
			c += 1;
			a = c;
			continue;

		}
		b = a % n;
		a /= n;

		st.push(b);
	}
	for (int i = 0; i < temp.length(); i++)
	{

		if (i % m == p - 1)
		{
			answer += temp[i];
		}
		if (answer.length() == t)
		{
			break;
		}
	}

	return answer;
}