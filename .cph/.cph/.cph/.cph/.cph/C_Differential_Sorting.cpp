#include<bits/stdc++.h>
using namespace std;
#define ll as long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        vector<long long> arr(n + 1);

        for(int i = 1; i <= n; i++) cin >> arr[i];

        vector<vector<int>> ans;
        bool flag = true;

        for(int i = n - 2; i >= 1; i -= 2) {

            
            if(arr[i] <= arr[i+1]) continue;
            else {

                // cout << arr[i] << " " << arr[i+1] << " " << arr[i+2] << '\n';
                
                arr[i] = arr[i+1] - arr[i+2];

                // cout << arr[i] << " " << arr[i+1] << " " << arr[i+2] << '\n';

                if(arr[i] <= arr[i+1]) {
                    ans.push_back({i, i + 1, i + 2});
                }
                else {
                    flag = false;
                    cout << -1 << '\n';
                    break;
                }
            }
        }

        

        if(flag) {
            cout << ans.size() << '\n';

            for(int i = 0; i < ans.size(); i++) {
                cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << '\n';
            }
        }
    }
    return 0;
}
