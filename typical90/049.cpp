#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < n; i++)
using ll = long long;
#define all(a) (a).begin(), (a).end()
using namespace std;

//89[ms]
struct edge{
  int u, v;
  ll cost;
  bool friend operator<(const edge &e1, const edge &e2){
    return e1.cost < e2.cost;
  }
};
struct UnionFind {
  vector<int> d;
  UnionFind(int n) : d(n, -1){}
  int root(int x){
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
int n,m;
ll kruskal(vector<edge> &es){
  ll res = 0;
  sort(all(es));
  UnionFind tree(n + 1);
  for(edge &e : es){
    if(!tree.same(e.u, e.v)){
      tree.unite(e.u, e.v);
      res += e.cost;
    }
  }
  if(tree.size(0) == n + 1) return res;
  else return -1;
}
int main(){
  cin >> n >> m;
  vector<edge> v(m);
  rep(i, m){
    int c,l,r;
    cin >> c >> l >> r;
    v[i] = {l-1, r, c};
  }
  ll ans = kruskal(v);
  cout << ans << "\n";
}