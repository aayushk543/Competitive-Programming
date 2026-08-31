#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
       int n;
       long long k;

       cin >> n >> k;

       vector<int> arr(31, 0);

       for(int i = 0; i < n; i++) {
        long long num;
        cin >> num;

        for(int j = 0; j < 31; j++) {

            if((num >> j) & 1 == 1) {
                arr[j]++;
            }
        }
       }

       for(int i = 0; i < 31; i++) {
        arr[i] = n - arr[i];
       }

       long long ans = 0;

       for(int i = 30; i >= 0; i--) {

        if(k >= arr[i]) {
            k -= arr[i];
            ans += (1 << i);
        }
       }

       cout << ans << '\n';


    }
    return 0;
}