#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	vector<vector<int>> triangle;
	triangle.push_back({7});
	triangle.push_back({3,8});
	triangle.push_back({8,1,0});
	triangle.push_back({2,7,4,4});
	triangle.push_back({4,5,2,6,5});
	for (int i = 1; i < triangle.size(); i++)
	{
		for (int j = 0; j < triangle[i].size(); j++)
		{
			if (j == 0)
			{
				triangle[i][j] += triangle[i - 1][j];
			}
			else if (j == triangle[i].size() - 1)
			{
				triangle[i][j] += triangle[i - 1][j-1];
			}
			else
			{
				triangle[i][j] += max(triangle[i - 1][j - 1], triangle[i - 1][j]);
			}
		}
	}

	int answer = *max_element(triangle[triangle.size() - 1].begin(), triangle[triangle.size() - 1].end());
	cout << answer;

}