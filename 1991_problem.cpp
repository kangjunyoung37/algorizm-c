#include<iostream>
using namespace std;


int Alpa[27][2];
string answer = "";
void prefunc(int Start)
{
	answer += (Start + 64);
	if (Alpa[Start][0] != 0)
	{
		prefunc(Alpa[Start][0]);
	}
	if (Alpa[Start][1] != 0)
	{
		prefunc(Alpa[Start][1]);
	}
	
}
void middlefunc(int Start)
{
	if (Alpa[Start][0] != 0)
	{
		middlefunc(Alpa[Start][0]);
	}
	answer += (Start + 64);

	if (Alpa[Start][1] != 0)
	{
		middlefunc(Alpa[Start][1]);
	}
}

void laterfunc(int Start)
{
	if (Alpa[Start][0] != 0)
	{
		laterfunc(Alpa[Start][0]);
	}
	if (Alpa[Start][1] != 0)
	{
		laterfunc(Alpa[Start][1]);
	}
	answer += (Start + 64);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		char root, left, right;
		cin >> root >> left >> right;
		if (left != '.')
		{
			Alpa[root - 64][0] = left - 64;
		}
		if (right != '.')
		{
			Alpa[root - 64][1] = right - 64;
		}
		
	}
	prefunc(1);
	cout << answer << "\n";
	answer = "";
	middlefunc(1);
	cout << answer << "\n";
	answer = "";
	laterfunc(1);
	cout << answer << "\n";
}