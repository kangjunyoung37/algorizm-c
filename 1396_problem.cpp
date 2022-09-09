#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
#define INF 987654321
using namespace std;
int Parent[100001];
struct edge
{
	int d;
	int x;
	int y;
};
bool comp(const edge& a, const edge& b)
{
	return a.d < b.d;
}
vector<edge> map;
int FindParent(int son)
{
	if (Parent[son] == son)
	{
		return son;
	}
	return Parent[son] = (FindParent(Parent[son]));
}
bool Union_(int a, int b)
{
	a = FindParent(a);
	b = FindParent(b);
	if (a == b)
	{
		return false;
	}
	Parent[b] = a;

	return true;
}
int main()
{
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int x, y, temp;
		cin >> x >> y >> temp;
		map.push_back({ temp, x,y,});
		//map.push_back({ temp, y,x });
	}
	sort(map.begin(), map.end(),comp);
	int quary, cnt, temperature;
	cin >> quary;
	for (int i = 0; i < quary;i++)
	{
		for (int j = 1; j <= N; j++)
		{
			Parent[j] = j;
		}
		int x, y ;
		bool isgo = false;;
		cin >> x >> y;
		cnt = 0; temperature = 0;

		for (int num = 0; num < map.size(); num++)
		{

			if (Union_(map[num].x, map[num].y))
			{
				if (FindParent(x) == FindParent(y))
				{
					temperature = map[num].d;
					break;
				}
			}
		}
		
		//for (int i = 1; i <= N; i++)
		//{
		//	cout << Parent[i] << " ";

		//}
		//cout << "\n";
		int resultParent = FindParent(x);
		for (int i = 1; i <= N; i++)
		{
			if (resultParent == Parent[i])
			{
				cnt += 1;
			}
		}
		
		if (temperature == 0)
		{
			cout << -1 << "\n";
		}
		else
		{
			cout << temperature << " " << cnt << "\n";
		}

	}
	
}