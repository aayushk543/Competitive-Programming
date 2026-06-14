#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    long long k;

    cin >> n >> m >> k;
    
    vector<long long> a(n,0);
    vector<long long> b(m,0);
    
    for(int i = 0; i < n; i++)
    cin >> a[i];

    for(int i = 0; i < m; i++)
    cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    

    int i = 0, j = 0, ans = 0;

    while(i < n && j < m){
        if(abs(a[i] - b[j]) <= k){
        ans++;
        i++;
        j++;
    }
        else if(b[j] < a[i] - k){
        j++;   
    }
        else{
        i++;   
    }
    }

    cout << ans << '\n';

    return 0; 
}