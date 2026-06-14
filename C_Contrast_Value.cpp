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

        vector<long long> nums(n, 0);

        for(int i = 0; i < n; i++){
            cin >> nums[i];
        }

        long long mini = nums[0];
        long long maxi = nums[0];

        int ans = 0;

        for(int i = 1; i < n; i++){
            
        }

        cout << ans << '\n';

    }
    return 0;
}
