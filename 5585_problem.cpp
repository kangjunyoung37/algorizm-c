#include<iostream>

using namespace std;

int moneys[6] = { 500,100,50,10,5,1 };

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int money;
	cin >> money;
	int count = 1000 - money;
	int result = 0;

	for (int i = 0; i < 6; i++)
	{
		result += (count / moneys[i]);
		count = count % moneys[i];
	}
	cout << result;
	

}