#include<bits/stdc++.h>
using namespace std;

int dist(int x1, int x2, int y1, int y2){
    return (pow(x1-x2,2) + pow(y1-y2,2));
}

int main() {
    int n;
    vector<long long> arr(2*n,0);
    for(int i = 0; i < 2*n; i++){
        cin >> arr[i];
    }


    return 0;
}