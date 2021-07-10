#include <iostream>
#include <vector>
#include <tuple>
using ll = long long;
using namespace std;
const ll inf = 1000000000000000000;

//350[ms]
template<class T> struct segmentTree{
  public:
  segmentTree(int x){
    while(x > n) n *= 2;
    d.resize(2*n - 1, -inf);
  }
  void update(int k, T a){
    k += n - 1;
    d[k] = a;
    while(k > 0){
      k = (k - 1) / 2;
      d[k] = max(d[k * 2 + 1], d[k * 2 + 2]);
    }
  }
  void set(int i, T x){ d[i + n - 1] = x; }
  void build(){
    for(int i = n - 2; i >= 0; i--)
      d[i] = max(d[i*2 + 1], d[i*2 + 2]);
  }
  T query(int a, int b){
    return query_sub(a, b, 0, 0, n);
  }
  
  T operator[](const int &i){ return d[i + n - 1]; }
  int n = 1;
  vector<T> d;
  T query_sub(int a, int b, int k, int l, int r){
    if(r <= a || b <= l) return -inf;
    if(a <= l && r <= b) return d[k];
    T vlef = query_sub(a, b, k*2 + 1, l, (r+l)/2);
    T vrig = query_sub(a, b, k*2 + 2, (r+l)/2, r);
    return max(vlef, vrig);
  }
};
int main(){
  int w,n;
  cin >> w >> n;
  vector<ll> L(n), R(n), C(n);
  for(int i = 0; i < n; i++) cin >> L[i] >> R[i] >> C[i];

  segmentTree<ll> cur(w + 1), next(w + 1);
  cur.update(0, 0);
  for(int i = 0; i < n; i++){
    ll l = L[i], r = R[i], c = C[i];
    for(int j = 0; j <= w; j++){
      next.set(j, cur[j]);
      ll val = cur.query(max(0LL, j-r), max(0LL, j-l+1));
      if(val != -inf) next.set(j, max(cur[j], val + c));
    }
    next.build();
    cur = next;
  }
  if(cur[w] == -inf) cout << "-1\n";
  else cout << cur[w] << "\n";
}