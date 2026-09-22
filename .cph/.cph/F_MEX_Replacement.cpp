#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<pair<long long, long long>> vp(n);

        for(int i = 0; i < n; i++) cin >> vp[i].first >> vp[i].second;

        sort(vp.begin(), vp.end());

        int curr = 0;
        int mini = 0;

        for(int i = 0; i < n; i++) {

            if(vp[i].first == curr) {
                curr++;
                mini = min(mini, vp[i].second);
            }
            else {
                
            }
        }
    }

    

}