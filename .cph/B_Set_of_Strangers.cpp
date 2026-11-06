#include<bits/stdc++.h>
using namespace std;

bool check(vector<vector<int>>& adj, int x, int y) {
    int n = adj.size() - 1;
    int m = adj[0].size() - 1;

    //cout << n << " " << m << '\n';

    adj[x][y] = 1;

    if(x - 1 >= 1 && adj[x-1][y] == 1) return false;
    //cout << "flag1" << '\n';
    if(y - 1 >= 1 && adj[x][y-1] == 1) return false;
    //cout << "flag2" << '\n';
    if(x + 1 <= n && adj[x+1][y] == 1) return false;
    //cout << "flag3" << '\n';
    if(y + 1 <= m && adj[x][y+1] == 1) return false;
    //cout << "flag4" << '\n';

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n,m;
        cin >> n >> m;

        vector<vector<int>> mat(n + 1, vector<int>(m + 1));
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) cin >> mat[i][j];
        }

        map<int, int> mp;

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {

                if(j + 1 <= m && mat[i][j] == mat[i][j+1]) {
                    mp[mat[i][j]] = 2;
                }
                else if(i + 1 <= n && mat[i+1][j] == mat[i][j]) mp[mat[i][j]] = 2;
                else mp[mat[i][j]] = max(mp[mat[i][j]], 1);
            }
        }

        int ans = 0, maxi = 0;

        for(auto it = mp.begin(); it != mp.end(); it++) {
            maxi = max(maxi, it->second);
            ans += it->second;
        }

        cout << ans - maxi << '\n';

    }
    return 0;
}