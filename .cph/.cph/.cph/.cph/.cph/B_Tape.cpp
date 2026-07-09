#include <iostream>
#include <vector>
#include <climits>
#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

        long long n,m,k;
        cin >> n >> m >> k;

        long long first;
        cin >> first;
        vector<long long> vis;

        long long one = first;
        long long last;

        for(int i = 1; i < n; i++) {
            long long second;
            cin >> second;

            if(i == n - 1) last = second;

            vis.push_back(second - first - 1);
            first = second;
        }

        long long ans = last - one + 1;
        sort(vis.begin(), vis.end(), greater<int>());

        for(int i = 0; i < k - 1; i++) {
            ans -= vis[i];
        }
        

        cout << ans << '\n';
    return 0;
}   