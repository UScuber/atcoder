#include <iostream>
#include <vector>
#include <queue>

//107[ms]
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  vector<vector<int>> root(n + m);
  rep(i, m){
    int k; cin >> k;
    rep(j, k){
      int v; cin >> v;
      v--;
      root[v].push_back(n + i);
      root[n + i].push_back(v);
    }
  }
  vector<int> checked(n + m, -2);
  queue<int> que;
  que.push(0);
  checked[0] = 0;
  while(!que.empty()){
    int pos = que.front();
    que.pop();
    for(int &x : root[pos]){
      if(checked[x] != -2) continue;
      checked[x] = checked[pos] + 1;
      que.push(x);
    }
  }
  rep(i, n) cout << checked[i] / 2 << "\n";
}