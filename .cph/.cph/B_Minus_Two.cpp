#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
#include <set>
#include <map>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        int odd = 0;
        int even_4 = 0;
        int even_2 = 0;

        for(int i = 0; i < n; i++) {
            long long num;
            cin >> num;
            
            if(num % 2 == 0) {
                if(num % 4 == 0) even_4++;
                else even_2++;
            }
            else odd++;
        }

        cout << max(odd, max(even_2, even_4)) << '\n';


    }
    return 0;
}