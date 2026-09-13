#include <bits/stdc++.h>
using namespace std;

int m;

long long f(vector<long long>& arr, int curr, int index, int prev, vector<vector<long long>>& dp) {
    if(curr == m) return 0;
    if(index == arr.size()) return LLONG_MIN;

    if(dp[index][curr] != -1) return dp[index][curr];

    long long skip = f(arr, curr, index + 1, prev, dp);

    long long take = f(arr, curr + 1, index + 1, arr[index], dp);
    if(take != LLONG_MIN) take += (curr + 1)*(arr[index] - prev);

    return dp[index][curr] = max(skip, take);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n >> m;

        vector<long long> arr(n);
        // vector<vector<long long>> dp(n, vector<long long>(n, -1));

        for(int i = 0; i < n; i++) cin >> arr[i];

        // cout << f(arr, 0, 0, 0, dp) << '\n';

        priority_queue<long long, vector<long long>, greater<long long>> pq;
        long long sum = 0;

        for(int i = 0; i < m - 1; i++) {
            sum -= arr[i];
            pq.push({-1*arr[i]});
        }

        long long ans = LLONG_MIN;

        for(int i = m - 1; i < n; i++) {

            ans = max(ans, sum + (m)*arr[i]);

            if(!pq.empty() && arr[i] * -1 > pq.top()) {
                sum -= pq.top();
                sum += arr[i] * -1;
                pq.pop();
                pq.push({arr[i] * -1});
            }
        }

        cout << ans << '\n';
    }
}