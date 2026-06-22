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

       int count = 0;
       int maxi = 0;

       for(int i = 0; i < n; i++) {
        int m;
        cin >> m;
        if(m == 0) count++;
        else {
            count = 0;
        }
        maxi = max(maxi, count);
       }

       cout << maxi << '\n';


    }
    return 0;
}