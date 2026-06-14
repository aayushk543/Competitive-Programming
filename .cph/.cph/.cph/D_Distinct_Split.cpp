#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        unordered_map<char, int> mp;

        for(int i = 0; i < s.length(); i++){
            mp[s[i]]++;
        }

        int ans = 0;
        set <char> st;

        for(int i = 0; i < s.length(); i++){
            st.insert(s[i]);
            if(mp[s[i]] > 0) mp[s[i]]--;
            if(mp[s[i]] == 0) mp.erase(s[i]);
            ans = max(ans, (int)st.size() + (int)mp.size());
        }
        cout << ans << '\n';
    }
    return 0;
}