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

        vector<long long> h(n);

        for(int i = 0; i < n; i++) cin >> h[i];

        sort(h.begin(), h.end());

        int ans = 0;

        vector<long long> ans_arr(n);

        int p = 0;

        int l = 0, r = n - 1;

        for(int i = 0; i < n; i++) {
            if(p == 0) {
                ans_arr[l++] = h[i];
                p = 1;
            }
            else if(p == 1) {
                ans_arr[r--] = h[i];
                p = 0;
            }
        }

        long long maxi_l = 0;
        vector<long long> f_ans = ans_arr;
        int j = 0;
        vector<bool> vis(n, false);
        for(int i = 0; i < n; i++) {
            if(ans_arr[i] > maxi_l) {
                vis[i] = true;
                ans++;

                //if(i == 3) cout << ans_arr[i] << " " << maxi_l << '\n';
                //maxi_l = ans_arr[i];
                //ans_arr[i] = INT_MIN;
            }
            else if(ans_arr[i] < maxi_l) break;

            maxi_l = max(ans_arr[i], maxi_l);
        }

        long long maxi_r = 0;
        for(int i = n - 1; i >= 0; i--) {
            if(ans_arr[i] > maxi_r) {
                ans++;
                vis[i] = true;
            }
            else if(ans_arr[i] < maxi_r) break;
            maxi_r = max(ans_arr[i], maxi_r);
        }

        ans = 0;
        for(int i = 0; i < n; i++) {
            if(vis[i]) ans++;
        }

        cout << ans << '\n';

        for(int i = 0; i < n; i++) cout << f_ans[i] << " ";
        cout << '\n';
    }
    return 0;
}