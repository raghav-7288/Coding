#include <bits/stdc++.h>
using namespace std;
double myPow(double x, int n) {
        if(!n) return 1;
        if(n>0){
            double a=myPow(x,n/2);
            if(n&1) return x*a*a;
            return a*a;
        }else{
            n=abs(n);
            double a=myPow(x,n/2);
            if(n&1) return 1/(x*a*a);
            return 1/(a*a);
        }
    }
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    double x;
    int n;
    cin >> x >> n;
    // cout << INT_MAX;
    // vector<double> dp(n, -1);
    cout << myPow(x, n) << endl;
    // for (auto x : dp)
    // {
    //     cout << x << " ";
    // }
    return 0;
}