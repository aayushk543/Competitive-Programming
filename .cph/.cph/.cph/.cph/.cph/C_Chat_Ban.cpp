#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
       long long k,x;
       cin >> k >> x;

       long long l = 1, r = 2*k-1;
       long long ans = r;

       while(l <= r){
        long long mid = floor((l+r)/2);

        long long messages;

        if(mid <= k) messages = (mid*(mid+1))/2;

        if(mid > k) messages = (k*(k+1))/2 + (mid-k)*k - ((mid-k)*(mid-k+1))/2;

        if(messages >= x) {
            r = mid-1;
            ans = mid;
        }
        else l = mid+1;

       }

       cout << ans << '\n';
    }
    return 0;
}