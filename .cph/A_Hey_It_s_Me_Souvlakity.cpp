#include<bits/stdc++.h>
using namespace std;

bool check(int mid, vector<vector<int>>& vec) {
    int n = vec.size();

    int l = 0, r = mid;

    for(int i = 0; i < n; i++) {

        if(r < vec[i][0] || l > vec[i][1]) return false;
        else {
            l = max(l, vec[i][0]) - mid;
            if(l < 0) l = 0;
            r = min(r, vec[i][1]) + mid;
        }
    }

    return true;
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

        vector<int> sol;
        vector<int> kal;

        for(int i = 0; i < n; i++) {
            if(s[i] == '0') kal.push_back(i+1);
            else sol.push_back(i + 1);
        }

        int ans = 0;

        if(sol.size() > 0) {
            ans = sol[sol.size() - 1] - sol[0];
            cout << ans << '\n';
        }
        else cout << 0 << '\n';
    }
    return 0;
}