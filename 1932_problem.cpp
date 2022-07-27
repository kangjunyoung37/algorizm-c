#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()

{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	vector<vector<int>> map(N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			int a;
			cin >> a;
			map[i].push_back(a);
		}
	}
	vector<vector<int>> d(N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
		{

			d[i].push_back(0);
		}
	}
	d[0][0] = map[0][0];

	for (int i = 0; i < N-1; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			d[i + 1][j] = max(d[i][j] + map[i + 1][j], d[i+1][j]);
			d[i + 1][j + 1] = max(d[i][j] + map[i + 1][j + 1], d[i+1][j + 1]);

		}
		
	}
	

	//for (int i = 0; i < N; i++)
	//{
	//	for (int j = 0; j < map[i].size();j++)
	//	{
	//		cout << map[i][j] << " ";
	//	}
	//	cout << "\n";
	//} Ãâ·Â
	/*for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < d[i].size();j++)
		{
			cout << d[i][j] << " ";
		}
		cout << "\n";
	} */
	cout << *max_element(d[N - 1].begin(), d[N - 1].end());


}