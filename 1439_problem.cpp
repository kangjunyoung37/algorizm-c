#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	string a;
	cin >> a;

	istringstream ss(a);
	string buff;

	vector<string> zero;
	vector<string> one;
	while (getline(ss, buff, '1'))
	{
		if (buff.empty())
		{
			continue;
		}
		zero.push_back(buff);
	}

	istringstream qq(a);
	while (getline(qq, buff, '0'))
	{
		if (buff.empty())
		{
			continue;
		}
		one.push_back(buff);
	}
	if (zero.size() < one.size())
	{
		cout << zero.size();
	}
	else
	{
		cout << one.size();
	}
}