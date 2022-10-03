#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> people = { 70, 50, 80 }; int limit = 100;
	int temp = limit;
	int answer = 0;
	int head = 0; int tail = people.size() - 1;
	sort(people.begin(), people.end());
	while (head <= tail)
	{
		if (people[head] + people[tail] <= limit)
		{
			head++;
			tail--;
		}
		else
		{
			tail--;
		}
		answer++;
	}

	//return answer;
}
