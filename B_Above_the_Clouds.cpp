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

        vector<int> ch(26, 0);
        bool flag = true;

        for(int i = 1; i < n - 1; i++) {
            ch[s[i] - 'a']++;

            if(ch[s[i] - 'a'] > 1) {
                flag = false;
                cout << "Yes" << '\n';
                break;
            }
        }

        if((ch[s[0] - 'a'] > 0 || ch[s[n-1] - 'a'] > 0) && flag) {
            flag = false;
            cout << "Yes" << '\n';
        }

        if(flag) cout << "No" << '\n';

    }
    return 0;
}