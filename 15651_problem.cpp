#include<iostream>

using namespace std;

int N, M;
int result[10] = { 0, };


void func(int x) {

	if (x == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << result[i] << " ";

		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; i++)
	{
		result[x] = i;
		func(x + 1);
	}
	

}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;

	func(0);
	


}