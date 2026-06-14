#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        long long x;
        cin >> n >> x;

        int maxi = 0;

        int a,b,c;
        int a2,b2,c2;

        int maxi2 = 0;

        for(int i = 0; i < n; i++){
            
            cin >> a >> b >> c;

            if(a*b - c > maxi){
                a2 = a;
                b2 = b;
                c2 = c;
            }

            maxi2 = max(maxi2, a*(b-1));

            maxi = max(maxi,a*b - c);

        }

        maxi2 = max(0, maxi2);

        if(maxi <= 0) cout << -1 << '\n';
        else cout << (ceil)(double(x-maxi2)/maxi) << '\n';
    }
    return 0;
}