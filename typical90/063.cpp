#include <iostream>
#include <vector>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
template<class T, class U>
T &chmax(T &a, const U &b){ if(a < b) a = b; return a; }

//72[ms]
int main(){
  int h,w;
  cin >> h >> w;
  vector<vector<int>> a(h, vector<int>(w));
  rep(i, h) rep(j, w) cin >> a[i][j];
  int ans = 0;
  for(int s = 1; s < (1 << h); s++){
    vector<int> cnt(h * w);
    int bits = 0;
    rep(i, h) if(s >> i & 1) bits++;
    rep(j, w){
      int last = -1;
      bool ok = true;
      rep(i, h) if(s >> i & 1){
        if(last != -1 && a[i][j] != last) ok = false;
        last = a[i][j];
      }
      if(ok) cnt[last - 1]++;
    }
    int res = 0;
    rep(i, h*w) chmax(res, cnt[i]);
    res *= bits;
    chmax(ans, res);
  }
  cout << ans << "\n";
}