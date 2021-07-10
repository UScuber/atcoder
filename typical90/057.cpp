#include <iostream>
#include <vector>
#define rep(i, n) for(int i = 0; i < n; i++)
using ll = long long;
#define mod 998244353
using namespace std;

//31[ms]
int main(){
  int n,m;
  cin >> n >> m;
  vector<vector<int>> d(n, vector<int>(m));
  rep(i, n){
    int t; cin >> t;
    rep(j, t){
      int a; cin >> a;
      d[i][--a] = 1;
    }
  }
  vector<int> s(m);
  rep(i, m) cin >> s[i];
  int pos = 0;
  rep(i, m){
    bool ok = false;
    for(int j = pos; j < n; j++){
      if(d[j][i]){
        if(pos != j) swap(d[j], d[pos]);
        ok = true;
        break;
      }
    }
    if(!ok) continue;
    rep(j, n) if(d[j][i] && j != pos)
      rep(k, m) d[j][k] ^= d[pos][k];
    if(s[i]) rep(j, m) s[j] ^= d[pos][j];
    pos++;
  }
  rep(i, m) if(s[i]){
    cout << "0\n";
    return 0;
  }
  int ans = 1;
  rep(i, n - pos) (ans <<= 1) %= mod;
  cout << ans << "\n";
}