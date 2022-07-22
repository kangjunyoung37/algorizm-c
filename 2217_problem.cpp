#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool Cmp(const int& a, const int& b) {
	return a > b;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	int result = 0;
	vector<int> weight;
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		weight.push_back(a);
	}
	sort(weight.begin(), weight.end(),Cmp);
	for (int i = 0; i < N; i++)
	{
		result = max(result, weight[i] * (i + 1));
	}
	cout << result;
}