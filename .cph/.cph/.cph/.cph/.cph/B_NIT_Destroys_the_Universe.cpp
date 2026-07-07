#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
       int n;
       cin >> n;

       bool t1 = true;
       int count = 0;

       for(int i = 1; i <= n; i++){
        long long m;
        cin >> m;

        if(m == 0) t1 = true;
        else if(m != 0 && t1) {
            count++;
            t1 = false;
        }
        
       }

       cout << min(count,2) << '\n';
    }
    return 0;
}