#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	vector<int> scoville;
	priority_queue<int,vector<int>, greater<int>> q;
	scoville.push_back(1);
	scoville.push_back(2);
	scoville.push_back(3);
	scoville.push_back(9);
	scoville.push_back(10);
	scoville.push_back(12);

	int num = 0,answer = -1;
	int K;
	cin >> K;
	for (int i = 0; i < scoville.size(); i++)
	{
		q.push(scoville[i]);
	}
	int a, b;
	while (!q.empty())
	{
		a = q.top();
		q.pop();
		if (a >= K)
		{
			answer = num;
			break;
		}
		if (q.empty())
		{
			break;
		}
		b = q.top();
		q.pop();
		q.push(a + (b * 2));
		num += 1;
	}
	cout << answer;

}