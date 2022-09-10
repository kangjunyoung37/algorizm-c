#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int T, n, m;
int A[1001],B[1001],sum = 0;
vector<int> mapA;
vector<int> mapB;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> T;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	for (int i = 0; i < n; i++)
	{
		sum = A[i];
		mapA.push_back(sum);
		for (int j = i + 1; j < n; j++)
		{
			sum += A[j];
			mapA.push_back(sum);
		}
	}

	cin >> m;
	for (int i = 0;i < m; i++)
	{
		cin >> B[i];
	}
	for (int i = 0; i < m; i++)
	{
		sum = B[i];
		mapB.push_back(sum);
		for (int j = i + 1; j < m; j++)
		{
			sum += B[j];
			mapB.push_back(sum);
		}
	}
	sort(mapB.begin(), mapB.end());

	long long result = 0;
	for (int i = 0; i < mapA.size(); i++)
	{
		int temp = T - mapA[i];

		auto lower = lower_bound(mapB.begin(), mapB.end(), temp);
		auto upper = upper_bound(mapB.begin(), mapB.end(), temp);

		result += (upper - lower);
	}
	cout << result;

}