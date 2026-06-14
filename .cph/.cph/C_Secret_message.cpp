#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<string> s(k);
        for (int i = 0; i < k; i++) {
            cin >> s[i];
        }

        vector<vector<pair<char, vector<int>>>> cols(n);


        for (int col = 0; col < n ; col++) {
            unordered_map<char, int> idx;

        for (int row = 0; row < k; row++) {
            char c = s[row][col];

        if (!idx.count(c)) {
            cols[col].push_back({c, {}});
            idx[c] = cols[col].size() - 1;
        }

        cols[col][idx[c]].second.push_back(row);
        }
    }

    string ans;

    for (int col = 0; col < n; col++) {
    char best;
    int mx = 0;

    for (auto &p : cols[col]) {
        if ((int)p.second.size() > mx) {
            mx = p.second.size();
            best = p.first;
        }
    }

    ans.push_back(best);
}


        cout << ans << '\n';
    }

    return 0;
}
