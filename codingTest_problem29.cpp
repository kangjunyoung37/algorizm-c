#include<iostream>
#include<vector>
#include<map>

using namespace std;

int dx[8] = {-1,-1,0,1,1,1,0,-1};
int dy[8] = {0,1,1,1,0,-1,-1,-1};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int answer = 0;
	vector<int> arrows = { 6, 6, 6, 4, 4, 4, 2, 2, 2, 0, 0, 0, 1, 6, 5, 5, 3, 6, 0 };
	
	map<pair<int, int>, bool> graph;
	map < pair<pair<int, int>, pair<int, int>>, bool> edge;
	int x = 0;
	int y = 0;

	graph[{x, y}] = true;
	
	for (int i = 0; i < arrows.size(); i++)
	{
		
		for (int j = 0; j < 2; j++)
		{
			int cdx = x + dx[arrows[i]];
			int cdy = y + dy[arrows[i]];

			if (graph[{cdx,cdy}] == true && edge[{{x,y},{cdx,cdy}}] == false)
			{
				edge[{ {x, y}, { cdx,cdy }}] = true;
				edge[{ {cdx, cdy}, { x,y }}] = true;
				answer++;
				x = cdx;
				y = cdy;
				continue;
			}
			graph[{cdx, cdy}] = true;
			edge[{ {x, y}, { cdx,cdy }}] = true;
			edge[{ {cdx, cdy}, { x,y }}] = true;
			x = cdx;
			y = cdy;
		}
		
	}
	cout << answer;

}