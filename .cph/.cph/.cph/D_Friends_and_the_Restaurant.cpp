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

        vector<long long> nums(n,0);

        for(int i = 0; i < n; i++){
            cin >> nums[i];
        }
        for(int i = 0; i < n; i++){
            long long m;
            cin >> m;
            nums[i] = m - nums[i];
        }

        sort(nums.begin(), nums.end());

        int l = 0, r = n - 1;
        long long ans = 0;
        

        while(l <= r){
            
            long long sum = nums[l] + nums[r];

            while(l < r && sum < 0){
                r--;
                sum += nums[r];
            }

            if(sum >= 0){
                ans++;
            }
            l++;
            r--;
        }
        

        cout << ans << '\n';
    }
    return 0;
}