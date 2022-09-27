#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int distance, vector<int> rocks, int n) {
	int low, high;
	int answer = 0;
	low = 0;
	high = distance;

	rocks.push_back(0);
	rocks.push_back(distance);
	sort(rocks.begin(), rocks.end());
	while (low + 1 < high)
	{
		int mid = (low + high) / 2;

		int prev = 0, cnt = 0;
		for (int i = 1; i < rocks.size(); i++)
		{
			if (rocks[i] - rocks[prev] < mid) cnt++;
			else
			{
				prev = i;
			}
		}
		if (cnt > n)
		{
			high = mid;
		}
		else
		{
			low = mid;
		}

	}
	return low;

}