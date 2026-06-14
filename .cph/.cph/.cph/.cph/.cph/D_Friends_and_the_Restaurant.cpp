#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        long long sum = 0;
        cin >> n;

        vector<long long> nums(n,0);

        for(int i = 0; i < n; i++){
            cin >> nums[i];
        }
        for(int i = 0; i < n; i++){
            long long m;
            cin >> m;
            nums[i] = m - nums[i];
            sum += nums[i];
        }

        sort(nums.begin(), nums.end());

        int l = 0, r = n-1;
        int ans = 0;
        
        while(l < r) {
            int curr = nums[l] + nums[r];
            if(curr >= 0) {
                ans++;
                l++;
                r--;
            }
            else l++;

        }

        cout << ans << '\n';
    }
    return 0;
}