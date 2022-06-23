#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
int graph[25][25];
int sum = 0;

bool DFS(int startX,int startY) {
	if (startX < 0 || startY < 0 || startX > n - 1 || startY > n - 1) return false; // ������ ����� false�� ����
	if (graph[startX][startY] == 1)//���࿡ 1�̶�� �湮ó���� ���ֱ�
	{
		graph[startX][startY] = 0;//�湮ó��
		sum += 1;
		//�����¿찡 ��������� ȣ��
		DFS(startX - 1, startY);
		DFS(startX + 1, startY);
		DFS(startX , startY +1);
		DFS(startX , startY -1);

		return true;
	}
	return false;


}


int main()
{
	vector<int> a;
	int result = 0;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%1d", &graph[i][j]);//�ϳ��� �ޱ� ���ؼ� %1d
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (DFS(i,j))
			{
				result += 1;
				a.push_back(sum);
				sum = 0;
			}
		}
	}
	cout << result << endl;
	sort(a.begin(), a.end());

	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i] << endl;
	}

	return 0;
}