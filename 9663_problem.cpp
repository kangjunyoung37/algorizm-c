#include<iostream>

using namespace std;
#define MAX_S 16

int col[MAX_S];
int N;
int cnt = 0;
bool check(int level)
{
	for (int i = 0; i < level; i++)
	{
		if (col[i] == col[level] || abs(col[level] - col[i]) == level - i)
			return false;
	}
	return true;
}
void func(int cur) {

	if (cur == N)
		cnt++;
	else
	{
		for (int i = 0; i < N; i++)
		{
			col[cur] = i;
			if (check(cur))
			{
				func(cur + 1);
			}

		}
	}
}
int main() {
	
	cin >> N;
	func(0);
	cout << cnt;


}