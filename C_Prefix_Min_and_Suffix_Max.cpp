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

        vector<int> arr(n);
        string ans = "";

        for(int i = 0; i < n; i++) ans += '0';

        for(int i = 0; i < n; i++) cin >> arr[i];

        int mini = INT_MAX, mini_index = -1;
        int maxi = INT_MIN, maxi_index = n;

        for(int i = 0; i < n; i++) {

            if(arr[i] < mini) {
                ans[i] = '1';
                mini = arr[i];
            }
        }

        for(int i = n - 1; i >= 0; i--) {

            if(arr[i] >= maxi) {
                ans[i] = '1';
                maxi = arr[i];
            }
        }

        cout << ans << '\n';

    }
    return 0;
}