#include<iostream>
#include<queue>
#define MAX_E 987654321
using namespace std;

int F, S, G, U, D;
int visited[1000001];
void bfs(int start) {

	queue<pair<int,int>> q;
	q.push({start,0});
	visited[start] = 0;
	while (!q.empty())
	{
		int current = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (current == G)
		{
			break;
		}
		int upnext = current + U;
		int downnext = current - D;
		if (upnext <= F && visited[upnext] > cnt + 1)
		{
			visited[upnext] = cnt + 1;
			q.push({ upnext,cnt + 1 });
		}
		if (downnext > 0 && visited[downnext] > cnt +1)
		{
			visited[downnext] = cnt + 1;
			q.push({ downnext,cnt + 1 });
		}

	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> F >> S >> G >> U >> D;

	for (int i = 0; i <= F; i++)
	{
		visited[i] = MAX_E;
	}
	bfs(S);
	if (visited[G] == MAX_E)
	{
		cout << "use the stairs";
	}
	else
	{
		cout << visited[G];
	}

}