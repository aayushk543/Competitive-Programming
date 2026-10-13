#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    priority_queue<pair<int, int>> pq;

    for(int i = 1; i <= q; i++) {
        char op;
        int u, v;

        cin >> op >> u >> v;

        if(op == '+') {
            pq.push({u, 1});
            pq.push({v, -1});
        }
        else {
            pq.push({u, -1});
            pq.push({v, 1});
        }
    }

    int count = 0;

    bool flag = true;

    while(!pq.empty()) {
        auto [x, sign] = pq.top();

        if(sign == 1) count++;
        else if(sign == -1) count--;

        if(count > 1) {
            flag = false;
            break;
        }
    }

    if(flag) cout << "YES" << '\n';
    else cout << "NO" << '\n';

    return 0;
}