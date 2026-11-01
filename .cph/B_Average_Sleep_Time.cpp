#include<bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if(1) {
        int n,k;
        cin >> n >> k;

        vector<long long> arr(n + 1);

        for(int i = 1; i <= n; i++) {
            cin >> arr[i];
            arr[i] += arr[i-1];
        }

        double ans = 0.00;

        //for(int i = 1; i <= k; i++) ans += arr[i];

        for(int i = k; i <= n; i++) {
            double curr = ((arr[i] - arr[i-k]) * 1.00);

            ans += curr;
        }

        cout << fixed << setprecision(10) << ans / (n - k + 1.00) << '\n'; 

    }
    return 0;
}