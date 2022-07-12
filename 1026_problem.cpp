#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> A;
vector<int> B;
 
int sum = 0;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		A.push_back(a);
	}
	for (int i = 0; i < N; i++)
	{
		int b;
		cin >> b;
		B.push_back(b);
		
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), greater<>());//내림차순
	for (int i = 0; i < N; i++)
	{
		//cout << A[i] << " " << B[i];
		sum += (A[i] * B[i]);
		//cout << "\n";
	}

	cout << sum;

}