#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;

    vector<string> mem;
    if (cacheSize == 0)
    {
        return cities.size() * 5;
    }
    for (int i = 0; i < cities.size(); i++)
    {
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::toupper);
    }
    for (int i = 0; i < cities.size();i++)
    {
        bool isgo = false;
        int hitindex = -1;
        for (int j = 0; j < mem.size(); j++)
        {
            if (cities[i] == mem[j])
            {
                isgo = true;
                hitindex = j;
                break;
            }
        }
        if (isgo)
        {
            answer += 1;
            mem.erase(mem.begin() + hitindex);
        }
        else
        {
            answer += 5;
            if (mem.size() == cacheSize)
            {
                mem.erase(mem.begin());
            }
        }
        mem.push_back(cities[i]);
    }
    return answer;
}