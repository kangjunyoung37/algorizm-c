#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

vector<string> solution(vector<string> record) {
	vector<string> answer;
	map<string, string> map;
	vector<pair<string, string>> result;
	pair<string, string> pair;
	for (int i = 0; i < record.size();i++) //아이디 닉네임 설정
	{
		istringstream ss(record[i]);
		string str;
		getline(ss, str, ' ');
		pair.first = str;
		getline(ss, str, ' ');
		pair.second = str;
		result.push_back(pair);
		if (pair.first == "Leave")
			continue;
		getline(ss, str, ' ');
		map[pair.second] = str;
	}

	for (int i = 0; i < result.size(); i++)
	{
		string temp = "";
		if (result[i].first == "Change")
		{
			continue;
		}
		temp += map[result[i].second] + "님이";
		if (result[i].first == "Enter")
		{
			temp += " 들어왔습니다.";
		}
		else
		{
			temp += " 나갔습니다.";
		}
		answer.push_back(temp);
	}
	return answer;
}