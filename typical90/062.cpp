#include <iostream>
#include <vector>
#include <queue>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

//84[ms]
int main(){
  int n;
  cin >> n;
  vector<vector<int>> root(n);
  queue<int> que;
  vector<int> checked(n, -1), ans;
  rep(i, n){
    int a,b;
    cin >> a >> b;
    a--; b--;
    root[a].push_back(i);
    root[b].push_back(i);
    if(i == a || i == b){
      que.push(i);
      checked[i] = 0;
    }
  }
  while(!que.empty()){
    int pos = que.front();
    que.pop();
    ans.push_back(pos);
    for(int x : root[pos]){
      if(checked[x] != -1) continue;
      checked[x] = 0;
      que.push(x);
    }
  }
  if((int)ans.size() != n) cout << "-1\n";
  else for(int i = n - 1; i >= 0; i--) cout << ans[i] + 1 << "\n";
}