#include <string>
#include <algorithm>

using namespace std;

int solution(string str1, string str2) {
	int answer = 0;
	transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
	transform(str2.begin(), str2.end(), str2.begin(), ::toupper);
	string a = "";
	vector<string> arr1, arr2;

	for (int i = 0; i < str1.length() - 1;i++)
	{
		if (str1[i] < 65 || str1[i] > 90 || str1[i + 1] < 65 || str1[i + 1] > 90)
		{
			continue;
		}
		a += str1[i];
		a += str1[i + 1];
		arr1.push_back(a);
		a = "";
	}
	for (int i = 0; i < str2.length() - 1;i++)
	{
		if (str2[i] < 65 || str2[i] > 90 || str2[i + 1] < 65 || str2[i + 1] > 90)
		{
			continue;
		}
		a += str2[i];
		a += str2[i + 1];
		arr2.push_back(a);
		a = "";
	}
	if (arr1.size() == 0 && arr2.size() == 0)
	{
		return 65536;
	}
	int arr2size = arr2.size();
	//for (int i = 0; i < arr2.size();i++)
	//{
	//	cout << arr2[i] << " ";
	//}
	for (int i = 0; i < arr1.size();i++)
	{
		for (int j = 0; j < arr2.size(); j++)
		{
			if (arr1[i] == arr2[j])
			{
				arr2.erase(arr2.begin() + j);;
				break;
			}
		}
	}
	double result = (float)(arr2size - arr2.size()) / (float)(arr1.size() + arr2.size());
	result *= 65536.0f;
	answer = (int)result;
	//result = round(result);
	//cout << (int)result;

	return answer;
}