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
        int count = 1;
        bool c = false;
        bool c2 = false;

        for(int i = 0; i < n; i++){
            cin >> nums[i];
            if(i > 0) {
                if(!c && nums[i-1] > nums[i]) {
                    c = true;
                    count++;
                    c2 = false;
                }
                else if(!c2 && nums[i-1] < nums[i]) {
                    c2 = true;
                    count++;
                    c = false;
                }
            }
        }

        cout << max(count, 1) << '\n';

    }
    return 0;
}
