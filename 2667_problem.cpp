#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
int graph[25][25];
int sum = 0;

bool DFS(int startX,int startY) {
	if (startX < 0 || startY < 0 || startX > n - 1 || startY > n - 1) return false; // 범위를 벗어나면 false를 리턴
	if (graph[startX][startY] == 1)//만약에 1이라면 방문처리를 해주기
	{
		graph[startX][startY] = 0;//방문처리
		sum += 1;
		//상하좌우가 재귀적으로 호출
		DFS(startX - 1, startY);
		DFS(startX + 1, startY);
		DFS(startX , startY +1);
		DFS(startX , startY -1);

		return true;
	}
	return false;


}


int main()
{
	vector<int> a;
	int result = 0;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%1d", &graph[i][j]);//하나씩 받기 위해서 %1d
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (DFS(i,j))
			{
				result += 1;
				a.push_back(sum);
				sum = 0;
			}
		}
	}
	cout << result << endl;
	sort(a.begin(), a.end());

	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i] << endl;
	}

	return 0;
}