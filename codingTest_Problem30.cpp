#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	vector<vector<string>> clothes;
	clothes.push_back({ "yellow_hat", "headgear" });
	clothes.push_back({ "blue_sunglasses", "eyewear" });
	clothes.push_back({ "green_turban", "headgear" });
	int answer = 1;
	int sum = 1;
	map<string, int> arr;

	for (int i = 0; i < clothes.size(); i++)
	{
		arr[clothes[i][1]] += 1;	
	}
	for (auto a = arr.begin(); a != arr.end(); a++)
	{
		answer *= a->second + 1;
	}
	answer -= 1;
	cout << answer;

}