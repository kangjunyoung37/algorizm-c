#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

    long long solution(int n, vector<int> times) {
        long long answer = 0;
      
        long long min_time = 1;
  
        long long max_time = (long long)*min_element(times.begin(), times.end()) * n;
    
        long long mid_time;
        long long sum_n;

        while (min_time <= max_time) {
            mid_time = (min_time + max_time) / 2;
            sum_n = 0;
            for (int i = 0; i < times.size(); ++i) 
                sum_n += mid_time / times[i];
            if (sum_n >= n) { 
                max_time = mid_time - 1; 
                answer = mid_time;
              
            }
            else 
                min_time = mid_time + 1; 
        }

       
        return answer;
    }


