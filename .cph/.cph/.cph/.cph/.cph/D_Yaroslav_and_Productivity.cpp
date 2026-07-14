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

        vector<long long> pre(n + 1, 0);
        vector<int> post(m);

        vector<vector<long long>> dp(m + 1, vector<long long>(2));
        dp[0][0] = 0;
        dp[0][1] = LLONG_MIN/2;

        long long sum = 0;

        for(int i = 1; i <= n; i++) {
            long long p;
            cin >> p;
            sum += p;
            pre[i] = sum;
        }
        for(int i = 0; i < m; i++) cin >> post[i];

        sort(post.begin(), post.end(), greater<int>());

        for(int i = 0; i < m; i++) {
            long long curr = pre[post[i]];

            dp[i+1][0] = max(dp[i][0], dp[i][1] + (2*curr));
            dp[i+1][1] = max(dp[i][1], dp[i][0] - (2*curr));

        }

        // vector<long long> add(n);
        // vector<long long> sub(n);

        // long long adding = 0;
        // long long subtrct = 0;

        // for(int i = 0; i < n; i++) {
        //     if(arr[i] >= 0) {
        //         adding += arr[i];
        //     }
        //     else {
        //         subtrct += -1 * arr[i];
        //     }

        //     add[i] = adding;
        //     sub[i] = subtrct;
        // }


        cout << sum + max(dp[m][0], dp[m][1]) << '\n';

    }
    return 0;
}