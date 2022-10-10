#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#define INF 1000000000
using namespace std;

string adventures ="dccccd";
int k = 3;
int alpa[27];
int main()
{
    vector<int> arr = {2,1,3,1,2,2,5,8,7,7};
    int first = arr[0];
    int pre = arr[0];
    int answer = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        if (first > arr[i])
        {
            if (pre >= arr[i])
            {
                answer = 0;
            }
            continue;
        }
        else
        {
            pre = first;
            first = arr[i];
            answer += 1;
        }
    }
    if (first >= arr[arr.size() - 1])
    {
        answer += 1;
    }
    cout <<  answer;
}
	
   
	
		
	

