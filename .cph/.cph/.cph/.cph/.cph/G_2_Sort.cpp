#include <iostream>
#include <vector>
#include <climits>
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
        
        for(int i = 0; i < n; i++){
            cin >> arr[i];  
        }

        int count = 1;
        int ans = 0;

        for(int i = 0; i < n - 1; i++) {
        
            if(arr[i] < 2LL * arr[i+1]) count++;
            else if(arr[i] >= 2LL*arr[i+1]) {
                count = 1;
            }

            if(count >= k + 1) ans++;
        }

        cout << ans << '\n';

        
    }
    return 0;
}   