#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string A;
	cin >> A;
	vector<int> num;
	vector<char> calculate;
	string  B = "";
	bool isgo = false;
	for (int i = 0; i < A.size();i++)
	{
		
		if (A[i] == '-' || A[i] == '+')
		{
			num.push_back(stoi(B));
			calculate.push_back(A[i]);
			B.clear();
			continue;
		}
		B += A[i];
	}
	num.push_back(stoi(B));
	// 출력해보기
	/*for (int i = 0; i < num.size(); i++)
	{
		cout << num[i] << " ";
	}

	for (int i = 0; i < calculate.size();i++)
	{
		cout << calculate[i] << " ";
	}*/

	int sum = num[0];
	int last = 1;

	for (int i = 1; i < num.size();i++)
	{
		if (calculate[i - 1] == '-' || isgo)
		{
			sum -= num[i];
			isgo = true;
		}
		else
		{
			sum += num[i];
		}
	}

	cout << sum;

}