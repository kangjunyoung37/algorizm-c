#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;
int Parent[200001];

int FindParent(int start)
{
	if (Parent[start] == start)
	{
		return start;
	}
	return Parent[start] = FindParent(Parent[start]);
}
bool Union_(int a, int b)
{
	a = FindParent(a);
	b = FindParent(b);
	if (a == b)
		return false;
	Parent[b] = a;
	return true;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<tuple<int, int, int>> map;
	int m, n;
	int x, y, d, result = 0, total;
	while (1)
	{
		total = 0;
		result = 0;
		cin >> m >> n;
		map.clear();
		if (m == 0 && n == 0)
		{
			break;
		}

		for (int i = 0; i < n; i++)
		{
			cin >> x >> y >> d;
			map.push_back({ d,x,y });
			Parent[i] = i;
			total += d;
		}
		sort(map.begin(), map.end());

		for (int i = 0; i < map.size();i++)
		{
			int a = get<1>(map[i]);
			int b = get<2>(map[i]);
			int dis = get<0>(map[i]);

			if (Union_(a, b))
			{
				result += dis;
			}
		}
		cout << total - result << "\n";


	}
	/*for (int i = 0; i < map.size();i++)
	{

		cout << get<0>(map[i]) << " " << get<1>(map[i]) << " " << get<2>(map[i]) << "\n";
	}  정렬 확인 */
}
