#include<bits/stdc++.h>
using namespace std;

int mod = 998244353;

long long factorial(int n) {

    long long ans = 1;

    while(n > 0) {
        ans = (ans*n) % mod;
        n -= 1;
    }

    //cout << ans << '\n';

    return ans;
}

long long f1(int n) {

    long long ans = 1;

    for(int i = 1; i <= (n / 4); i += 2) ans = (ans * (n - i)) % mod;

    return ans;
}


long long calculate(int n) {

    if(n < 100) return (factorial(n) / (factorial(n/2) * factorial(n/2)));

    long long ans = (f1(n)) / (factorial(n / 4));

    for(int i = 1; i <= (n / 4); i++) ans = (ans*2) % mod;

    return ans;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if(1) {
       int n;
       cin >> n;

       vector<int> edges(n);

       long long ans = 1;

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
            if(num2 == num3) ans = (ans*3) % mod;
            else {
                ans *= 1;
            }
        }
        else {
            if(num2 == num3) ans = (ans*2) % mod;
            else ans *= 1;
        }
       }

       n /= 3;

       long long f = (calculate(n)) % 998244353;

       cout << (f * ans) % 998244353 << '\n';


    }
    return 0;
}