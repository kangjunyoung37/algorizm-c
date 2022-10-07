#include<iostream>
using namespace std;

int Min[3];
int Max[3];
int input[3];
int temp0, temp2;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int a;
	cin >> a;
	cin >> input[0] >> input[1] >> input[2];
	for (int i = 0; i < 3; i++)
	{
		Min[i] = input[i];
		Max[i] = input[i];
	}
	for (int i = 1; i < a; i++)
	{
		cin >> input[0] >> input[1] >> input[2];
		temp0 = Max[0]; temp2 = Max[2];
		Max[0] = max(Max[0], Max[1]) + input[0];
		Max[2] = max(Max[1], Max[2]) + input[2];
		Max[1] = max(max(temp0, temp2), Max[1]) + input[1];
		temp0 = Min[0]; temp2 = Min[2];
		Min[0] = min(Min[0], Min[1]) + input[0];
		Min[2] = min(Min[1], Min[2]) + input[2];
		Min[1] = min(min(temp0, temp2), Min[1]) + input[1];
	}
	cout << max(max(Max[0], Max[1]),Max[2]) << " ";
	cout << min(min(Min[0], Min[1]), Min[2]);

}