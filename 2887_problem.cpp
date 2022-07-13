#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
#define MAX_V 100002
using namespace std;
int parent[MAX_V];
vector<pair<int, int>> X;
vector<pair<int, int>> Y;
vector<pair<int, int>> Z;
vector<tuple<int, int, int>> map;
int result = 0;

int FindParent(int start) {

	if (parent[start] == start)
		return start;
	return parent[start] = FindParent(parent[start]);
}
void Union_(int a, int b)
{
	a = FindParent(a);
	b = FindParent(b);

	if (a == b)
		return;
	parent[b] = a;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int result = 0;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;

		X.push_back(make_pair(x,i));
		Y.push_back(make_pair(y,i));
		Z.push_back(make_pair(z,i));

		parent[i] = i;
	}


	//for (int i = 0; i < N; i++) 출력하기
	//{
	//	cout << map[i][0] <<" " << map[i][1]<<" " << map[i][2] << "\n";
	//}
	sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());
	sort(Z.begin(), Z.end());

	for (int i = 0; i < N-1; i++)
	{
		map.push_back({ X[i + 1].first - X[i].first,X[i].second,X[i + 1].second });
		map.push_back({ Y[i + 1].first - Y[i].first,Y[i].second,Y[i + 1].second });
		map.push_back({ Z[i + 1].first - Z[i].first,Z[i].second,Z[i + 1].second });

	}
	sort(map.begin(), map.end());

	for (int i = 0; i < map.size(); i++)
	{
		int a = get<0>(map[i]);
		int b = get<1>(map[i]);
		int c = get<2>(map[i]);

		int parentB = FindParent(b);
		int parentC = FindParent(c);

		if (parentB == parentC)
		{
			continue;
		}
		Union_(parentB, parentC);
		result += a;

	}
	cout << result;

}