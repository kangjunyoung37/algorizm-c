#include<iostream>
#include<queue>

using namespace std;
int visited[10000];
int a, b;
void bfs()
{
	queue<pair<int, string>> q;
	q.push({ a,"" });
	visited[a] = 1;
	while (!q.empty())
	{
		int x = q.front().first;
		string result = q.front().second;
		q.pop();

		if (x == b)
		{
			cout << result << "\n";
			return;
		}
		int D, S, L, R, temp;

		D = (x * 2) % 10000;
		if (!visited[D])
		{
			visited[D] = 1;
			q.push({ D,result + 'D' });
		}

		S = x - 1 < 0 ? 9999 : x - 1;
		if (!visited[S])
		{
			visited[S] = 1;
			q.push({ S,result + 'S'});
		}

	
		L = (x % 1000) * 10 + (x / 1000);
		if (!visited[L])
		{
			visited[L] = 1;
			q.push({ L,result + 'L' });
		}

		R = x / 10 + (x % 10) * 1000;
		if (!visited[R])
		{
			visited[R] = 1;
			q.push({ R,result + 'R' });
		}

	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int Num;
	cin >> Num;
	for (int i = 0; i < Num; i++)
	{
		cin >> a >> b;
		fill(&visited[0], &visited[10000], 0);
		bfs();
		
	}
	return 0;
	
}