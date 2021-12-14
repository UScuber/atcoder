#include <iostream>
#include <vector>

//11[ms]
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
template<class T, class U>
T &chmax(T &a, const U &b){ if(a < b) a = b; return a; }

const int dy[] = {-1,0,1,0}, dx[] = {0,-1,0,1};
int h,w;
char a[16][16];
int res = 0;
void dfs(int posy, int posx, vector<vector<int>> checked, int d, int &sy, int &sx){
  rep(i, 4){
    int y = posy + dy[i];
    int x = posx + dx[i];
    if(y < 0 || x < 0 || y >= h || x >= w) continue;
    if(y == sy && x == sx) chmax(res, d);
    if(a[y][x] == '#' || checked[y][x]) continue;
    checked[y][x] = 1;
    dfs(y, x, checked, d+1, sy, sx);
    checked[y][x] = 0;
  }
}
int main(){
  cin >> h >> w;
  rep(i, h) rep(j, w) cin >> a[i][j];
  vector<vector<int>> checked(h, vector<int>(w));
  int ans = 0;
  rep(i, h) rep(j, w){
    if(a[i][j] == '#') continue;
    checked[i][j] = 1;
    dfs(i, j, checked, 1, i, j);
    checked[i][j] = 0;
    chmax(ans, res);
    res = 0;
  }
  if(ans < 4) cout << "-1\n";
  else cout << ans << "\n";
}