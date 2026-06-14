#include <iostream>
using namespace std;

bool possible(long long x, long long y, long long z) {
    for (int i = 0; i < 60; i++) { // handle up to 2^60 if needed
        int xi = (x >> i) & 1;
        int yi = (y >> i) & 1;
        int zi = (z >> i) & 1;

        if (!(
            (xi == 0 && yi == 0 && zi == 0) ||
            (xi == 0 && yi == 1 && zi == 1) ||
            (xi == 1 && yi == 0 && zi == 1) ||
            (xi == 1 && yi == 1 && zi == 1)
        )) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long x, y, z;
        cin >> x >> y >> z;
        cout << (possible(x, y, z) ? "YES\n" : "NO\n");
    }

    return 0;
}
