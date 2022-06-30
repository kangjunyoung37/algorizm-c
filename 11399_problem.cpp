#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define MAX 1002
vector<int> ATM;

int main() {
	int n;
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		ATM.push_back(a);
	}
	sort(ATM.begin(), ATM.end());
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			sum += ATM[j];
		}
	}
	cout << sum;
}