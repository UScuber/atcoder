#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

#define rep(i, n) for(int i = 0; i < n; i++)
#define vi vector<int>
#define pii pair<int, int>
using namespace std;

const int inf = 1000000000;
void dijkstra(vector<vector<pii>> &root, int s, vi &dist){
  priority_queue<pii, vector<pii>, greater<pii>> que;
  que.push({0, s});
  dist[s] = 0;

  while(!que.empty()){
    int pos, score;
    tie(score, pos) = que.top();
    que.pop();
    if(dist[pos] < score) continue;
    for(auto x : root[pos]){
      int v = score + x.second;
      if(dist[x.first] <= v) continue;
      que.push({v, x.first});
      dist[x.first] = v;
    }
  }
}

int main(){
  int n,m;
  cin >> n >> m;
  vector<vector<pii>> root(n);
  rep(i, m){
    int a,b,c;
    cin >> a >> b >> c;
    a--; b--;
    root[a].push_back({b, c});
    root[b].push_back({a, c});
  }
  
  vi dist(n, inf), dist2(n, inf);
  dijkstra(root, 0, dist);
  dijkstra(root, n - 1, dist2);
  rep(i, n){
    cout << dist[i] + dist2[i] << "\n";
  }
}