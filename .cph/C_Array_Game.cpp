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

        vector<long long> vec(n);

        for(int i = 0; i < n; i++) cin >> vec[i];

        if(k > 2) cout << 0 << '\n';
        else if(k == 1) {
            sort(vec.begin(), vec.end());

            long long diff = vec[0];

            //cout << diff << '\n';

            for(int i = 1; i < n; i++) {

                //cout << vec[i] - vec[i-1] << '\n';
                diff = min(diff, vec[i] - vec[i-1]);
            }

            cout << diff << '\n';

        }
        else if(k == 2) {
            vector<vector<long long>> vec2;
            sort(vec.begin(), vec.end());
            //vec2.push_back({vec[0], 0});

            long long ans = LLONG_MAX;

            // for(int i = 0; i < vec.size(); i++) cout << vec[i] << " ";
            // cout << '\n';

            for(int i = 0; i < n; i++) {
                vec2.push_back({vec[i], 0});

                for(int j = 0; j < n; j++) {

                    vec2.push_back({abs(vec[j] - vec[i]), 1});
                    if(i != j) ans = min(ans, abs(vec[j] - vec[i]));
                }
            }

            sort(vec2.begin(), vec2.end());

            // for(int i = 0; i < vec2.size(); i++) cout << vec2[i][0] << " " << vec2[i][1] << '\n';
            // cout << '\n';

            for(int i = 0; i < vec2.size() - 1; i++) {
                if(vec2[i+1][1] == 1 && vec2[i][1] == 1) continue;

                // cout << "olo" << " " << vec2[i+1][0] - vec2[i][0] << " ";
                ans = min(ans, vec2[i+1][0] - vec2[i][0]);
            }

            cout << ans << '\n';
        }
    }
    return 0;
}