#include <string>
#include <vector>

using namespace std;

vector<int> solution(string msg) {

	string temp, current = "";
	vector<string> arr;
	vector<int> answer;

	for (int i = 65; i <= 90; i++)
	{
		temp = "";
		temp += (char)i;
		arr.push_back(temp);
	}

	int a, num;
	for (int i = 0; i < msg.length();i++)
	{
		a = i;
		current = "";
		num = -1;
		while (a < msg.length())
		{
			current += msg[a];
			bool isgo = false;
			for (int j = 0; j < arr.size(); j++)
			{
				if (current == arr[j])
				{
					isgo = true;
					num = j + 1;
					a++;
					if (num > 26)
					{
						i++;
					}
					break;
				}
			}

			if (!isgo)
			{
				answer.push_back(num);
				arr.push_back(current);
				break;
			}

		}
	}
	answer.push_back(num);

	return answer;
}