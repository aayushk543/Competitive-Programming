#include <iostream>  
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin >> n >> k;

        string s;
        cin >> s;

        int ans = s.length();

        for(int i = 0; i < n; i++){
            if(s[i] == '1'){
                for(int j = 1; j <= k; j++){
                    if(s[i+j] == '1' || i + j >= n) {
                        break;
                    }
                    else if(j == k){
                        ans = ans - k;
                        i = i + j;
                    }
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}