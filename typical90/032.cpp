#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int inf = 1000000000;

//54[ms]
int main(){
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(n));
  vector<vector<int>> b(n, vector<int>(n));
  for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> a[i][j];
  int m; cin >> m;
  for(int i = 0; i < m; i++){
    int x,y;
    cin >> x >> y;
    x--; y--;
    b[x][y] = 1;
    b[y][x] = 1;
  }
  vector<int> v(n);
  for(int i = 0; i < n; i++) v[i] = i;
  int ans = inf;
  do {
    bool ok = true;
    int cost = 0;
    for(int i = 0; i < n; i++){
      if(i){
        if(b[v[i - 1]][v[i]]) ok = false;
      }
      cost += a[v[i]][i];
    }
    if(ok) ans = min(ans, cost);
  } while(next_permutation(v.begin(), v.end()));
  if(ans == inf) cout << "-1\n";
  else cout << ans << "\n";
}