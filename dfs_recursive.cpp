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
#define MAX_V 100'000 //입력으로 주어지는 정점의 최대 갯수

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

//탐색하고자 하는 그래프
vector<int> graph[MAX_V+1];

//DFS
bool visited[MAX_V+1] = {false, };

void dfs(int cur) {
    visited[cur] = true;
    
    for(auto &next: graph[cur]) {
        if(!visited[next]) {
            //다음 노드 탐색전에 수행할 내용
            
            dfs(next);
            
            //다음 노드 탐색 완료 후 수행할 내용
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    
    
    return 0;
}