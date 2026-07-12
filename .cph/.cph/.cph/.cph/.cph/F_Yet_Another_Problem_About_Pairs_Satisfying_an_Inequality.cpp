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

        vector<pair<long long, int>> arr;

        for(int i = 1; i <= n; i++) {
            long long m;
            cin >> m;

            if(m >= i) continue;

            arr.push_back({m, i});
        }

        long long ans = 0;

        sort(arr.begin(), arr.end());

        for(int i = 0; i < arr.size(); i++) {
            int curr = arr[i].second;
            
            int l = i, r = arr.size() - 1;

            while(l <= r) {
                int mid = (l + r) / 2;

                if(arr[mid].first > curr) {
                    r = mid - 1;

                }
                else l = mid + 1;
            }

            //cout << arr.size() - l << '\n';
            ans += arr.size() - l;
        }

        cout << ans << '\n';
    }
    return 0;
}