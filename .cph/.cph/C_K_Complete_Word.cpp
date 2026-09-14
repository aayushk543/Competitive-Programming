#include<bits/stdc++.h>
using namespace std;

int x;

int curr_maxi = 0;
int curr_size = 0;

void dfs(string& s, vector<int>& mp, int index, vector<int>& vis) {
    int n = s.length();
    vis[index] = false;

    mp[s[index] - 'a']++;

    curr_maxi = max(curr_maxi, mp[s[index] - 'a']);
    curr_size += 1;

    if(n - (index + 1) < n && vis[n - (index + 1)]) dfs(s, mp, n - (index + 1), vis);

    for(int i = index + x; i < n; i += x) {
        if(vis[i]) {
            vis[i] = false;
            dfs(s, mp, i, vis);
        }
        return;
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
                vector<int> mp(26, 0);
                curr_maxi = 0;
                curr_size = 0;

                dfs(s, mp, i, vis);

                int maxi = curr_maxi;
                int size = curr_size;

                ans += size - maxi;
            }
        }

        cout << ans << '\n';
    }
    return 0;
}