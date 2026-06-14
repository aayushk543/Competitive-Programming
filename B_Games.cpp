
#include <iostream>
#include <iostream>  
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n,m;
        cin >> n >> m;
        for(int i = 0; i < n+m; i++){
            int g;
            cin >> g; 
        }

        int ans = 2*min(n,m) - 1;

        if (n > m){
            ans = ans + 1;
        }

        cout << ans << '\n';

    }
    return 0;
}