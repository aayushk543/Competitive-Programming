#include <bits/stdc++.h>
using namespace std;

int f(vector<int>& arr, int index, vector<int>& dp) {
    int n = arr.size();

    if(dp[index] != -1) return dp[index];

    int val = arr[index];

    int ans = n;

    for(int i = index + val + 1; i <= n; i++) {
        if(ans <= (i - (index + 1 + val))) break;
        ans = min(ans, i - (index + 1 + val) + f(arr, i, dp));
    }

    return dp[index] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);

        for(int i = 0; i < n; i++) cin >> arr[i];

        int mini = n;
        int ans = n;

        
        //vector<int> mini(n);
        //mini[n-1] = 0;

        for(int i = n - 1; i >= 0; i--) {
            int val = arr[i];
            mini += 1;

            if(val + i + 1 >= n) {
                arr[i] = (n - i);

                if(val + i + 1 == n) arr[i] = 0;
            }
            else {
                arr[i] = arr[val + i + 1];

                mini = min(mini, arr[i]);

                arr[i] = mini;
            }

            mini = min(mini, arr[i]);
            arr[i] = mini;

        }

        for(int i = 0; i < n; i++) ans = min(ans, arr[i] + i);

        cout << ans << '\n';
    }
}