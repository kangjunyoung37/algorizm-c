#include<iostream>

using namespace std;
int Num[11];
int Operator[4];
int Max = -1000000000;
int Min = 1000000000;
int totalsize;

void dfs(int plus, int minus, int mutiple, int divide, int x, int sum)
{
	if (x == totalsize - 1)
	{
		if (sum > Max)
		{
			Max = sum;
		}
		if (sum < Min)
		{
			Min = sum;
		}
	}
	
	if (plus > 0) dfs(plus - 1, minus, mutiple, divide, x + 1, sum + Num[x + 1]);
	if (minus > 0) dfs(plus, minus-1, mutiple, divide, x + 1, sum - Num[x + 1]);
	if (mutiple > 0) dfs(plus, minus, mutiple-1, divide, x + 1, sum * Num[x + 1]);
	if (divide > 0) dfs(plus, minus, mutiple, divide-1, x + 1, sum / Num[x + 1]);

}
int main()
{
	
	
	cin >> totalsize;
	for (int i = 0; i < totalsize; i++)
	{
		int a;
		cin >> a;
		Num[i] = a;
	}
	for (int i = 0; i < 4; i++)
	{
		int b;
		cin >> b;
		Operator[i] = b;
	}
	dfs(Operator[0], Operator[1], Operator[2], Operator[3], 0, Num[0]);
	
	cout << Max << '\n' << Min;
	
}