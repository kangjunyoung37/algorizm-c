#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int N, M;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    vector<pair<int, int>> v[N + 2];
    vector<bool> isVisited(N + 1, false);
    int A, B, C;
    int MAX = 0;
    int from, to;

    for (int i = 0; i < M; i++) {
        cin >> A >> B >> C;
        v[A].emplace_back(B, C);
        v[B].emplace_back(A, C);
        MAX = max(MAX, C);
    }
    cin >> from >> to;

    int left = 0;
    int right = MAX;

    while (left <= right) {
        int mid = (left + right) / 2; // 수송 가능한 최소값

        queue<int> q;
        fill(isVisited.begin(), isVisited.end(), false);
        //vector<bool> isVisited(N+1, false);
        q.push(from);
        isVisited[from] = true;
        bool isTrue = false;

        while (!q.empty()) {
            int now = q.front();
            q.pop();
            //isVisited[now]=true;

            if (now == to) {
                isTrue = true;
                break;
            }

            for (int i = 0; i < v[now].size(); i++) {
                int next = v[now][i].first;
                int cost = v[now][i].second;

                if (isVisited[next] || cost < mid) continue;
                // 방문한 적 있거나 최소 값도 못옮기면 skip
                isVisited[next] = true;
                q.push(next);
            }
        }

        if (isTrue) left = mid + 1;
        else right = mid - 1;
    }


    cout << right;
}
