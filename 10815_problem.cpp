#include<iostream>
#include<vector>
#include<algorithm>
#define MAX_V 500000
using namespace std;
vector<int> cardlist;
int N, M;
int Start;
int End;
int Find(int FindNum)
{
	Start = 0;
	End = cardlist.size() - 1;

	while (Start <= End)
	{
		int middle = (Start + End) / 2;

		if (cardlist[middle] > FindNum)
		{
			End = middle - 1;
		}
		else if (cardlist[middle] < FindNum)
		{
			Start = middle + 1;
		}
		else if(cardlist[middle] == FindNum)
		{
			return 1;
		}

	}
	return 0;

}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		cardlist.push_back(a);
	}
	cin >> M;
	sort(cardlist.begin(), cardlist.end());
	for (int i = 0; i < M; i++)
	{
		int b;
		cin >> b;
		cout << Find(b) << " ";
	}


}