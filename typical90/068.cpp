#include <iostream>
#include <vector>
#define rep(i, n) for(int i = 0; i < n; i++)
using ll = long long;
using namespace std;

//165[ms]
struct UnionFindW {
  vector<int> par, rank;
  vector<ll> diff_weight;
  
  UnionFindW(int n = 1, ll sum_unity = 0) : par(n), rank(n), diff_weight(n){
    for(int i = 0; i < n; i++) par[i] = i, rank[i] = 0, diff_weight[i] = sum_unity;
  }
  int root(int x){
    if(par[x] == x){
      return x;
    }else{
      int r = root(par[x]);
      diff_weight[x] += diff_weight[par[x]];
      return par[x] = r;
    }
  }
  ll weight(int x){
    root(x);
    return diff_weight[x];
  }
  bool same(int x, int y){
    return root(x) == root(y);
  }
  bool merge(int x, int y, ll w){
    w += weight(x); w -= weight(y);
    x = root(x); y = root(y);
    if(x == y) return false;
    if(rank[x] < rank[y]) swap(x, y), w = -w;
    if(rank[x] == rank[y]) ++rank[x];
    par[y] = x;
    diff_weight[y] = w;
    return true;
  }
  ll diff(int x, int y){
    return weight(y) - weight(x);
  }
};
int main(){
  int n,q;
  cin >> n >> q;
  UnionFindW tree(n);
  rep(i, q){
    int t,x,y; ll v;
    cin >> t >> x >> y >> v;
    x--; y--;
    if(t == 0){
      if(x & 1) tree.merge(x, y, v);
      else tree.merge(x, y, -v);
    }else{
      if(!tree.same(x, y)) cout << "Ambiguous\n";
      else{
        ll d = tree.diff(x, y);
        if(x & 1) d -= v;
        else d += v;
        if(y & 1) d = -d;
        cout << d << "\n";
      } 
    }
  }
}