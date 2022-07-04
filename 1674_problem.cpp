#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 100003
vector<int> group(MAX + 1);
int Find(int x)
{
	if (group[x] == x)
	{
		return x;
	}
	return group[x] = Find(group[x]);

}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int node, edge;
	int max_edge = 0;
	cin >> node >> edge;
	int result = 0;
	vector<vector<int>> map(edge, vector<int>(3, 0));
	for (int i = 0; i < edge; i++)
	{
		cin >> map[i][1] >> map[i][2] >> map[i][0];
	}
	for (int i = 1; i <= node; i++)
	{
		group[i] = i;
	}

	sort(map.begin(), map.end());

	for (int i = 0; i < edge; i++)
	{
		int a = Find(map[i][1]);
		int b = Find(map[i][2]);
		if (a == b)
		{
			continue;
		}

		group[b] = a;
		result += map[i][0];

		if (map[i][0] > max_edge) max_edge = map[i][0];
	}
	result -= max_edge;
	cout << result;
}