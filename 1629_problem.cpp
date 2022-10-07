#include<iostream>
using namespace std;

long long Pow(long long a, long long b, long long c)
{
	if (b == 0) return 1;
	long long temp = Pow(a, b / 2, c);
	temp = temp * temp % c;
	if (b % 2 == 0) return temp;
	else return temp * a % c;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	long long a, b, c;
	cin >> a >> b >> c;
	cout << Pow(a, b, c);

}