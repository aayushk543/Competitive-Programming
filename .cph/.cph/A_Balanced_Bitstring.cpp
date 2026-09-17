#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n,k;
        cin >> n >> k;

        bool flag = true;

        string s;
        cin >> s;

        vector<vector<int>> adj;

        vector<bool> vis(n + 1, false);

        for(int i = 0; i < n; i++) {
            if(vis[i] == false) {
                int index = i;
                vis[i] = true;

                if(s[index] != '?') {

                    while(index + k < n && (s[index] == s[index+k] || s[index+k] == '?')) {
                        s[index+k] = s[index];
                        vis[index] = true;
                        index += k;
                    }

                    if(index + k < n) {
                        flag = false;
                        break;
                    }
                }
                else {

                    char curr = 'a';

                    while(index < n && s[index] == '?') {
                        vis[index] = true;
                        index += k;
                    }
                    if(index >= n) {
                        
                    }
                    else {
                        int j = i;
                        s[j] = s[index];
                        while(j <= index && j < k) {
                            s[j] = s[index];
                            vis[j] = true;
                            j += k;
                        }

                        while(index + k < n && (s[index] == s[index + k] || s[index + k] == '?')) {
                            s[index + k] = s[index];
                            vis[index + k] = true;
                            index += k;
                        }

                        if(index + k < n) {
                            flag = false;
                            break;
                        }
                    }
                }
            }
        }



        if(flag) {

            int count_0 = 0, count_1 = 0;

            for(int i = 0; i < k && i < n; i++) {

                //cout << s[i] << '\n';

                if(s[i] == '0') {
                    count_0++;
                    //cout << '0' << '\n';
                }
                else if(s[i] == '1') count_1++;

            }

            int count_ = k - (count_0 + count_1);

            //cout << count_0 << " " << count_1 << '\n';
            //cout << s << '\n';

            if(max(count_0, count_1) - min(count_0, count_1) > count_) cout << "NO" << '\n';
            else cout << "YES" << '\n';
        }
        else cout << "NO" << '\n';
    }


}