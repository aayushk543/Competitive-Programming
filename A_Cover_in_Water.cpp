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

        int e = 0;
        int count = 0;
        int ans = 0;

        for(int i = 0; i < n; i++){
            if(s[i] == '.'){
                e++;
                count++;
            }
            else count = 0;

            if(count == 3){
                ans = 2;
                break;
            }
        }

        if(ans == 0) cout << e << '\n';
        else cout << ans << '\n';
    }
    return 0;
}