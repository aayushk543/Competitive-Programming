#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int k;
        long long x;
        cin >> k >> x;

        long long c = 1LL << k; 
        long long v = c;

        vector<int> ans;

        
        
        while (c != x ) {
            if (c > x) {
                c /= 2;
                v += c;
                ans.push_back(1);
            } else {
                v /= 2;
                c += v;
                ans.push_back(2);
            }
        }

            cout << ans.size() << "\n";
            for (int step : ans) cout << step << " ";
            cout << "\n";
        
    }
    return 0;
