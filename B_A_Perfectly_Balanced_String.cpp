#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;

        bool flag = true;

        string pattern = "";
        map<char, int> mp;

        mp[s[0]] = 1;

        map<char, int> mp2;

        for(int i = 0; i < s.length(); i++) {
            mp2[s[i]] += 1;
        }

        for(int i = 1; i < s.length(); i++) {
            
            if(s[i] == s[0]) {
                pattern = s.substr(0, i);
                break;
            }

            if(mp[s[i]] == 1) {
                flag = false;
                break;
            }
            mp[s[i]] = 1;
        }

        if(mp2.size() == 1) {
            cout << "YES" << '\n';
            continue;
        }

        for(int i = 1; i < s.length(); i++) {
            if(s[i] == s[i-1]) {
                flag = false;
                break;
            }
        }

        if(pattern.length() == 0) {
            if(flag) cout << "YES" << '\n';
            else cout << "NO" << '\n';

            continue;
        }

        for(int i = 0; i < s.length(); i++) {

            int j = i % pattern.length();

            // cout << s[i] << " " << pattern[j] << '\n';
            // cout << i << " " << j << '\n';
            if(s[i] != pattern[j]) {
                flag = false;
                break;
            }
        }

        if(flag) cout << "YES" << '\n';
        else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}