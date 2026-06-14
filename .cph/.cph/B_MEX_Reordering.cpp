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

        
        
        int count0 = 0;
        int count1 = 0;

        for(int i = 0; i < n; i++){
            int m;
            cin >> m;
             
            if(m == 0) count0++;
            else if(m == 1) count1++;
        }

        if(count0 == 1 && count1 == 0){
            cout << "YES" << '\n';
        }
        else if(count0 == 0 || count1 == 0){
            cout << "NO" << '\n';
        }
        else {
            cout << "YES" << '\n';
        }
        
    }
    return 0;
}