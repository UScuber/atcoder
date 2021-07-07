#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using ll = long long;
using namespace std;
template<class T, class U>
T &chmax(T &a, const U &b){ if(a < b) a = b; return a; }

//43[ms]
int main(){
  int n;
  cin >> n;
  vector<tuple<int,int,int>> v(n);
  for(int i = 0; i < n; i++){
    int d,c,s;
    cin >> d >> c >> s;
    v[i] = {d,c,s};
  }
  sort(v.begin(), v.end());
  vector<ll> cur(5001), next(5001);
  for(int i = 0; i < n; i++){
    int d,c,s;
    tie(d,c,s) = v[i];
    for(int j = 0; j <= 5000; j++){
      next[j] = cur[j];
      if(j > d || j < c) continue;
      chmax(next[j], cur[j - c] + s);
    }
    swap(cur, next);
  }
  ll ans = 0;
  for(int i = 0; i <= 5000; i++) chmax(ans, cur[i]);
  cout << ans << "\n";
}