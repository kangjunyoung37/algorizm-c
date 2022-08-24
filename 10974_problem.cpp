#include<iostream>
int result[9];
int visit[9];
using namespace std;
int N;
void func(int x)
{
	if (x == N)
	{
		for (int i = 0; i < N; i++)
		{
			cout << result[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= N; i++)
	{
		if (visit[i])
			continue;
		result[x] = i;
		visit[i] = true;
		func(x + 1);
		visit[i] = false;
	}

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> N;
	func(0);
}