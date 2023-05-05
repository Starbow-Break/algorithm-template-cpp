#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <map>
#include <iomanip>
#include <complex>
#define x first
#define y second

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef __int128_t int128;

//a^e % mod
ll modPow(ll a, ll e, ll mod) {
    ll ret = 1, w = a;
    
    while(e > 0) {
        if(e%2) {
            ret *= w; ret %= mod;
        }
        w *= w; w %= mod;
        e /= 2;
    }
    
    return ret;
}

//mod에 대해서 v^-1
//NTT를 사용할 때는 mod가 소수임이 보장된다.
ll inverse(ll v, ll mod) {
    return modPow(v, mod-2, mod);
}

//NTT
//mod = 998'244'353, pri = 3, maxSize = 1 << 23
//mod = 2'281'701'377, pri = 3, maxSize = 1 << 27
//mod = 2'483'027'969, pri = 3, maxSize = 1 << 26
//mod = 2'113'929'217, pri = 5, maxSize = 1 << 25
//mod = 104'857'601, pri = 3, maxSize = 1 << 22
//mod = 1'092'616'193, pri = 3, maxSize = 1 << 21
template<int mod, int pri>
void ntt(vector<ll> &A, bool inv = false) {
    int sz = A.size();
    
    //NTT를 수행할 수 있도록 적절하게 정렬
    for(int i = 0; i < sz; i++) {
        int j = 0;
        for(int t = 1; t < sz; t <<= 1) {
            j <<= 1; j |= ((i & t) != 0);
        }
        
        if(i < j) swap(A[i], A[j]);
    }
    
    //NTT 실시
    for(int len = 2; len <= sz; len <<= 1) {
        ll w = modPow(pri, (mod-1)/len, mod);
        if(inv) w = inverse(w, mod);
        
        for(int i = 0; i < sz; i += len) {
            ll e = 1;
            for(int j = 0; j < len/2; j++) {
                ll odd = A[i+j+len/2], even = A[i+j];
                A[i+j] = (even+e*odd)%mod;
                A[i+j+len/2] = (even+(mod-e)*odd)%mod;
                e *= w; e %= mod;
            }
        }
    }
    
    if(inv) {
        for(int i = 0; i < sz; i++) {
            A[i] *= inverse(sz, mod); A[i] %= mod;
        }
    }
}

//두 다항식의 곱셈
//단, 결과로 각 계수들이 원래 계수를 mod로 나눌 때 나머지로 나온다.
template<int mod, int pri>
vector<ll> polyMultiple(vector<ll> A, vector<ll> B) {
    int sz = 1;
    while(sz < A.size() || sz < B.size()) sz <<= 1;
    sz <<= 1;
    
    A.resize(sz); B.resize(sz);
    vector<ll> ret(sz);
    
    ntt<mod, pri>(A); ntt<mod, pri>(B); //A, B를 NTT
    for(int i = 0; i < sz; i++) {
        ret[i] = (A[i]*B[i])%mod; //결과의 NTT를 구함
    }

    ntt<mod, pri>(ret, true); //INTT를 사용해서 실제 결과값 구함
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M; cin >> N >> M;
    vector<ll> A, B;
    
    for(int i = 0; i < N; i++) {
        int v; cin >> v;
        A.push_back(v);
    }
        
    for(int i = 0; i < M; i++) {
        int v; cin >> v;
        B.push_back(v);
    }
    
    vector<ll> AB = polyMultiple<1'092'616'193, 3>(A, B);
    
    return 0;
}