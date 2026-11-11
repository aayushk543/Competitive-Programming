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

        string s;
        cin >> s;

        string r = s;
        reverse(r.begin(), r.end());

        if(r == s) {
            vector<int> vec(26, 0);

            for(int i = 0; i < n; i++) vec[s[i] - 'a']++;

            int count = 0;

            for(int i = 0; i < 26; i++) {
                if(vec[i] > 0) count++;
            }

            if(count > 1) {
                if(k == 0) cout << "NO" << '\n';
                else cout << "YES" << '\n';
            }
            else cout << "NO" << '\n';

            continue;
        }

        bool flag = false;

        for(int i = 0; i < n/2; i++) {
            if(s[i] == r[i]) continue;
            else {
                if(s[i] > r[i]) {
                    if(k > 0) {
                        flag = true;
                    }
                    break;
                }
                else {
                    flag = true;
                    break;
                }
            }
        }

        if(flag) cout << "YES" << '\n';
        else cout << "NO" << '\n'; 
    }
    
    return 0;
}