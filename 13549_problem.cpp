#include<iostream>
#include<queue>
#include<vector>
#define MAX_V 987654321
using namespace std;

int N, K;
int visit[100002];

void dijestra(int start)
{
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int> >> pq;
	//priority_queue<pair<int, int>> pq;
	pq.push({0,start});
	visit[start] = 1;

	while (!pq.empty())
	{

		int current = pq.top().second;
		int distance = pq.top().first;
		pq.pop();
		if (current == K)
		{
			cout << distance;
			break;
		}

		if (current - 1 >= 0 && visit[current - 1] == 0)
		{
			visit[current - 1] = 1;
			pq.push(make_pair(distance + 1, current - 1));
		}

		if (current * 2 <= K + 1 && visit[current * 2] == 0)
		{
			visit[current * 2] = 1;
			pq.push(make_pair(distance, current * 2));

		}
		if (current + 1 <= K && visit[current + 1] == 0)
		{
			visit[current + 1] = 1;
			pq.push(make_pair(distance + 1, current + 1));
		}
	



	}

}
int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;


	dijestra(N);

	/*for (int i = 0; i < K + 1; i++)
	{
		cout << visit[i];
	}*/
}