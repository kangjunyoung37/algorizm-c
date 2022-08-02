#include<iostream>
#include<vector>
using namespace std;

int arr[21];
int N, S;
int cnt = 0;
int result[21];

void func(int start, int x)
{
	if (x > 0)
	{
		int temp = 0;
		for (int i = 0; i < x; i++)
		{
			temp += result[i];
		}
		if (temp == S)
		{
			cnt += 1;
		}
		
	}

	for (int i = start; i < N; i++)
	{
		result[x] = arr[i];
		func(i + 1, x + 1);
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);


	cin >> N >> S;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	func(0, 0);
	cout << cnt;
}