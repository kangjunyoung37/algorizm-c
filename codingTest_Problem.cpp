#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	map<string, int> arr;
	for (int i = 0; i < participant.size();i++)
	{
		arr[participant[i]] += 1;
	}
	for (int i = 0; i < completion.size(); i++)
	{
		arr[completion[i]] -= 1;
	}
	for (int i = 0; i < participant.size();i++)
	{
		if (arr[participant[i]] != 0)
		{
			answer += participant[i];
			arr[participant[i]] -= 1;
		}
	}
	return answer;
}