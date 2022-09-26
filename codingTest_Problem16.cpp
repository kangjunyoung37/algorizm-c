#include <iostream>
#include <string>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	

	int answer = 0;
	string name = "JAN";
	string temp = "";
	int n = name.length();
	int turn = n -1;
	for (int i = 0; i < n; i++)
	{
		if (name[i] - 'A' < 14)
			answer += name[i] - 'A';
		else
		{
			answer += 'Z' - name[i] + 1;
		}
		int ind = i + 1;
		while (ind < n && name[ind] == 'A') ind++;

		turn = min(turn, i + n - ind + min(i, n - ind));
		
	}
	answer += turn;
	return answer;
}