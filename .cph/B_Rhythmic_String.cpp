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

        for(int i = 0; i < n; i++) cin >> arr[i];

        int ans = 0;

        for(int i = 0; i < n; i++) {
            int curr = arr[i];
            int count = 0;

            for(int j = 0; j < n; j++) {
                if(arr[j] % curr == 0) count++;
            }

            ans = max(ans, count);
        }

        cout << n- ans << '\n';
    }
    return 0;
}