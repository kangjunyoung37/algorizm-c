#include <string>
#include <vector>
#include <cmath>

using namespace std;



bool check(long long a)
{
	for (long long i = 2; i <= sqrt(a); i++)
	{
		if (a % i == 0)
		{
			return false;
		}
	}
	return true;
}

int solution(int n, int k) {
	int answer = 0;
	int a;
	string temp = "";
	vector<long long> number;

	while (1)
	{
		a = n % k;
		n /= k;
		if (n == 0)
		{
			temp += to_string(a);
			break;
		}

		temp += to_string(a);

	}
	string num = "";
	for (int i = temp.size() - 1; i >= 0; i--)
	{
		if (!num.empty() && temp[i] == '0')
		{
			number.push_back(stol(num));
			num = "";
		}
		if (num.empty() && temp[i] == '0')
		{
			continue;
		}
		num += temp[i];
	}
	if (!num.empty())
	{
		number.push_back(stol(num));
	}

	for (int i = 0; i < number.size(); i++)
	{
		if (number[i] == 1)
		{
			continue;
		}
		if (check(number[i]))
		{
			answer += 1;
		}
	}

	return answer;
}