#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;

        cin >> n;
        int n1 = 0;
        int n2 = 0;

        for(int i = 0; i < n; i++){
            int m;
            cin >> m;
            if(m) n1++;
        }
        for(int i = 0; i < n; i++){
            int m;
            cin >> m;
            if(m) n2++;
        }
        if(n1 == n && n2 == n){
            n = 2;
        }
        if(n % 2 == 0){
            if(n1 % 2 == 1 && n2 % 2 == 1) cout << "Tie" << '\n';
            else if(n1 % 2 == 1) cout << "Ajisai" << '\n';
            else if(n2 % 2 == 1) cout << "Mai" << '\n';
            else cout << "Tie" << '\n';
        }
        else{
            if(n1 % 2 == 1 && n2 % 2 == 1) cout << "Tie" << '\n';
        }
    }
    return 0;
}
