#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	

	int N;
	cin >> N;
	vector<int> arr;
	vector<int> d(N,0);

	for (int i = 0;i < N; i++)
	{
		int a;
		cin >> a;
		arr.push_back(a);
	}
	d[0] = arr[0];
	for (int i = 1; i < N; i++)
	{
		int temp;
		if (d[i - 1] < 0)
		{
			temp = 0;
		}
		else
		{
			temp = d[i - 1];
		}

		d[i] = temp +arr[i];

	}
	int result = *max_element(d.begin(), d.end());
	cout << result;

}