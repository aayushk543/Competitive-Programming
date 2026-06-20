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

        long long diff = 0;
        long long mini_diff = INT_MAX;

        for(int i = 0; i < n; i++) {
            cin >> arr[i];

            if(i > 0) {
                diff = arr[i] - arr[i-1]; 
                mini_diff = min(mini_diff, diff);
            }
        }

        if(mini_diff < 0) {
            cout << 0 << '\n';
        } 
        else {
            cout << (mini_diff / 2 ) + 1 << '\n';
        }



    }
    return 0;
}