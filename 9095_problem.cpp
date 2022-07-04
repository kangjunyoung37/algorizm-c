#include<iostream>

using namespace std;

int d[12] = { 0, };

void func()
{
	for (int i = 4; i < 11; i++)
	{
		d[i] = d[i - 3] + d[i - 2] + d[i - 1];
	}
}
int main()
{
	int Num;
	cin >> Num;

	d[1] = 1;
	d[2] = 2;
	d[3] = 4;	
	func();
	for (int i = 0; i < Num; i++)
	{
		int want;
		cin >> want;
		cout << d[want] << '\n';
	}

}