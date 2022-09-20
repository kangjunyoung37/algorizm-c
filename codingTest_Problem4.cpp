#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	vector<int> arr;
	vector<int>temp;
	vector<vector<int>> commands;
	arr.push_back(1);
	arr.push_back(5);
	arr.push_back(2);
	arr.push_back(6);
	arr.push_back(3);
	arr.push_back(7);
	arr.push_back(4);
	int Start, End;
	for (int i = 0; i < 3;i++)
	{
		vector<int> a;
		int b;
		
		for (int j = 0; j < 3; j++)
		{
			cin >> b;
			a.push_back(b);
		}
		commands.push_back(a);

	}
	for (int i = 0; i < commands.size();i++)
	{
		temp.clear();
		temp = arr;
		Start = commands[i][0] - 1;
		End = commands[i][1];
		sort(temp.begin() + Start, temp.begin() + End);
		for (int j = 0; j < temp.size(); j++)
		{
			cout << temp[j] << " ";
		}
		cout << "\n";
		cout << temp[Start + (commands[i][2] - 1)];
	}


}

