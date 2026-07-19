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

       long long l = s.length();
       long long curr = 0;
       long long maxi = 0;
       bool t1 = true;

       for(int i = 0; i < 2*l; i++) {
        int ind = i % l;

        if(s[ind] == '1') curr++;
        else curr = 0;

        maxi = max(maxi, curr);

        if(i == l - 1 && maxi == l) break;
       }

       if(maxi == l) cout << l*l << '\n';
       else if(maxi % 2 == 0) {
        cout << (maxi/2)*(maxi/2 + 1) << '\n';
       }
       else {
        cout << (maxi/2 + 1)*(maxi/2 + 1) << '\n';
       }


    }
    return 0;
}