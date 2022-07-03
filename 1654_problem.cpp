#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> lan;
long long ans = 0;
void Find(long long FindNum)
{
	long long start = 0;
	long long end = lan.at(lan.size()-1);
	long long cut;
	long long temp;
	
	while (start <= end)
	{
		cut = start + (end - start) / 2;
		if (cut == 0) cut = 1;
		long long result = 0;
		for (int i = 0; i < lan.size(); i++)
		{
			result += lan[i] / cut;
		}


		if (result >= FindNum)
		{
			start = cut + 1;
			ans = max(ans, cut);
		}
		else if (result < FindNum)
		{
			 end = cut -1 ;
		}

	}

}



int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int K;
	long long N;
	cin >> K >> N;
	

	for (int i = 0; i < K; i++)
	{
		long long len;
		cin >> len;
		lan.push_back(len);
	} 
	
	sort(lan.begin(), lan.end());
	Find(N);
	cout << ans;
	
}