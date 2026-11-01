#include<bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        int n,m;
        cin >> n >> m;

        string p,q;
        cin >> p >> q;

        vector<int> mp(26, 0);

        bool flag = false;

        for(int i = 0; i < n; i++) mp[p[i] - 'a']++;
        for(int i = 0; i < m; i++) {
            if(mp[q[i] - 'a'] <= 0) {
                flag = true;
                break;
            }
            else mp[q[i] - 'a']--;
        }

        if(flag) cout << "NO" << '\n';
        else {

            if(mp['s' - 'a'] == 1 && mp['i' - 'a'] == 1 && mp['x' - 'a'] == 1) flag = false;
            else flag = true;

            if(flag) cout << "NO" << '\n';
            else {
                for(int i = 0; i < 26; i++) {

                    if(i == 's' - 'a' || i == 'i' - 'a' || i == 'x' - 'a') continue;

                    if(mp[i] > 0) {
                        flag = true;
                        break;
                    }
                }

                if(flag) cout << "NO" << '\n';
                else cout << "YES" << '\n';
            }
        }

    }
    return 0;
}