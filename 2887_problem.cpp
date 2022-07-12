#include<iostream>
#include<vector>
#include<algorithm>
#define MAX_V 100002
using namespace std;
int parent[MAX_V];
vector<int> map[MAX_V];

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

		map[i].push_back(x);
		map[i].push_back(y);
		map[i].push_back(z);

		parent[i] = i;
	}
	vector<vector<int>> impo;


	//for (int i = 0; i < N; i++) 출력하기
	//{
	//	cout << map[i][0] <<" " << map[i][1]<<" " << map[i][2] << "\n";
	//}
	vector<int> exam(3, 0);
	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			int x1 = map[i][0];
			int y1 = map[i][1];
			int z1 = map[i][2];

			int x2 = map[j][0];
			int y2 = map[j][1];
			int z2 = map[j][2];


			int distance = min(min(abs(x1 - x2), abs(y1 - y2)), abs(z1 - z2));

			exam[0] = distance;
			exam[1] = i;
			exam[2] = j;

			impo.push_back(exam);
		}
	}
	sort(impo.begin(), impo.end());

	for (int i = 0; i < impo.size(); i++)
	{
		int a = FindParent(impo[i][1]);
		int b = FindParent(impo[i][2]);
		if (a == b)
		{
			continue;
		}
		Union_(a, b);
		result += impo[i][0];

	}
	cout << result;

}