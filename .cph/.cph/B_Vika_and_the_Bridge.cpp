#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n,k;
        cin >> n >> k;
        
        vector<int> planc(n,0);

        vector<pair<pair<int, int>, int>> arr(k, {{1,0}, 0});

        for(int i = 0; i < n; i++){
            cin >> planc[i];
        }

        int ans = INT_MAX;

        for(int i = 0; i < n; i++){
            if(arr[planc[i] - 1].first.second == 0){
                arr[planc[i] - 1].first.second = i + 1;
            }
            else if(arr[planc[i] - 1].second == 0){
                arr[planc[i] - 1].second = i + 1;
            }
            else if(i + 1 - (arr[planc[i] - 1].second) > (arr[planc[i] - 1].first.second - arr[planc[i] - 1].first.first)) {
                arr[planc[i] - 1].first.first = arr[planc[i] - 1].second;
                arr[planc[i] - 1].second = i + 1;
                arr[planc[i] - 1].first.second = i + 1;
            }
            else {
                arr[planc[i] - 1].second = i + 1;
            }

            if(i == n - 1){
            for(int j = 0; j < k; j++){
                if(arr[j].second == 0){
                    if(arr[j].first.second == 0){
                        ans = min(ans, max(arr[j].first.first,n - arr[j].first.first));
                    }
                    else ans = min(ans, max(n - arr[j].first.second, arr[j].first.second - arr[j].first.first));
                }
                else ans = min(ans, max(n - arr[j].second, arr[j].first.second - arr[j].first.first));
            }
        }
        }

        
        cout << (ans-1)/2 << '\n';
    }
    return 0;
}
