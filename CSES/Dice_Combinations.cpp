#include<bits/stdc++.h>
using namespace std;

int f(int num) {
    if(num < 0) return 0;
    else if(nums == 0) return 1;

    return f(num-1) + f(num-2) + f(num-3) + f(num-4) + f(num-5) + f(num-6);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n; 


    return f(n);
}
