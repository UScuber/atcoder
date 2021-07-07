#include <iostream>
#include <vector>
using namespace std;

//81[ms]
void dfs(vector<vector<int>> &root, int s, vector<int> &dist){
  for(int x : root[s]){
    if(dist[x] == -1){
      dist[x] = dist[s] + 1;
      dfs(root, x, dist);
    }
  }
}
int main(){
  int n;
  cin >> n;
  vector<vector<int>> root(n);
  for(int i = 0; i < n - 1; i++){
    int a,b;
    cin >> a >> b;
    a--; b--;
    root[a].push_back(b);
    root[b].push_back(a);
  }
  vector<int> dist(n, -1);
  dist[0] = 0;
  dfs(root, 0, dist);
  
  //頂点0から一番遠い(dist[i]が最も大きい)ところを探す
  int mx = 0, mx_pos;
  for(int i = 0; i < n; i++){
    if(mx < dist[i]){
      mx = dist[i];
      mx_pos = i;
    }
  }

  dist = vector<int>(n, -1);
  dist[mx_pos] = 0;
  dfs(root, mx_pos, dist);

  //mx_posから一番遠い距離を求める
  int ans = 0;
  for(int i = 0; i < n; i++){
    ans = max(ans, dist[i]);
  }
  cout << ans + 1 << endl;
}