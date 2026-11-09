#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;

        int l = s.length();

        int count = 0;
        vector<int> vec(l/2, 0);

        for(int i = 0; i < l / 2; i++) {
            if(s[i] != s[l-i-1]) {
                count++;
                vec[i] = 1;
            }
        }

        int ans = 0;
        int start = -1, end = -1;

        for(int i = 0; i < l / 2; i++) {
            if(start == -1 && vec[i] == 1) {
                start = i;
                end = i;
            }
            else if(vec[i] == 1) end = i;
        }

        if(start == -1) cout << 0 << '\n';
        else cout << end - start + 1 << '\n';
    }
    return 0;
}