#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
       int n, k;
       cin >> n >> k;

       vector<long long> arr(n);

       long long sum = 0;
       long long ans = LLONG_MIN;

       for(int i = 0; i < n; i++) {
        cin >> arr[i];
       }

       sort(arr.begin(), arr.end());

       for(int i = 0; i < n-k; i++) sum += arr[i];

       ans = max(ans, sum);
       int l = 0, r = n-1-k;

       for(int i = n-k; i < n; i++){
        sum -= ((arr[l] + arr[l+1]) - arr[i]);
        l += 2;
        ans = max(ans, sum);
       }

       
       cout << ans << '\n';
    }
    return 0;
}