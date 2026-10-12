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

       map<int, int> mp;

       for(int i = 0; i < n; i++) {
        int m;
        cin >> m;

        mp[m] += 1;
       }

       int count = 0;
       int c = -1;

       for(auto it = mp.begin(); it != mp.end(); it++) {

        if(it->first != count) {
            //cout << it->first << '\n';
            c = 0;
            break;
        }
        else {
            //cout << it->second << '\n';
            if(it->second >= 2*k) {
                count++;
                continue;
            }
            else if(it->second == (2*k - 1)) {
                c = 1;
                break;
            }
            else {
                c = 0;
                break;
            }
        }

        count++;
       }

       if(c == 0 || c == -1) {
        cout << "NO" << '\n';
       }
       else cout << "YES" << '\n';

    }
    return 0;
}