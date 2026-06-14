#include <iostream>
#include <iostream>  
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <bitset>
#include <string>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int a,b,c,d;
        cin >> a >> b >> c >> d;

        if(a == b && b == c && c == d){
            cout << "YES" << '\n';
        }
        else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}
