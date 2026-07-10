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

        map<char, int> mp;

        for(int i = 0; i < n; i++) {
            mp[s[i]]++;
        }

        int count = 0;

        for(auto it = mp.begin(); it != mp.end(); it++) {
            if(it->second % 2) count++;
        }

        if(count - 1 > k) cout << "NO" << '\n';
        else cout << "YES" << '\n';
    }
    return 0;
}