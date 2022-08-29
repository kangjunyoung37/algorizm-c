#include<iostream>
#include<vector>
using namespace std;

int N, M;
vector<bool> Switcharr;
int b;
void Switch(int a,int num)
{
	switch (a)
	{
		case 1:
			b = N / num;

			for (int i = 1; i <= b; i++)
			{
				Switcharr[num * i] = !Switcharr[num * i];
			}
		break;
		
		case 2:
			Switcharr[num] = !Switcharr[num];
			if (num == 1 || num == N)
			{
				break;
			}
			int arr1 = num - 1;
			int arr2 = num + 1;
			
			while (Switcharr[arr1] == Switcharr[arr2])
			{
				
				Switcharr[arr1] = !Switcharr[arr1];
				Switcharr[arr2] = !Switcharr[arr2];
				arr1 -= 1;
				arr2 += 1;
				if (arr1 < 1 || arr2 > N)
				{
					break;
				}
			}

		break;
		
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin >> N;
	Switcharr.push_back(0);
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		Switcharr.push_back(a);
	}
	
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		Switch(a, b);

	}
	for (int i = 1; i <= N; i++)
	{

		cout << Switcharr[i] << " ";
		if (i % 20 == 0)
		{
			cout << "\n";
		}
	}
}