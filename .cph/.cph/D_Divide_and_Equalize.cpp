#include<bits/stdc++.h>
using namespace std;

void f(int num, map<int,int>& mp) {

    for(int i = 2; i * i <= num; i++) {

        while(num % i == 0) {
            num /= i;

            mp[i] += 1;
        }

    }

    if(num > 1) mp[num]++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
       int n;
       cin >> n;
       map<int,int> mp;

       for(int i = 0; i < n; i++) {
        int curr;
        cin >> curr;

        f(curr, mp);
       }

       bool flag = false;

       for(auto it = mp.begin(); it != mp.end(); it++) {
        if(it->second % n != 0) {
            flag = true;
            break;
        }
       }

       if(flag) cout << "NO" << '\n';
       else cout << "YES" << '\n';


    }
    return 0;
}