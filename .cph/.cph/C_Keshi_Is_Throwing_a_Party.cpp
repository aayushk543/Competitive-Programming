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

       vector<vector<int>> arr(n, vector<int>(3));

       for(int i = 0; i < n; i++) {
        cin >> arr[i][1];
        cin >> arr[i][2];
        arr[i][0] = arr[i][1] + arr[i][2] + 1;
       }

       sort(arr.begin(), arr.end());
       int ans = 0;
       int i = 0;

       while(i < n) {

        int curr = arr[i][0];
        int j = i;

        while(i + 1 < n && arr[i + 1][0] == curr && curr >= i - j) i++;

        int len = min(curr, i - j + 1);
        if(len > ans) ans = len;
        while(i < n && arr[i][0] == curr) i++;

       }

       cout << ans << '\n';

    }
    return 0;
}