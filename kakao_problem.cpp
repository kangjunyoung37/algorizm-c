#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;


    for (int i = 0; i < n; i++)
    {
        int temp = arr1[i] | arr2[i];
        string a = "";
        stack<char> st;
        for (int j = 0; j < n; j++)
        {
            if (temp % 2 == 0)
            {
                st.push(' ');
            }
            else
            {
                st.push('#');
            }
            temp /= 2;
        }
        while (!st.empty())
        {

            a += st.top();
            st.pop();
        }
        answer.push_back(a);


    }
    return answer;
}