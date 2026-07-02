#include <vector>
#include <iostream>
#include <string>
#include<map>
#include <unordered_map>
using namespace std;

//int co = 0;

int ans = 0;

int f(vector<vector<int>>& adj, int index, string s) {
    if(index == -1) return 0;

    int num = 0;

    if(s[index - 1] == 'W') num += 1;
    else num -= 1;

    for(int i = 0; i < adj[index].size(); i++) num += f(adj,adj[index][i],s);

    //cout << m << " " << n << " ";

    if(num == 0) ans++;

    return num;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n; 
        cin >> n;

        ans = 0;

        vector<vector<int>> adj(n + 1, vector<int>(2, -1));

        for(int i = 2; i <= n; i++) {
            int m;
            cin >> m;

            adj[m].push_back(i);
        }

        // unordered_map<int,int> mp_white;
        // unordered_map<int,int> mp_black;

        string s;

        cin >> s;
        
        f(adj, 1, s);

        cout << ans << '\n';


    }
    return 0;
}