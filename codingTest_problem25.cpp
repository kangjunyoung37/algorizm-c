#include<iostream>
#include<vector>
#include<string>
#include<set>

using namespace std;

bool visit[8],visitnum[10000000];
set<int> s;
string temp = "";
vector<int> ex;
int a;
int answer = 0;
void func(int num,int X,string numbers)
{
	if (X == num)
	{
		a = stoi(temp);
		if (visitnum[a])
			return;	
		ex.push_back(a);
		visitnum[a] = true;
		return;
	}
	for (int i = 0; i < numbers.size(); i++)
	{
		if (visit[i])
			continue;
		temp.push_back(numbers[i]);
		visit[i] = true;
		func(num + 1,X, numbers);
		visit[i] = false;
		temp.pop_back();
	}
}
bool check(int num)
{
	if (num <= 1)
	{
		return false;
	}
	for (int i = 2; i < num; i++)
	{
		if (num % i == 0)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string numbers = "17";
	for (int i = 1; i <= numbers.size(); i++)
	{
		func(0,i, numbers);
	}
	for (int i = 0; i < ex.size(); i++)
	{
		if (check(ex[i]))
		{
			answer += 1;
		}
	}
	cout << answer;

	
}