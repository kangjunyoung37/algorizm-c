#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, M;
vector<int> map;
int result[10];
void func(int start, int X)
{
	if (X == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << result[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = start; i < N; i++)
	{
		result[X] = map[i];
		func(i, X + 1);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		map.push_back(a);
	}
	sort(map.begin(), map.end());
	func(0, 0);

}