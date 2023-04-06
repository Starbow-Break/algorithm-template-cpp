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

//실패함수 구하기
vector<int> getFail(string &s) {
    vector<int> fail(s.length());
    
    fail[0] = 0;
    
    for(int i = 1; i < s.length(); i++) {
        int j = fail[i-1];
        while(j > 0 && s[j] != s[i]) j = fail[j-1];
        
        if(s[j] == s[i]) j++;
        fail[i] = j;
    }
    
    return fail;
}

//s가 t를 부분 문자열로 갖는지를 kmp로 확인
void kmp(string &s, string &t) {
    vector<int> fail = getFail(t);
    
    for(int i = 0, j = 0; i < s.length(); i++) {
        while(j > 0 && s[i] != t[j]) j = fail[j-1];
        
        if(s[i] == t[j]) j++;
        
        if(j == t.length()) {
            //t가 s의 부분문자열임을 확인할 수 있음, t == s[i-t.length()+1, i]
            //이 때, 수행해야하는 작업을 채워준다.
            j = fail[j-1];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    
    
    return 0;
}