#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	int N;
	cin >> N;

	priority_queue<int> map;
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		map.push( -a);
	}
	int ans = 0;
	while (map.size() > 1)
	{
		int sum = 0;
		sum += map.top();
		map.pop();
		sum += map.top();
		map.pop();
		ans += sum;
		map.push(sum);
	}
	cout << -ans; 
	

}