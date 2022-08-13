#include<iostream>
using namespace std;
int cup[4];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	
	int N;
	cin >> N;
	fill(&cup[0], &cup[4], 0);
	cup[1] = 1;
	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		if (cup[a] == 1)
		{
			cup[b] = 1;
			cup[a] = 0;
			continue;
		}
		if (cup[b] == 1)
		{
			cup[b] = 0;
			cup[a] = 1;
			continue;
		}
	}
	for (int i = 1;i < 4;i++)
	{
		if (cup[i] == 1)
		{
			cout << i;
			return 0;
		}
	}
}