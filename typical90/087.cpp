#include <iostream>
#include <vector>

//21[ms]
#define rep(i, n) for(int i = 0; i < n; i++)
using ll = long long;
using namespace std;
#define mod 1000000007
template<class T, class U>
T &chmin(T &a, const U &b){ if(a > b) a = b; return a; }

const ll inf = 5000000000;
ll n,p,K;
vector<vector<ll>> a, dist;
ll search(){
  ll left = 0, right = inf;
  while(left + 1 < right){
    ll mid = (left + right) / 2;
    rep(i, n) rep(j, n){
      dist[i][j] = a[i][j];
      if(dist[i][j] == -1) dist[i][j] = mid;
    }
    rep(k, n) rep(i, n) rep(j, n)
      chmin(dist[i][j], dist[i][k] + dist[k][j]);
    int cnt = 0;
    rep(i, n) for(int j = i + 1; j < n; j++) if(dist[i][j] <= p) cnt++;
    if(cnt <= K) right = mid;
    else left = mid;
  }
  return left;
}
int main(){
  cin >> n >> p >> K;
  a.resize(n, vector<ll>(n));
  dist.resize(n, vector<ll>(n));
  rep(i, n) rep(j, n) cin >> a[i][j];
  ll s = search();
  K--;
  ll t = search();
  if(t - s >= mod) cout << "Infinity\n";
  else cout << t - s << "\n";
}