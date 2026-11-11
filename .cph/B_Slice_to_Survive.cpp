#include<bits/stdc++.h>
using namespace std;

int solve(int n, int m, int a, int b) {
    if(a == 1 )
    
    a = min(a, n - a) + 1;

    int count = 1;

    int maxi = 0;
    int count1 = 0;

    //cout << a << '\n';

    for(int i = 0; i <= 31; i++) {

        if(a & (1 << i)) {
            maxi = i;
            count1++;
        }
    }

    //cout << maxi << " " << count1 << '\n';

    if(maxi > 0) count += maxi + (count1 > 1);

    maxi = 0;
    count1 = 0;

    for(int i = 0; i <= 31; i++) {

        if(m & (1 << i)) {
            maxi = i;
            count1++;
        }
    }

    if(maxi > 0) count += maxi + (count1 > 1);

    //cout << count << '\n';
    
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        long long n,m,a,b;
        cin >> n >> m >> a >> b;

        cout << min(solve(n,m,a,b), solve(m,n,b,a)) << '\n';
    }
    
    return 0;
}