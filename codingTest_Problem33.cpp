#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    //�⺻ ī�޶� 1��
    int answer = 1;
    //���� ����Ʈ ����
    sort(routes.begin(), routes.end());
    //�񱳸� ���� ó������ ������ �κ� üũ
    int temp = routes[0][1];
    //����Ʈ ��ȸ�ϱ�
    for (auto a : routes) {
        //���� ���� ������ �κк��� �ڿ� ���� ���´ٸ�
        if (temp < a[0]) {
            //ī�޶� ��ġ
            answer++;
            //������ �κ� ����
            temp = a[1];
        }
        //���� ������ ������ ���������� 
        if (temp >= a[1])    temp = a[1];// ������ �κ��� ������ ����
    }
    return answer;
}
