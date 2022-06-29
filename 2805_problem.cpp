#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<long long> tree;
//#�̺�Ž��
long long  Find(long long FindNum)
{
	long long End = tree.at(tree.size() - 1);
	long long Beg = 0;
	long long cut;
	long long temp;
	while (Beg <= End)
	{
	    cut = Beg + (End - Beg) / 2;//�����ϴ� ����
		long long result = 0;
		for (int i = 0; i < tree.size();i++)
		{
			if (tree[i] > cut)
			{
				result += (tree[i] - cut); //�ڸ��� ���� ���������� ��
			}
		}
		if (result > FindNum) //���� ���̰� ã�� ���� �ͺ��� ũ�ٸ� 
		{
			temp = cut; //temp���� ���ܳ��̸� �־�ΰ� ���ܳ��̸� ������
			Beg = cut + 1;

		}
		else if (result < FindNum)
		{
			
			End = cut - 1;
		}
		else
		{
			return cut;
		}		
	}

	return temp;
}
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	long long m, n;
	cin >> m >> n;
	for (int i = 0; i < m; i++)
	{
		long long height;
		cin >> height;
		tree.push_back(height);
	}
	sort(tree.begin(), tree.end());
	cout << Find(n);


}