#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // int t;
    // cin >> t;

    if(1) {
        int n;
        cin >> n;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for(int i = 0; i < n; i++) {
            int u,v;
            cin >> u >> v;

            pq.push({u, 1});
            pq.push({v + 1, -1});
        }

        bool flag = true;
        int val = 0;

        while(!pq.empty()) {

            auto [curr, mag] = pq.top();
            pq.pop();

            val += mag;

            if(val > 2) {
                flag = false;
                break;
            }
        }

        

        if(flag) cout << "YES" << '\n';
        else cout << "NO" << '\n';

    }
}