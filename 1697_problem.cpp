#include<iostream>
#include<queue>
#define MAX_V 100000
using namespace std;
int visit[MAX_V];
queue<int> q;
int N, K;
int bfs() {
	
	q.push(N);
	visit[N] = 1;

	while (!q.empty())
	{
		int current = q.front();
		q.pop();

		if (current == K) return visit[current] - 1;

		if (current - 1 >= 0 && visit[current-1] == 0)
		{		
			visit[current - 1] = visit[current] + 1;
			q.push(current - 1);
		}
		if (current + 1 <= MAX_V && visit[current + 1] == 0)
		{
			visit[current + 1] = visit[current] + 1;
			q.push(current + 1);
		}
		if (current * 2 <= MAX_V && visit[current * 2] == 0)
		{
			visit[current * 2] = visit[current] + 1;
			q.push(current * 2);
		}
	}
	

}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	cout << bfs();
	
}