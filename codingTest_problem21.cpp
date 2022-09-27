#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	vector<string> phone_book;
	map<string, bool> m;
	sort(phone_book.begin(), phone_book.end());
	for (int i = 0; i < phone_book.size(); i++)
	{
		string phone_number = phone_book[i];
		for (int j = 1; j <= phone_number.length(); j++)
		{
			
			if (m[phone_number.substr(0,j)])
			{
				return false;
			}
		}
		m[phone_number] = true;
		
	}
	return true;

}