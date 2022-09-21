#include<iostream>
#include<vector>
#include<set>
using namespace std;

int getNum(int N, int idx)
{
	int M = N;
	for (int i = 0; i < idx; i++)
	{
		M = M * 10 + N;
	}
	return M;
}
int main()
{
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int N, number;
	cin >> N >> number;
	int answer = 0;
	vector<set<int>> d(8);
	if (number == N)
	{
		return 1;
	}
	d[0].insert(N);
	for(int k = 1; k < 8; k++)
	{
		d[k].insert(getNum(N, k));
		for (int i = 0; i < k; i++)
		{
			for (int j = 0; j < k; j++)
			{
				if (i + j + 1 != k)
				{
					continue;
				}
				for (int a : d[i])
				{
					for (int b : d[j])
					{
						d[k].insert(a + b);
						d[k].insert(a * b);
						if (a - b >= 1)
						{
							d[k].insert(a - b);
						}
						if (a / b >= 1)
						{
							d[k].insert(a / b);
						}
					}
				}
			}
		}
		if (d[k].find(number) != d[k].end()) return  k + 1;

	}
	return -1;



}