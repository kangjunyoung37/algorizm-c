#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
char map[21][21];
int dx[4] = { 0,1 ,-1 ,0 };
int dy[4] = { 1, 0, 0, -1};
int alpa[26];
int result = 0;
int R, C;

void dfs(int x, int y ,int cnt)
{
	result = max(result, cnt);
	for (int i = 0; i < 4; i++)
	{
		int cdx = x + dx[i];
		int cdy = y + dy[i];

		if (cdx < 0 || cdy < 0 || cdx >= R || cdy >= C)
		{
			continue;
		}
		if (!alpa[map[cdx][cdy] - 65])
		{
			alpa[map[cdx][cdy]-65]++;
			dfs(cdx, cdy, cnt+1);
			alpa[map[cdx][cdy]-65]--;
		}

	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> R >> C;
	for (int i = 0; i < R; i++)
	{
		string A;
		cin >> A;
		for (int j = 0; j < C; j++)
		{
			map[i][j] = A[j];
		}
	}
	/*for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}출력 확인
	*/
	alpa[map[0][0]-65]++;
	dfs(0, 0 ,1);
	cout << result;

}