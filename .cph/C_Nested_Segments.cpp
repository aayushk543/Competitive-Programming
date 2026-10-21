#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
       int n;
       cin >> n;

       vector<vector<long long>> vec(n, vector<long long>(2));
       priority_queue<tuple<long long, int, int>> pq;

       for(int i = 0; i < n; i++) {
        cin >> vec[i][0] >> vec[i][1];
        pq.push({vec[i][0], 1, i});
        pq.push({vec[i][1], -1, i});
       }

       sort()

       while(!pq.empty()) {
        auto [bound, val, index] = pq.top();
        pq.pop();

        if(val == 1) {

        }
       }


    }
    return 0;
}