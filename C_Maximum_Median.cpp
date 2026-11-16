#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    if(1) {
        int n,k;
        cin >> n >> k;

        vector<long long> arr(n);

        for(int i = 0; i < n; i++) cin >> arr[i];

        sort(arr.begin(), arr.end());

        int pos = n / 2 + 1;

        arr[n / 2] += min(arr[n/2 + 1] - arr[n/2], (long long)k);
        k -= min(arr[n/2 + 1] - arr[n/2], (long long)k);
        
        cout << arr[n / 2] + (k / pos) << '\n';
    }
    return 0;
}