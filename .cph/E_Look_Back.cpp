#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
       int n;
       cin >> n;

       vector<long long> arr(n);

       for(int i = 0; i < n; i++) {
        int num;
        cin >> num;

        int count = 0;

        while(num > 0) {
            num >>= 1;
            count++;
        }

        arr[i] = count;
       }

       long long prev = arr[0];
       int ans = 0;

       for(int i = 1; i < n; i++) {
        
        if(arr[i-1] > arr[i]) {
            int num = (arr[i-1] - arr[i]);
            
            ans += (31 - _builtin_clz((unsigned int)num));
        }
       }

       cout << ans << '\n';
    }
    return 0;
}