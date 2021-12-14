#include <iostream>
#include <vector>
#include <algorithm>

//169[ms]
#define rep(i, n) for(int i = 0; i < n; i++)
using ll = long long;
#define pii pair<int, int>
using namespace std;
template<class T> struct bit{
  public:
  bit(int x){
    while(x > n) n *= 2;
    d.resize(n);
  }
  T sum(int l, int r){
    return sum(r) - sum(l);
  }
  void add(int i, T x){
    i++;
    while(i <= n){
      d[i - 1] += x;
      i += i & -i;
    }
  }
  private:
  int n = 1;
  vector<T> d;
  T sum(int i){
    T tot = 0;
    while(i > 0){
      tot += d[i - 1];
      i -= i & -i;
    }
    return tot;
  }
};
int main(){
  ll n,m;
  cin >> n >> m;
  vector<pii> val(m);
  rep(i, m){
    cin >> val[i].second >> val[i].first;
    val[i].first--; val[i].second--;
  }
  ll ans = m * (m - 1) / 2;
  {
    vector<ll> cnt(n);
    rep(i, m){
      cnt[val[i].first]++;
      cnt[val[i].second]++;
    }
    rep(i, n) ans -= cnt[i] * (cnt[i] - 1) / 2;
  }
  {
    vector<ll> cnt(n);
    rep(i, m) cnt[val[i].first]++;
    rep(i, n - 1) cnt[i + 1] += cnt[i];
    rep(i, m) if(val[i].second) ans -= cnt[val[i].second - 1];
  }
  {
    bit<int> seg(n);
    sort(val.begin(), val.end());
    rep(i, m){
      ll num = seg.sum(val[i].second + 1, val[i].first);
      ans -= num;
      seg.add(val[i].second, 1);
    }
  }
  cout << ans << "\n";
}