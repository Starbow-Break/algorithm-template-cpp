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

class TrieNode {
    private:
    TrieNode* child[26]; //자식 노드
    bool isEnd; //문자열이 끝나는지 확인
    
    public:
    TrieNode() {
        for(int i = 0; i < 26; i++) child[i] = NULL;
        isEnd = false;
    }
    
    ~TrieNode() {
        for(int i = 0; i < 26; i++) {
            if(child[i] == NULL) continue;
            delete child[i];
        }
    }
    
    //문자열 삽입
    void insert(string s, int idx = 0) {
        if(idx == s.length()) {
            isEnd = true; return;
        }
        
        if(child[s[idx]-'a'] == NULL) {
            child[s[idx]-'a'] = new TrieNode();
        }
        
        child[s[idx]-'a']->insert(s, idx+1);
    }
    
    //호출된 노드의 서브 트리에 속하는 노드 전부 제거 (호출된 노드는 제외)
    void clear() {
        for(int i = 0; i < 26; i++) {
            if(child[i] == NULL) continue;
            delete child[i];
            child[i] = NULL;
        }
    }
};

class Trie {
    private:
    TrieNode root; //루트 노드
    
    public:
    Trie() {
        root = TrieNode();
    }
    
    //문자열 삽입
    void insert(string s) {
        root.insert(s);
    }
    
    //트라이 비우기
    void clear() {
        root.clear();
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    return 0;
}