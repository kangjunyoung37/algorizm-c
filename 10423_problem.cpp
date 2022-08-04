#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;

int M, N, K;

int Parent[1001];
vector<tuple<int, int, int>> map;
int FindParent(int son)
{
	if (Parent[son] == son || Parent[son] == -1)
	{
		return Parent[son];
	}
	return Parent[son] = FindParent(Parent[son]);
} 

bool Union_(int a, int b)
{
	int aa = FindParent(a);
	int bb = FindParent(b);
	if (aa == bb)
	{
		return false;
	}
	if (aa == -1)
	{
		Parent[bb] = aa;
	}
	else if (bb == -1)
	{
		Parent[aa] = bb;
	}
	else
	{
		Parent[bb] = a;
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> M >> N >> K;
	int result = 0;
	for (int i = 0; i <= M; i++)
	{
		Parent[i] = i;
	}
	for (int i = 0; i < K; i++)
	{
		int a;
		cin >> a;
		Parent[a] = -1;
	}
	
	for (int i = 0; i < N; i++)
	{
		int x, y, d;
		cin >> x >> y >> d;
		map.push_back({ d,x,y });
	}
	sort(map.begin(), map.end());

	for (int i = 0; i < map.size(); i++)
	{
		int d = get<0>(map[i]);
		int x = get<1>(map[i]);
		int y = get<2>(map[i]);

		if (Union_(x, y))
		{
			
			result += d;
		}

	}
	cout << result;

}