#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
#include <set>
#include <map>
#include <stack>
using namespace std;

string a,b,c;

int f(int i1, int i2, int i3) {
    int n = a.length();
    int m = b.length();

    int count = 0;

    if(i1 == n) {
        while(i2 < m) {
            if(b[i2] != c[i3]) count++;
            i2++;
            i3++;
        }

        return count;
    }

    if(i2 == m) {
        while(i1 < m) {
            if(a[i1] != c[i3]) count++;
            i1++;
            i3++;
        }

        return count;
    }

    if(a[i1] != c[i3]) count++;

    int one = count + f(i1 + 1, i2, i3 + 1);

    count = 0;

    if(b[i2] != c[i3]) count++;

    int two = count + f(i1, i2 + 1, i3 + 1);

    return min(one, two);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        
        cin >> a >> b >> c;

        cout << f(0,0,0) << '\n';
    }
    return 0;
}