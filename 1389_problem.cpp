#include<iostream>
#include<algorithm>
#define MAX_V 102
#define INF  987654321

using namespace std;

int graph[MAX_V][MAX_V];
int node;
void floyd() {

	for (int m = 1; m <= node; m++)
	{
		for (int i = 1; i <= node; i++)
		{
			for (int j = 1; j <= node; j++)
			{

				graph[i][j] = min(graph[i][j], graph[i][m] + graph[m][j]);
			}
		}
	}

}
int main(){

	int  edge;
	cin >> node >> edge;

	for (int i = 1; i <= node; i++)
	{
		for (int j = 1; j <= node; j++)
		{
			if (i == j)
			{
				graph[i][j] == 0;
				continue;
			}
			graph[i][j] = INF;
		}
	}
	for (int i = 0; i < edge; i++)
	{
		int x, y;

		cin >> x >> y;

		graph[x][y] = 1;
		graph[y][x] = 1;
	}
	floyd();
	int idx = -2;
	int minimum = INF;
	for (int i = 1; i <= node; i++)
	{
		int num = 0;
		for (int j = 1; j <= node; j++)
		{
			num += graph[i][j];
		}
		if (num < minimum)
		{
			minimum = num;
			idx = i;
		}
	}

	cout << idx;


}
