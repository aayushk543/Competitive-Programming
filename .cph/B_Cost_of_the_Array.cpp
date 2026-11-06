#include<bits/stdc++.h>
using namespace std;

int mod = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n,k;
        cin >> n >> k;

        vector<int> arr(n);

        for(int i = 0; i < n; i++) cin >> arr[i];

        if(arr[0] != 1) cout << 1 << '\n';
        else {
            int i = 0;

            while(i < n && arr[i] == 1) i++;

            int rem = n - i;

            if(rem >= k - 1) cout << 1 << '\n';
            else {
                
            }
        }
    }
    return 0;
}