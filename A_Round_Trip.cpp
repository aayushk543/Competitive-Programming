#include <iostream>
#include <iostream>  
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <bitset>
#include <string>
#include <numeric>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long r,x,d;
        int n;

        cin >> r >> x >> d >> n;

        string s;
        cin >> s;
        long long count = 0;

        for(int i = 0; i < s.size(); i++){
            if (s[i] == '2' && r < x){
                r = max(r-d,0LL);
                count++;
            }
            else if(s[i] == '1') {
                count++;
                r = max(r-d,0LL);
            }
        }
        cout << count << '\n';
    }

    return 0;
}
