#include<iostream>
#include<queue>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	int A, B;
	cin >> A >> B;
	int cnt = 0;
	queue<int> q;
	q.push(B);
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		if (x == A)
		{
			cout << cnt + 1;
			exit(0);
		}
		if (x == 0)
		{
			break;
		}
		if (x % 2 == 0)
		{
			x /= 2;
			cnt += 1;
			q.push(x);
			continue;
		}
		else if (x % 10 == 1)
		{
			x /= 10;
			cnt += 1;
			q.push(x);
			continue;

		}
	}
	cout << -1; 

}