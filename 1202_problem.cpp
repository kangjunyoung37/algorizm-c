#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

vector<pair<long long , long long>> diamond;
vector<long long> bag;

priority_queue<long long> q;
bool comp(const pair<long long, long long>& a, const pair<long long, long long>& b)
{
	if (a.second  == b.second)
	{
		return a.first > b.first;
	}
	
	return a.second < b.second;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(0);cin.tie(0);
	long long N, M;
	cin >> N >> M;
	for (long long i = 0; i < N; i++)
	{
		long long weight, price;
		cin >> weight >> price;
		diamond.push_back({ price,weight });

	}
	for (long long i = 0; i < M; i++)
	{
		long long weight;
		cin >> weight;
		bag.push_back(weight);
	}
	sort(diamond.begin(), diamond.end(),comp);
	sort(bag.begin(), bag.end());
	/*for (int i = 0; i < diamond.size(); i++)
	{
		cout << diamond[i].first << " " << diamond[i].second << "\n";
	}*/
	long long sum = 0;
	long long a = 0;
	for (long long i = 0; i < bag.size(); i++)
	{
		while (a < N && diamond[a].second <= bag[i])
		{
			q.push(diamond[a].first);
			a++;
		}
		if (!q.empty())
		{
			sum += q.top(); 
			q.pop();
		}
				
	}
	cout << sum;


}