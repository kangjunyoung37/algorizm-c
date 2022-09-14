#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(string dartResult) {
	int answer = 0;
	int num[3], pos = 0;

	for (int i = 0; i < dartResult.length();i++)
	{

		if (dartResult[i] == '1' && dartResult[i + 1] == '0')
		{
			num[pos] = 10;
			i++;
			continue;
		}
		if (dartResult[i] > 47 && dartResult[i] < 58)
		{
			num[pos] = dartResult[i] - 48;
			continue;
		}


		if (dartResult[i] == 'S')
		{
			if (dartResult[i + 1] == '#')
			{
				num[pos] *= -1;
			}
			else if (dartResult[i + 1] == '*')
			{
				num[pos] *= 2;
				if (pos != 0)
				{
					num[pos - 1] *= 2;
				}
			}
			pos++;
		}


		else if (dartResult[i] == 'D')
		{
			num[pos] = pow(num[pos], 2);

			if (dartResult[i + 1] == '#')
			{
				num[pos] *= -1;
			}
			else if (dartResult[i + 1] == '*')
			{
				num[pos] *= 2;
				if (pos != 0)
				{
					num[pos - 1] *= 2;
				}
			}
			pos++;
		}

		else if (dartResult[i] == 'T')
		{
			num[pos] = pow(num[pos], 3);
			if (dartResult[i + 1] == '#')
			{
				num[pos] *= -1;
			}
			else if (dartResult[i + 1] == '*')
			{
				num[pos] *= 2;
				if (pos != 0)
				{
					num[pos - 1] *= 2;
				}
			}
			pos++;
		}



	}

	for (int i = 0; i < 3;i++)
	{
		answer += num[i];
	}
	return answer;

}