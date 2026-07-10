#include<bits/stdc++.h>
using namespace std;

int f(vector<int>& arr, int index, vector<int>& dp) {
    if(index >= arr.size() - 1) return 0;

    if(dp[index] != -1) return dp[index];
 
    return dp[index] = min(arr[index] + arr[index + 1] + min(f(arr, index + 3, dp), f(arr, index + 4, dp)), arr[index] + min(f(arr, index + 2, dp), f(arr, index + 3, dp)));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        vector<int> arr(n + 1, 0);

        for(int i = 0; i < n; i++) cin >> arr[i];

        vector<int> dp(n, -1);

        cout << f(arr, 0, dp) << '\n';
    }
    return 0;
}