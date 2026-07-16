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

        int prev = -1;

        vector<int> curr(n + 1, 0);
        int count_0 = 0;

        for(int i = 1; i <= n; i++) {
            cin >> curr[i];
            if(curr[i] == 0) count_0++;
        }  
        
        bool check = true;

        for(int i = 1; i < n; i++) {
            prev = curr[i];
            if(prev == 0 && curr[i + 1] == 1) {
                int j = 1;
                for(; j <= i; j++) cout << j << " ";
                cout << n + 1 << " ";
                for(j = i + 1; j <= n; j++) cout << j << " ";
                cout << '\n';
                check = false;
                break;
            }
            
        }

        if(check){
            if(curr[1] == 1) {
                cout << n + 1 << " ";
                for(int i = 1; i <= n; i++) cout << i << " ";
                cout << '\n';
                check = false;
            }
        }

        if(count_0 == n) {
            for(int i = 1; i <= n + 1; i++) cout << i << " ";
            cout << '\n';
        }
        else if(check) cout << -1 << '\n';
    }
    return 0;
}