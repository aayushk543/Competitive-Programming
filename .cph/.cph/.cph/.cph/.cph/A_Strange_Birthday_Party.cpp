#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n,m;

        cin >> n >> m;

        vector<int> assign(n);

        for(int i = 0; i < n; i++) {
        
            cin >> assign[i];
        }

        vector<long long> prices(m + 1);

        for(int i = 1; i <= m; i++) cin >> prices[i];

        sort(assign.begin(), assign.end());
        int j = 1;
        long long ans = 0;

        for(int i = n - 1; i >= 0; i--) {

            if(prices[j] < prices[assign[i]]) {
                //cout << prices[j] << '\n';
                ans += prices[j];
                //prices[j] = -1;
                j++;
            }
            else {
                ans += prices[assign[i]];
                //prices[assign[i].first] = -1;
            }
        }

        cout << ans << '\n';
    }
    return 0;
}
