#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N;
long long ans = 0;
vector<long long> v[5];

vector<long long> ab;
vector<long long> cd;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		long long a, b, c, d;
		cin >> a >> b >> c >> d;
		v[1].push_back(a);
		v[2].push_back(b);
		v[3].push_back(c);
		v[4].push_back(d);
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			ab.push_back(v[1][i] + v[2][j]);
			cd.push_back(v[3][i] + v[4][j]);
		}
	}
	sort(ab.begin(), ab.end());
	sort(cd.begin(), cd.end());
	long long start = 0, end = cd.size()-1;
	
	while (start < ab.size() && end >= 0)
	{
		if (ab[start] + cd[end] > 0)
		{
			end--;
		}
		else if (ab[start] + cd[end] < 0)
		{
			start++;
		}
		else
		{
			long long a = 1, b = 1;
			while (start != ab.size() - 1 && ab[start + 1] == ab[start])
			{
				start++;
				a++;
			}
			while (end != 0 && cd[end -1] == cd[end])
			{
				end--;
				b++;
			}
			start++;
			ans += (a * b);
		}


	}
	cout << ans;
}