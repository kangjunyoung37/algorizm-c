#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> v1;


int Find(int FindNum)
{	
	int End = v1.size() - 1;
	int Beg = 0;
	while (End - Beg > 1)
	{
		int index = Beg + (End - Beg) / 2;//�ݿ��� ū�� ������ Ȯ��

		if (FindNum > v1.at(index))//ũ�� �������� index������
		{
			Beg = index;
		}
		else if (FindNum < v1.at(index))//������ ������ index������
		{
			End = index;

		}

		else//else�� ��ȯ����
		{
			return 1;
		}

	}
	if (v1.at(End) == FindNum || v1.at(Beg) == FindNum)//���࿡ �������̶� ������ ������ ���ٸ� 1�� ��ȯ
	{
		return 1;
	}

	return 0;
	

}


int main() {

	int count;
	cin >> count;
	
	for (int i = 0; i < count; i++)
	{
		int num;
		scanf("%d", &num);//cin  cout ���� scanf printf�� �ð��� �� ����
		v1.push_back(num);
	}

	sort(v1.begin(), v1.end());

	int count1;
	cin >> count1;
	for (int i = 0; i < count1; i++)
	{
		int num;
		scanf("%d", &num);
		printf("%d\n", Find(num));

	}

}