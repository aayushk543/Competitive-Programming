#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n,q;
       cin >> n >> q;

       vector<long long> arr(n+1);

       arr[0] = 0;

       for(int i = 0; i < n; i++) {
        cin >> arr[i+1];
        if(i > 0) arr[i+1] += arr[i];
       }

       long long t_sum = arr[n];

       for(int i = 0; i < q; i++){
        int l,r;
        long long k;

        cin >> l >> r >> k;

        long long sum = arr[r] - arr[l-1];
        long long now_sum = t_sum - sum + k*(r-l+1);

        if(now_sum % 2 == 1) cout << "YES" << '\n';
        else cout << "NO" << '\n';

       }

    }
    return 0;
}   