#include<iostream>
using namespace std;
int room[101];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int Num;
	cin >> Num;
	for (int n = 0; n < Num; n++)
	{
		int N;
		cin >> N;
		fill(&room[0], &room[101], 1);
		for (int i = 2; i <= N; i++)
		{
			for (int j = 1; i * j <= N;j++)
			{
				room[i * j] = -room[i * j];
			}

		}
		int sum = 0;
		for (int i = 1; i <= N; i++)
		{
			if (room[i] == 1)
			{
				sum += 1;
			}
		}
		cout << sum << "\n";
		
	}
}