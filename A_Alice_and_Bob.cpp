#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        long long a;
        int n;

        cin >> n >> a;

        long long sum = 0;
        int up = 0;
        int down = 0;

        for(int i = 0; i < n; i++){
            long long m;
            cin >> m;
            if(m > a){
                up++;
            }
            else if(m < a)down++;
        }

        long long ans = 0;

        if(up < down){
            ans = a - 1;
        }
        
        else ans = a + 1;

        

        cout << ans << '\n';
    }
    return 0;
}