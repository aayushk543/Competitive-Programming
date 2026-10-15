#include<bits/stdc++.h>
using namespace std;

long long factorial(int n) {

    long long ans = 1;

    while(n > 0) {
        ans *= n;
        n -= 1;
    }

    //cout << ans << '\n';

    return ans;
}

long long f1(int n) {

    long long ans = 1;

    for(int i = 1; i <= (n / 4); i += 2) ans *= (n - i);

    return ans;
}


long long calculate(int n) {

    long long ans = (f1(n)) / (factorial(n / 4));

    for(int i = 1; i <= (n / 4); i++) ans *= 2;

    return ans;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if(1) {
       int n;
       cin >> n;

       vector<int> edges(n);

       int ans = 1;

       for(int i = 1; i <= (n / 3); i++) {
        int a,b,c;

        cin >> a >> b >> c;

        int num1 = 0, num2 = 0, num3 = 0;

        if(a >= b && b >= c) {
            num1 = a;
            num2 = b;
            num3 = c;
            //ans += (a + b);
        }
        else if(b >= a && a >= c) {
            num1 = b;
            num2 = a;
            num3 = c;
            //ans += (a + b);
        }
        else if(a >= c && c >= b) {
            num1 = a;
            num2 = c;
            num3 = b;
            //ans += (a + c);
        }
        else if(b >= c && c >= a) {
            num1 = b;
            num2 = c;
            num3 = a;
            //ans += (b + c);
        }
        else if(c >= a && a >= b) {
            num1 = c;
            num2 = a;
            num3 = b;
            //ans += (c + a);
        }
        else if(c >= b && b >= a) {
            num1 = c;
            num2 = b;
            num3 = a;
            //ans += (c + b);
        }

        if(num1 == num2) {
            if(num2 == num3) ans *= 3;
            else {
                ans *= 1;
            }
        }
        else {
            if(num2 == num3) ans *= 2;
            else ans *= 1;
        }
       }

       n /= 3;

       long long f = (calculate(n)) % 998244353;

       cout << (f * ans) % 998244353 << '\n';


    }
    return 0;
}