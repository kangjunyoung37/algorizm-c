#include<iostream>
#include<vector>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int brown = 24, yellow = 24;
	vector<int>answer;
	int a;
	for (int i = 1; i <= yellow; i++)
	{
		
		if (yellow % i == 0)
		{
			//a 는 가로
			//갈색은 2(a + 2) + (i * 2);
			a = yellow / i;
			if (brown == 2 * (a + 2) + (i * 2))
			{
				answer.push_back(a+2);
				answer.push_back(i+2);
				break;
			}
		}
	}
	cout << answer[0] << " " << answer[1];
}