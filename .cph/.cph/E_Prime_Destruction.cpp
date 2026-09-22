#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        int n,k;
        cin >> n >> k;

        map<int, int> mp;
        vector<int> dp(200001, -1);

        for(int i = 0; i < n; i++) {
            int curr;
            cin >> curr;

            mp[curr] += 1;
        }

        int ans = 0;

        for(auto it = mp.begin(); it != mp.end(); it++) {

            if(it->first <= k) continue;
            else if(k == 1) {
                int curr = it->first;
                int count = 0;

                for(int i = 2; i * i <= n; i++) {
                    if(curr % i == 0) {
                        int now = curr;

                        while(now % i == 0) {
                            now /= i;
                            count += 1;
                        }
                    }
                }

                ans += (count) * (it->second);
            }
            else {

                map<int, int> mp;
                int curr = it->first;
                int count = 0;

                for(int i = 2; i * i <= curr && i <= k; i++) {
                    if(curr % i == 0) {
                        int now = curr;

                        while(now % i == 0) {
                            now /= i;
                            mp[i] += 1;
                        }
                    }
                }

                



                ans += (it->second) * (count);
            }
        }
        
        cout << ans << '\n';
    }

    

}