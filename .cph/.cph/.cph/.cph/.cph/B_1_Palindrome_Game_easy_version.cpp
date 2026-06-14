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

        for(int i = 0; i < s.length(); i++){
            n_zero += '1' - s[i];
        }
        if(n_zero == 1) cout << "BOB" << '\n';
        else if(n_zero % 2 == 1){
            cout << "ALICE" << '\n';
        }
        else cout << "BOB" << '\n';
    }
    return 0;
}