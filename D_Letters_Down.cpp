#include<bits/stdc++.h>
using namespace std;

pair<int,int> dfs(vector<vector<int>>& adj, int index, vector<int>& vis, vector<int>& st) {
    vis[index] = 1;
    int curr = index;
    int curr2 = index;

    st.push_back(index);


    for(int i = 0; i < adj[index].size(); i++) {
        int node = adj[index][i];

        if(vis[node] == -1) {
            curr = min(curr, dfs(adj, node, vis, st).first);
            curr2 = max(curr2, dfs(adj, node, vis, st).second);
        }
    }

    return {curr, curr2};
}

long long cal(vector<vector<int>>& adj, int index, vector<int>& vis) {
    vector<int> st;
    long long ans = 0;

    vector<int> vis2(26, -1);
    pair<int,int> p = dfs(adj, index, vis2, st);

    for()

    for(int i = 0; i < st.size(); i++) {
        ans += st[i] - curr;
    }

    return ans;
}

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

        bool flag = true;

        for(int i = 0; i < n / 2; i++) {
            if(s[i] != s[n-i-1]) {
                flag = false;
                break;
            }
        }

        if(flag) cout << 0 << '\n';
        else {
            vector<int> freq(26, 0);

            for(int i = 0; i < n; i++) freq[s[i] - 'a']++;

            int ch;
            long long ans = 0;

            vector<vector<int>> adj(26, vector<int>());

            for(int i = 0; i < n / 2; i++) {
                if(s[i] == s[n-i-1]) continue;

                adj[s[i] - 'a'].push_back(s[n-i-1] - 'a');
                adj[s[n-i-1] - 'a'].push_back(s[i] - 'a');
            }

            vector<int> vis(26, -1);

            for(int i = 0; i < 26; i++) {

                if(adj[i].size() > 0) {
                    ans += cal(adj, i, vis);
                }
            }

            cout << ans << '\n';
        }
    }
    return 0;
}