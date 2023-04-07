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
#define MAX_N 1'000

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

vector<int> graph[MAX_N+1];

bool visited[MAX_N+1]; int conn[MAX_N+1];
bool dfs(int cur) {
    for(auto &next: graph[cur]) {
        if(visited[next]) continue;
        
        visited[next] = true;
        
        if(conn[next] == 0 || dfs(conn[next])) {
            conn[next] = cur;
            return true;
        }
    }
    
    return false;
}

int binaryMatching(int n) {
    int ret = 0;
    fill(conn+1, conn+MAX_N+1, 0);
    
    for(int i = 1; i <= n; i++) {
        fill(visited+1, visited+MAX_N+1, false);
        ret += dfs(i);
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    

    return 0;
}