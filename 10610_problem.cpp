#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

string N;
int comp(const int& a, const int& b)
{
	return a > b;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	bool isgo = false;
	vector<int> num;
	int sum = 0;
	cin >> N;

	for (int i = 0; i < N.length(); i++)
	{
		if ((int)N[i] - 48 == 0)
		{
			isgo = true;
		}
		sum += ((int)N[i] - 48);
		
		num.push_back((int)N[i] - 48);
	}
	if (isgo == false || sum % 3 != 0)
	{
		cout << -1;
		return 0;
	}
	else
	{
		sort(num.begin(), num.end(),comp);
		
		for (int i = 0; i < num.size();i++)
		{
			cout << num[i];
		}
		
	}


}