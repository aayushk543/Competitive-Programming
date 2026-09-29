#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
       int n;
       long long c;

       cin >> n >> c;

       vector<long long> arr(n);

       for(int i = 0; i < n; i++) {
        cin >> arr[i];
        arr[i] += i + 1;
       }

       sort(arr.begin(), arr.end());

       int ans = 0;

       for(int i = 0; i < n; i++) {

        if(c >= arr[i]) {
            c -= arr[i];
            ans++;
        }
        else break;
       }

       cout << ans << '\n';
       
       
    }
    return 0;
}