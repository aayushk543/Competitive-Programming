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

        char c;
        cin >> c;

        string s;
        cin >> s;

        bool verify = true;

        int count = 0;
        vector<bool> v(n+1);

        for(int i = 0; i < n; i++) {
            if(s[i] == c) count++;
            v[i+1] = (s[i] == c);
        }

        if(count == n) cout << 0 << '\n';
        else {
            for(int i = 1; i <= n && verify; i++) {
                
                if(v[i] == true) {
                    int j = i;
                    int num = 1;

                    while(j <= n) {
                        
                    if(v[j] == false) break;

                    j = i * num;
                    num++;
                    if(j > n) {
                        cout << 1 << '\n' << i << '\n';
                        verify = false;
                        break;
                    } 
                }
                }
            }
            if(verify) {
                cout << 2 << '\n';
                cout << n << " " << n-1 << '\n';
            }
        }


    }
    return 0;
}