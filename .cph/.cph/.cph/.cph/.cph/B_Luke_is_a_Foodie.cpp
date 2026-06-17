#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        long long x;

        cin >> n >> x;

        vector<long long> arr(n);

        for(int i = 0; i < n; i++) cin >> arr[i];

        int count = 1;

        long long mini = LLONG_MAX;
        long long maxi = LLONG_MIN;

        for(int i = 0; i < n; i++){
            mini = min(mini, arr[i]);
            maxi = max(maxi, arr[i]);

            if(maxi - mini > 2 * x) {
                mini = arr[i];
                maxi = arr[i];
                count++;
                
            }
        }

        
        cout << count - 1 << '\n';
    }

    return 0;
}