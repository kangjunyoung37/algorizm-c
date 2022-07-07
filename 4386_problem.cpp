#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>

#define MAX_S 10000
using namespace std;

int group[MAX_S];
int N;


int Find(int start)
{
	if (group[start] == start)
		return start;
	return group[start] = Find(group[start]);
}
void Union_(int a, int b)
{
	a = Find(a);
	b = Find(b);
	if (a == b)
		return;
	group[b] = a;
}
int main()
{
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	double result = 0.0;
	vector<pair<double, double>> map;
	int N;
	cin >> N;
	vector<vector<double>> stars;
	for (int i = 0; i < N; i++)
	{
		double x, y;
		cin >> x >> y;
		map.push_back(make_pair(x, y));
		group[i] = i;
	}
	vector<double> exam(3, 0);
	for (int i = 0; i < N; i++)
	{
		for (int j = i +1; j < N; j++)
		{
		
			double x1 = map[i].first;
			double y1 = map[i].second;
			
			double x2 = map[j].first;
			double y2 = map[j].second;

			exam[0] = round(sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)) * 100) / 100;
			exam[1] = i;
			exam[2] = j;

			stars.push_back(exam);
		}
	}
	sort(stars.begin(), stars.end());

	//for (int i = 0; i < N; i++)
	//{


	//	cout << stars[i][0] << stars[i][1] << stars[i][2] << " ";
	//	
	//	cout << "\n";
	//}
	for (int i = 0; i < stars.size(); i++)
	{
		int a = Find(stars[i][1]);
		int b = Find(stars[i][2]);
		if (a == b)
		{
			continue;
		}
		Union_(a, b);
		result += stars[i][0];

	}

	cout << result;
}