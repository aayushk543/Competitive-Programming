
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
        int n;
        cin >> n;

        if(n % 3 == 0){
            cout << 0 << '\n';
        }{

        int m = 3 - n % 3;

        cout << m << '\n';}
    }
    return 0;
}