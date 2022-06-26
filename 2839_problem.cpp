#include<iostream>

using namespace std;
int main()
{
	int n;
	cin >> n;
	int count = 0;
	while (true) // 5로 계속 빼면서 3 6 9 12가 되면 3으로 계속 빼준다
	{
		if (n == 0)
		{
			break;
		}
		else if (n == 3 || n == 6 || n == 9 || n == 12)
		{
			n -= 3;
			count += 1;
			continue;
		}
		else if (n < 0)
		{
			count = -1;
			break;
		}
		n -= 5;
		count += 1;

	}
	cout << count;

}