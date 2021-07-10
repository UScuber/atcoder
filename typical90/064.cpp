#include <iostream>
#include <vector>
#define rep(i, n) for(int i = 0; i < n; i++)
using ll = long long;
using namespace std;

//249[ms]
int main(){
  int n,q;
  cin >> n >> q;
  int last = 0;
  ll ans = 0;
  vector<ll> b(n);
  for(int i = 0; i < n; i++){
    int a; cin >> a;
    if(i){
      b[i - 1] = a - last;
      ans += abs(b[i - 1]);
    }
    last = a;
  }
  for(int i = 0; i < q; i++){
    int l,r,v;
    cin >> l >> r >> v;
    ll before = 0, after = 0;
    if(l >= 2){
      before += abs(b[l - 2]);
      b[l - 2] += v;
      after += abs(b[l - 2]);
    }
    if(r < n){
      before += abs(b[r - 1]);
      b[r - 1] -= v;
      after += abs(b[r - 1]);
    }
    ans += after - before;
    cout << ans << "\n";
  }
}