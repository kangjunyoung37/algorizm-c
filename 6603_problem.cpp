#include<iostream>

using namespace std;
int N = 1;
int arr[14];
int result[14];
void func(int x,int start) {

	if (x == 6)
	{
		for (int i = 0; i < 6; i++)
		{
			cout << result[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = start; i < N; i++)
	{
		result[x] = arr[i];
		func(x + 1, i + 1);
	}


}
int main()
{
	while (N != 0)
	{
		cin >> N; 
		for (int i = 0; i < N; i++)
		{
			cin >> arr[i];
		}

		//for (int i = 0; i < N; i++)
		//{
		//	cout << arr[i] << " ";
		//} 출력 확인
		// 
		func(0,0);
		cout << "\n";
	}
	
}