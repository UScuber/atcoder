#include <iostream>
#include <vector>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

//742[ms]
template<class T> struct rangeUpdateQuery{
  public:
  rangeUpdateQuery(int x){
    while(x > n) n *= 2;
    d.resize(2*n - 1, inf);
    lazy.resize(2*n - 1, inf);
  }
  void set(int i, T x){ d[i + n - 1] = x; }
  void build(){
    for(int k = n - 2; k >= 0; k--)
      d[k] = max(d[k * 2 + 1], d[k * 2 + 2]);
  }
  void eval(int k){
    if(lazy[k] == inf) return;
    if(k < n - 1){
      lazy[k * 2 + 1] = lazy[k];
      lazy[k * 2 + 2] = lazy[k];
    }
    d[k] = lazy[k];
    lazy[k] = inf;
  }
  void update(int a, int b, T x){ update(a, b, x, 0, 0, n); }
  T query(int a, int b){ return query_sub(a, b, 0, 0, n); }
  private:
  const T inf = numeric_limits<T>::max();
  int n = 1;
  vector<T> d, lazy;
  void update(int a, int b, T x, int k, int l, int r){
    eval(k);
    if(a <= l && r <= b){
      lazy[k] = x;
      eval(k);
    }else if(a < r && l < b){
      update(a, b, x, k*2 + 1, l, (l+r)/2);
      update(a, b, x, k*2 + 2, (l+r)/2, r);
      d[k] = max(d[k * 2 + 1], d[k * 2 + 2]);
    }
  }
  T query_sub(int a, int b, int k, int l, int r){
    eval(k);
    if(r <= a || b <= l) return 0;
    if(a <= l && r <= b) return d[k];
    T vlef = query_sub(a, b, k*2 + 1, l, (r+l)/2);
    T vrig = query_sub(a, b, k*2 + 2, (r+l)/2, r);
    return max(vlef, vrig);
  }
};
int main(){
  int w,n;
  cin >> w >> n;
  rangeUpdateQuery<int> seg(w);
  for(int i = 0; i < w; i++) seg.set(i, 0);
  seg.build();
  for(int i = 0; i < n; i++){
    int l,r;
    cin >> l >> r;
    int num = seg.query(l - 1, r);
    cout << num + 1 << "\n";
    seg.update(l - 1, r, num + 1);
  }
}