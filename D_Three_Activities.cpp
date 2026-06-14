#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        vector<long long> a(n,0);
        vector<long long> b(n,0);
        vector<long long> c(n,0);

        long long a1 = 0,a2 = 0,a3 = 0;
        int i1 = 0,i2 = 0,i3 = 0,i4 = 0,i5 = 0,i6 = 0,i7 = 0,i8 = 0,i9 = 0;

        long long b1 = 0, b2 = 0, b3 = 0, c1 = 0, c2 = 0, c3 = 0;

        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(a[i] > a1){
                a3 = a2;
                a2 = a1;
                a1 = a[i];

                i3 = i2;
                i2 = i1;
                i1 = i; 
            }
            else if(a[i] > a2){
                i3 = i2;
                i2 = i;

                a3 = a2;
                a2 = a[i];
            }
            else if(a[i] > a3){
                i3 = i;
                a3 = a[i];
            }

            
        }

        for(int i = 0; i < n; i++){
            cin >> b[i];
            if(b[i] > b1){
                b3 = b2;
                b2 = b1;
                b1 = b[i];

                i6 = i5;
                i5 = i4;
                i4 = i;
            }
            else if(b[i] > b2){
                i6 = i5;
                i5 = i;

                b3 = b2;
                b2 = b[i];
            }
            else if(b[i] > b3){
                i6 = i;
                b3 = b[i];
            }

            
        }

        for(int i = 0; i < n; i++){
            cin >> c[i];
            if(c[i] > c1){
                c3 = c2;
                c2 = c1;
                c1 = c[i];

                i9 = i8;
                i8 = i7;
                i7 = i;
                
            }
            else if(c[i] > c2){
                i9 = i8;
                i8 = i;

                c3 = c2;
                c2 = c[i];
            }
            else if(c[i] > c3){
                i9 = i;
                c3 = c[i];
            }
            
        }

        vector<int> ca = {i1,i2,i3};
        vector<int> cb = {i4,i5,i6};
        vector<int> cc = {i7,i8,i9};


        long long ans = 0;

        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                for(int k = 0; k < 3; k++){
                    if(ca[i] == cb[j] ||  cb[j] == cc[k] || cc[k] == ca[i]) continue;

                    ans = max(ans, a[ca[i]] + b[cb[j]] + c[cc[k]]);
                }
            }
        }

        cout << ans << '\n';

    }
    return 0;
}