#include<iostream>
#include<string>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string number;
	cin >> number;
	int k;
	cin >> k;
	string answer = "";
	int i = 0 , n = 0;
	while (1)
	{
		if (i == number.size() - 1 || n == k)
		{
			break;
		}
		if (number[i] < number[i + 1])
		{
			number.erase(number.begin() + i);
			i = 0;
			n++;
		}
		else
		{
			i++;
		}
	}
	if (n != k)
	{
		for (int i = 0; i < k - n; i++)
		{
			number.erase(number.end() - 1);
		}
	}
	answer = number;
	cout << answer;

}