#include<iostream>
#include<queue>
using namespace std;
//시물레이션 문제

int main() {
	int count;
	cin >> count;
	for (int i = 0; i < count; i++)
	{
		queue<pair<int,int>> q;
		priority_queue<int> pq;
		

		int queuecount , want;
		cin >> queuecount >> want;

		for (int j = 0; j < queuecount; j++)
		{
			int data ;
			cin >> data;
			q.push({j,data});
			pq.push(data);
		}
		int result = 0;
		while (!q.empty())
		{
			int index = q.front().first;
			int value = q.front().second;
			q.pop();
			if (pq.top() == value)
			{
				result++;
				pq.pop();
				if (index == want)
				{
					cout << result << endl;
					break;
				}
			}
			else
			{
				q.push({ index,value });
			}
		}
	}
	

	return 0;

}