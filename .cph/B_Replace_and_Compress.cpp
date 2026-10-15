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

       int i = 0;

       int ans = 1;
       bool flag = false;
       bool flag2 = false;

       while(i < l) {

        int count_0 = 0, count_1 = 0;

        while(i < l && s[i] == '0') {
            count_0++;
            i++;
        }

        if(count_0 > 2) flag2 = true;
        else if(count_0 == 1 && i != l && i != 1) flag = true;

        while(i < l && s[i] == '1') {
            count_1++;
            i++;
        }
        
        if(count_1 > 2) flag2 = true;
        else if(count_1 == 1 && i != l && i != 1) flag = true;

       }

       if(flag) ans++;
       if(flag2) ans++;

       cout << ans << '\n';
    }
    return 0;
}