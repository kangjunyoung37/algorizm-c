#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(const int& a, const int& b)
{
    string A = to_string(a);
    string B = to_string(b);

    return A + B > B + A;

}
string solution(vector<int> numbers) {
    string answer = "";
    sort(numbers.begin(), numbers.end(), comp);
    int sum = 0;
    for (int i = 0; i < numbers.size(); i++)
    {
        sum += numbers[i];
        answer += to_string(numbers[i]);
    }
    if (sum == 0)
    {
        return "0";
    }
    return answer;
}