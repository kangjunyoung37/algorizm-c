#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(const string& a, const string& b)
{
	string headA = "", headB = "", NumA = "", NumB = "";
	bool isgo = false;
	for (int i = 0; i < a.length();i++)
	{
		if (a[i] >= 48 && a[i] <= 57)
		{
			isgo = true;
			NumA += a[i];
		}
		else if (isgo)
		{
			break;
		}
		if (!isgo)
		{
			headA += a[i];
		}
	}
	isgo = false;
	for (int i = 0; i < b.length();i++)
	{
		if (b[i] >= 48 && b[i] <= 57)
		{
			isgo = true;
			NumB += b[i];
		}
		else if (isgo)
		{
			break;
		}
		if (!isgo)
		{
			headB += b[i];
		}
	}
	transform(headA.begin(), headA.end(), headA.begin(), ::tolower);
	transform(headB.begin(), headB.end(), headB.begin(), ::tolower);

	if (headA == headB)
	{
		return stoi(NumA) < stoi(NumB);

	}
	return headA < headB;
}
vector<string> solution(vector<string> files) {
	vector<string> answer;
	stable_sort(files.begin(), files.end(), comp);

	answer = files;
	return answer;
}