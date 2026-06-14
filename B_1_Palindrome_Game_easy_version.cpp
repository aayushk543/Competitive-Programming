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

        int n_zero = 0;

        for(int i = 0; i < n; i++){
            if(s[i] == '0') n_zero++;
        }
        
        if(n_zero % 2 == 1){
            n_zero -= 1;
            if(n_zero % 4 == 0) cout << "BOB" << '\n';
            else cout << "ALICE" << '\n';
        }
        else if(n_zero % 4 == 0) cout << "DRAW" << '\n';
        else cout << "BOB" << '\n';
    }
    return 0;
}