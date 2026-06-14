#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n,m,d;

        cin >> n >> m >> d;

        cout << ceil((double)n/((d/m)+1)) << '\n';

    }
    return 0;
}