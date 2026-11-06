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

        vector<vector<int>> arr(n, vector<int>(2));

        map<int, int> mp;

        for(int i = 0; i < n; i++) {
            cin >> arr[i][0] >> arr[i][1];

            if(arr[i][0] == arr[i][1]) mp[arr[i][0]] += 1;
        }

        vector<int> interval(2*n + 1, 0);

        for(auto it = mp.begin(); it != mp.end(); it++) interval[it->first] += 1;

        for(int i = 1; i <= 2*n; i++) interval[i] += interval[i-1];

        string ans = "";

        for(int i = 0; i < n; i++) {

            int l = arr[i][0];
            int r = arr[i][1];

            if(l == r) {
                if(mp[l] > 1) ans += '0';
                else ans += '1';
            }
            else {
                //bool flag = true;
                // for(int i = l; i <= r; i++) {
                //     if(mp[i] == 0) {
                //         flag = false;
                //         break;
                //     }
                // }

                if(interval[r] - interval[l-1] < (r - l + 1)) ans += '1';
                else ans += '0';
            }
        }

        cout << ans << '\n';
    }
    return 0;
}