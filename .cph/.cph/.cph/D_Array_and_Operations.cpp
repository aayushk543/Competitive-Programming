#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n,k;

        cin >> n >> k;

        vector<int> arr(n);
        int ans = 0;

        for(int i = 0; i < n; i++) cin >> arr[i];

        sort(arr.begin(), arr.end());

        for(int i = n-1; i > n-1-k; i -= 2){
            ans += floor(arr[i-1]/arr[i]); 
        }

        for(int i = n-1-k; i >= 0; i--){
            ans += arr[i];
        }

        cout << ans << '\n';

    }
    return 0;
}