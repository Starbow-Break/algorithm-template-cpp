#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <map>
#include <cmath>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef __int128_t int128;

ll modPow(ll a, ll e, ll n) {
    int128 ret = 1, w = a;
    
    while(e > 0) {
        if(e%2) {
            ret *= w; ret %= n;
        }
        
        e /= 2;
        w *= w; w %= n;
    }
    
    return ret;
}

bool millerRabin(ll n) {
    ll a[14] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43};
    
    for(int i = 0; i < 14; i++) {
        if(n <= a[i]) break;
        
        ll _n = n-1;
        
        bool check = false;
        
        while(_n%2 == 0) {
            _n /= 2;
            if(modPow(a[i], _n, n) == n-1) check = true;
        }
        
        if(modPow(a[i], _n, n) == 1) check = true;
        
        if(!check) return false;
    }
    
    return true;
}

//x^2+c
ll f(ll x, ll c, ll n) {
    return ((int128)x*x+c)%n;
}

ll gcd(ll a, ll b) {
    if(a < b) swap(a, b);
    if(b == 0) return a;
    return gcd(b, a%b);
}

void pollardRho(ll n, vector<ll> &pf) {
    if(n == 1) return;
    
    if(n%2 == 0) {
        while(n%2 == 0) {
            pf.push_back(2);
            n /= 2;
        }
        
        pollardRho(n, pf);
        return;
    }
    
    if(millerRabin(n)) {
        pf.push_back(n); return;
    }
    
    ll x = 1, y = 1, g = 1, c = 1;
    
    while(g == 1) {
        x = f(x, c, n);
        y = f(y, c, n);
        y = f(y, c, n);
        
        g = gcd(abs(y-x), n);
        
        //g가 n이면 실패, c값을 바꿔서 다시 실시한다.
        if(g == n) {
            g = 1; x = 1; y = 1;
            c++;
        }
    }
    
    pollardRho(g, pf);
    pollardRho(n/g, pf);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    vector<ll> pf;
    ll n; cin >> n;
    
    pollardRho(n, pf)

    return 0;
}