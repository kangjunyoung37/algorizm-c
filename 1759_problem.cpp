#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int L, C;

vector<char> alpa;
char result[16];
int consonant = 0, vowel = 0;
void func(int X, int cnt)
{
	if (X == L)
	{
		consonant = 0; vowel = 0;
		for (int i = 0; i < X; i++)
		{
			
			if (result[i] == 'a' || result[i] == 'e' || result[i] == 'i' || result[i] == 'o' || result[i] == 'u')
			{
				consonant += 1;
			}
			else
			{
				vowel += 1;
			}

		}
		if (consonant >= 1 && vowel >= 2)
		{
			for (int i = 0; i < L; i++)
			{
				cout << result[i];
			}
			cout << "\n";
			return;
			
		}

	}
	for (int i = cnt; i < C; i++)
	{
		result[X] = alpa[i];
		func(X + 1, i + 1);
	}

}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> L >> C;
	for (int i = 0; i < C; i++)
	{
		char a;
		cin >> a;
		alpa.push_back(a);
	}
	sort(alpa.begin(), alpa.end());
	func(0, 0);

}