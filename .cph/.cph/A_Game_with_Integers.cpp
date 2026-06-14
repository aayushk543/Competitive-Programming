#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        bool c1 = false;

        if(n % 3 == 0){
            c1 = true;
        }

        if(c1) cout << "Second" << '\n';
        else cout << "First" << '\n';
    }
    return 0;
}