#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        long long n,k;
        cin >> n >> k;

        vector<long long> arr(n , 0);

        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }

        sort(arr.begin(), arr.end());
        int ans = 1;
        int maxi = 0;

        for(int i = 1; i < n; i++){
            if(arr[i] - arr[i-1] <= k) ans++;
            else ans = 1;

            maxi = max(maxi, ans);
        }
        if(n == 1){
            n = maxi;
        }
        cout << n - maxi << '\n';
    }
    return 0;
}