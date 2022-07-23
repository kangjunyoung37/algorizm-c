#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int arr[1001] = { 0 ,};
int d[1001] = { 0 ,};
int A[1001];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;

	fill(&A[1], &A[1001], 2000);
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}
	for (int i = 1;i <= N; i++)
	{
		for (int j = 0; j <= (sizeof(A)/sizeof(int)); j++)
		{
			if (arr[i] <= A[j])
			{
				d[i] = j;
				A[j] = min(arr[i], A[j]);
				break;
			}

		}
	}
	int result = 0;
	for (int i = 1; i <= N; i++)
	{
		if (result < d[i]) {
			result = d[i];
		}
	}
	cout << result;

	
}