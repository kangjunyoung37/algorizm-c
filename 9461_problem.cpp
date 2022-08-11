#include<iostream>
#include<queue>
using namespace std;
long long d[101];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	d[1] = d[2] = d[3] = 1;
	d[4] = d[5] = 2;
	queue<int> map;
	map.push(3);
	map.push(2);
	map.push(1);
	map.push(4);
	map.push(5);
	for (int i = 6; i < 101;i++)
	{
		int a = map.front();
		map.pop();
		d[i] = d[i - 1] + d[a];
		map.push(i);
	}
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		cout << d[a] << "\n";
	}
	

	
}