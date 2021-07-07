#include <iostream>
#include <vector>
using namespace std;

//231[ms]
struct UnionFind {
  vector<int> d;
  UnionFind(int n): d(n,-1) {}
  int root(int x) {
    if(d[x] < 0) return x;
    return d[x] = root(d[x]);
  }
  bool unite(int x, int y){
    x = root(x);
    y = root(y);
    if(x == y) return false;
    if(d[x] > d[y]) swap(x,y);
    d[x] += d[y];
    d[y] = x;
    return true;
  }
  bool same(int x, int y){
    return root(x) == root(y);
  }
  int size(int x){
    return -d[root(x)];
  }
};

int dy[] = {1,-1,0,0};
int dx[] = {0,0,1,-1};
int main(){
  int h,w,q;
  cin >> h >> w >> q;
  UnionFind tree(h * w);
  vector<vector<bool>> cnt(h, vector<bool>(w));
  for(int i = 0; i < q; i++){
    int t; cin >> t;
    if(t & 1){
      int r,c;
      cin >> r >> c;
      r--; c--;
      cnt[r][c] = true;
      for(int j = 0; j < 4; j++){
        int y = r + dy[j];
        int x = c + dx[j];
        if(y < 0 || x < 0 || y >= h || x >= w || !cnt[y][x]) continue;
        tree.unite(r*w + c, y*w + x);
      }
    }else{
      int a,b,c,d;
      cin >> a >> b >> c >> d;
      a--; b--; c--; d--;
      if(a*w + b == c*w + d){
        if(cnt[a][b]) cout << "Yes\n";
        else cout << "No\n";
      }else{
        if(tree.same(a*w + b, c*w + d)) cout << "Yes\n";
        else cout << "No\n";
      }
    }
  }
}