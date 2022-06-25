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
		int index = Beg + (End - Beg) / 2;//반에서 큰지 작은지 확인

		if (FindNum > v1.at(index))//크면 시작점을 index값으로
		{
			Beg = index;
		}
		else if (FindNum < v1.at(index))//작으면 끝점을 index값으로
		{
			End = index;

		}

		else//else면 반환해줌
		{
			return 1;
		}

	}
	if (v1.at(End) == FindNum || v1.at(Beg) == FindNum)//만약에 시작점이랑 같던가 끝점과 같다면 1을 반환
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
		scanf("%d", &num);//cin  cout 보다 scanf printf가 시간이 더 빠름
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