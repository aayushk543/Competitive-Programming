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

        char a;
        cin >> a;

        string s;
        cin >> s;

        int ans = 0;
        int count = 0;
        bool p = false;

        for(int i = 0; i < 2*n; i++){
            int j = i % n;

            if(s[j] == 'g'){
                ans = max(ans, count);
                count = 0;
                p = false;
            }
            else if(!p && s[j] == a){
                count++;
                p = true;
            }
            else if(p) count++;

        }

        if(a == 'g') ans = 0;

        cout << ans << '\n';
    }
    return 0;
}