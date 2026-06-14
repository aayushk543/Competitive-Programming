#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        long long x;

        cin >> n >> x;

        vector<long long> arr(n,0);

        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        sort(arr.begin(), arr.end());

        for(int i = 1; i < n; i++) arr[i] += arr[i-1];

        long long total_count = 0;

        for(int i = 0; i < n; i++){
            if(arr[i] > x) break;

            total_count += (x - arr[i]) / (i + 1) + 1;
        }

        cout << total_count << '\n';
    }
    return 0;
}