#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        long long n;
        cin >> n;

        if(n % 3 == 0 || n % 3 == 2){
            cout << "NO" << '\n';
        }
        else{
            cout << "YES" << '\n';
        }
        
    }
    return 0;
}