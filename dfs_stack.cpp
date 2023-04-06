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
int idx[MAX_V+1] = {0, };
stack<int> s;

void dfs(int start) {
    fill(idx, idx+MAX_V+1, -1);
    s.push(start);
    
    while(!s.empty()) {
        int cur = s.top();
        if(idx[cur] == -1) idx[cur] = 0; //아직 한번도 방문하지 않은 노드일 때
        else { //이미 방문한 노드일 때
            //graph[cur][idx[cur]]을 탐색하면서 얻은 정보를 사용하여 작업 시행
        }
        
        while(idx[cur] < graph[cur].size()) {
            int next = graph[cur][idx[cur]];
            
            if(!visited[next]) {
                //다음 노드 탐색 전 수행 내용
                s.push(next); break;
            }
            
            idx[cur]++;
        }
        
        //추가로 탐색할 다음 노드가 없으면 스택에서 제거해 준다
        if(idx[cur] == graph[cur].size()) s.pop();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    
    
    return 0;
}