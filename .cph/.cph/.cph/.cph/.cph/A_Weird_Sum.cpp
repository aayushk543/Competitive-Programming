#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>
#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    unordered_map<int, pair<vector<int>, vector<int>>> mp;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            int curr;
            cin >> curr;

            mp[curr].first.push_back(i);
            mp[curr].second.push_back(j);
        }
    }

    long long ans = 0; 

    for(auto it = mp.begin(); it != mp.end(); it++) {
        auto &row1 = it->second.first;
        auto &row2 = it->second.second;

        sort(row1.begin(), row1.end());
        sort(row2.begin(), row2.end());

        long long sum1 = 0;
        long long sum2 = 0;

        for(int i = 0; i < row1.size(); i++) {
            ans += (long long)(row1[i])*i - sum1;
            sum1 += row1[i];
        }

        for(int i = 0; i < row2.size(); i++) {
            ans += (long long)(row2[i])*i - sum2;
            sum2 += row2[i];
        }
    }

    cout << ans << '\n';

}   