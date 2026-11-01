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

        long long sum = 0;

        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            sum += arr[i];
        }

        bool flag = false;

        for(int i = 0; i < n; i++) {
            if(arr[i] > 1) {
                flag = true;
                break;
            }
        }

        if(flag == false) cout << -1 << '\n';
        else {
            bool flag2 = false;

            for(int i = 1; i < n - 1; i++) {
                if(arr[i] != 1) {
                    flag2 = true;
                    break;
                }
            }

            int count = 0;

            if(arr[0] == 1 || arr[1] == 1) count = 1; 

            if(flag2 == false) {
                int ans = 0;

                ans = sum - (n - 1);

                if(ans <= 0) cout << -1 << '\n';
                else cout << ans << '\n';
            }
            else {
                cout << sum - 1 << '\n';
            }
        }
    }
    return 0;
}