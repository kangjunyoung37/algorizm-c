#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<long long> tree;
//#이분탐색
long long  Find(long long FindNum)
{
	long long End = tree.at(tree.size() - 1);
	long long Beg = 0;
	long long cut;
	long long temp;
	while (Beg <= End)
	{
	    cut = Beg + (End - Beg) / 2;//절단하는 높이
		long long result = 0;
		for (int i = 0; i < tree.size();i++)
		{
			if (tree[i] > cut)
			{
				result += (tree[i] - cut); //자르고 남은 나무길이의 함
			}
		}
		if (result > FindNum) //남은 길이가 찾고 싶은 것보다 크다면 
		{
			temp = cut; //temp값에 절단높이를 넣어두고 절단높이를 높여봄
			Beg = cut + 1;

		}
		else if (result < FindNum)
		{
			
			End = cut - 1;
		}
		else
		{
			return cut;
		}		
	}

	return temp;
}
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	long long m, n;
	cin >> m >> n;
	for (int i = 0; i < m; i++)
	{
		long long height;
		cin >> height;
		tree.push_back(height);
	}
	sort(tree.begin(), tree.end());
	cout << Find(n);


}