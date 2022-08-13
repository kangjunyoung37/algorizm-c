#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M;
vector<int> arr;
int result[10];
int visited[10];
void func(int x )
{
	if (x == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << result[i] << " ";
		}
		cout << "\n";
	}
	for (int i = 0; i < N; i++)
	{
		if (visited[i])
		{
			continue;
		}
		result[x] = arr[i];
		visited[i] = true;
		func(x + 1);
		visited[i] = false;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;


	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		arr.push_back(a);
		visited[i] = false;
	}
	sort(arr.begin(), arr.end());
	func(0);

}