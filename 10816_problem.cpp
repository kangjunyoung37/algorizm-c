#include<iostream>
#include<algorithm>
#define MAX_N 500002

using namespace std;

int card[MAX_N];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		
		cin >> card[i];
	}
	sort(card, card+N);
	int M;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int x;
		cin >> x;
		cout << upper_bound(card, card + N, x) - lower_bound(card, card + N, x) << " ";

	}
}
