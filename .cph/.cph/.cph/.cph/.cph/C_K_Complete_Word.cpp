#include<bits/stdc++.h>
using namespace std;

int x;

void dfs(string& s, map<char, int>& mp, int index, vector<int>& vis) {
    int n = s.length();
    vis[index] = false;

    mp[s[index]]++;
    if(n - (index + 1) < n && vis[n - (index + 1)]) dfs(s, mp, n - (index + 1), vis);

    for(int i = index + x; i < n; i += x) {
        if(vis[i]) {
            vis[i] = false;
            dfs(s, mp, i, vis);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n,k;
        cin >> n >> k;

        x = k;

        string s;
        cin >> s;

        vector<int> vis(n, true);

        int ans = 0;

        for(int i = 0; i < n; i++) {
            if(vis[i]) {
                map<char, int> mp;
                dfs(s, mp, i, vis);

                int maxi = 0;
                int size = 0;

                for(auto it = mp.begin(); it != mp.end(); it++) {
                    maxi = max(maxi, it->second);
                    size += it->second;
                }

                ans += size - maxi;
            }
        }

        cout << ans << '\n';
    }
    return 0;
}