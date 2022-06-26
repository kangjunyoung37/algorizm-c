#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int node, edge;
	int result = 0;
	cin >> node >> edge;
	int num = 1;
	vector<vector<int>> map(edge, vector<int>(3, 0));
	vector<int> group(node + 1 , 0);

	for (int i = 0; i < edge; i++)
	{
		cin >> map[i][1] >> map[i][2] >> map[i][0];
		
	}
	sort(map.begin(), map.end());

	 
	for (int i = 0; i < edge; i++)
	{
		if (group[map[i][1]] == 0 && group[map[i][2]] == 0)
		{
			group[map[i][1]] = num;
			group[map[i][2]] = num;

			num++;
			result += map[i][0];
		}
		else if (group[map[i][1]] == 0 || group[map[i][2]] == 0)
		{
			if (group[map[i][1]] == 0)
			{
				group[map[i][1]] = group[map[i][2]];
			}
			else if (group[map[i][2]] == 0)
			{
				group[map[i][2]] = group[map[i][1]];
			}
			result += map[i][0];
		}
		else if(group[map[i][1]] != 0 || group[map[i][2]] != 0)
		{
			if (group[map[i][1]] == group[map[i][2]])
			{
				continue;
			}
			int change = group[map[i][2]];
			int target = group[map[i][1]];
			for (int j = 1; j <= node; j++)
			{
				if (group[j] == change)
				{
					group[j] = target;
				}
			}
			result += map[i][0];
		}
	}

	cout <<  result; 

}