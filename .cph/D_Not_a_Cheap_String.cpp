#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        string w;
        cin >> w;

        int p;
        cin >> p;

        vector<int> vec(27, 0);
        map<char, vector<int>> mp;

        int sum = 0;

        for(int i = 0; i < w.length(); i++) {
            vec[w[i] - 'a' + 1]++;
            sum += (w[i] - 'a' + 1);

            mp[w[i]].push_back(i);
        }

        for(int i = 26; i > 0; i--) {
            while(vec[i] > 0 && sum > p) {
                sum -= i;
                vec[i]--;
            }
        }

        string ans = "";
        if(sum > p) {
            cout << ans << '\n';
            continue;
        }
        vector<bool> vis(w.length(), false);

        for(int i = 1; i <= 26; i++) {

            vector<int> curr = mp[char(i - 1 + 'a')];

            for(int j = 0; j < vec[i]; j++) vis[curr[j]] = true;
        }

        for(int i = 0; i < w.length(); i++) {
            if(vis[i]) ans += w[i];
        }

        cout << ans << '\n';

    }
    
    return 0;
}