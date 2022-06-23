#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int checkDFS[1001];
int checkBFS[1001];
vector<int> v[1001];

void DFS(int t)
{
	if (checkDFS[t]) return;
	checkDFS[t] = true;

	cout << t << " ";

	for (int i = 0; i < v[t].size(); i++)//���� ��ȣ�� ���� ���� ���� �湮�ϱ� ������ �������� ����
	{
		sort(v[t].begin(), v[t].end());
	}
	for (int i = 0; i < v[t].size(); i++)//����Ǿ� �ִ� �����߿��� ���� �ͺ��� ������� �湮
	{
		int a = v[t][i];
		DFS(a);
	}



}
void BFS(int t)
{
	queue<int> q;
	q.push(t);
	checkBFS[t] = true;
	while (!q.empty())//ť�� ������� ���� �� ����
	{
		int x = q.front();
		q.pop();

		cout << x << " ";

		for (int i = 0; i < v[x].size(); i++)//���� �ͺ��� �湮�ϱ� ������ �������� ����
		{
			sort(v[x].begin(), v[x].end());
		}
		for (int i = 0; i < v[x].size(); i++)//
		{
			int a = v[x][i];

			if (!checkBFS[a])
			{
				q.push(a);
				checkBFS[a] = true;
			}
		}
	}
}
int main()
{
	int n, m, c = 0;
	cin >> n >> m >> c;
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;

		v[x].push_back(y);
		v[y].push_back(x);
	}

	DFS(c);
	cout << endl;
	BFS(c);
	return 0;
}