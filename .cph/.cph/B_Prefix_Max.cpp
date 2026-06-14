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
        
        int maxi = 0;
        
        

        for(int i = 0; i < n; i++){
            int m;
            cin >> m;

            maxi = max(maxi,m);
            
        }

        

        
        cout << maxi * n << '\n';
    }
    return 0;
}