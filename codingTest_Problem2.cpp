#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	vector<int> arr;
	vector<int>answer;
	stack<int> st;
	for (int i = 0; i < arr.size(); i++)
	{
		if (st.empty())
		{
			st.push(arr[i]);
			answer.push_back(arr[i]);
		}
		if (st.top() == arr[i])
		{
			continue;
		}
		st.push(arr[i]);
		answer.push_back(arr[i]);
	}
	


}