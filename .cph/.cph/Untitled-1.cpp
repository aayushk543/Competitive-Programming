#include<bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

bool check(int n) {
    vector<int> curr;

    while(n > 0) {

        curr.push_back(n % 10);
        n /= 10;

    }

    int i = 0, j = curr.size() - 1;

    while(i < j) {
        if(curr[i++] != curr[j--]) return false;
    }

    return true;
}

int main() {
    vector<int> arr;

    for(int i = 1; i <= 10000; i++) {
        if(check(i)) arr.push_back(i);
    }
    
    return 0;
}