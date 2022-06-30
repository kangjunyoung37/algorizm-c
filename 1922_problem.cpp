#include<iostream>
#include<algorithm>
#include<vector>
#define MAX 1002
using namespace std;
vector<int> group(MAX);
int Find(int start)
{
	if (start == group[start])
		return start;
	return group[start] = Find(group[start]);
}
void union_(int a, int b)
{
	a = Find(a);
	b = Find(b);
	if (a == b)
	{
		return;
	}
	group[b] = a;
}

int main() 
{
	int node, edge;
	int num = 1;
	cin >> node;
	cin >> edge;
	vector<vector<int>> map(edge, vector<int>(3, 0));
	int result = 0;
	for (int i = 0; i < edge; i++)
	{
		cin >> map[i][1] >> map[i][2] >> map[i][0];
	}
	for (int i = 1;i <= node;i++) {
		group[i] = i;
	}
	sort(map.begin(), map.end());
	for (int j = 0; j < edge; j++)
	{
		int a = Find(map[j][1]);
		int b = Find(map[j][2]);
		if (a == b)
		{
			continue;
		}
		union_(a, b);
		result += map[j][0];
	}
	cout << result;

	
}

