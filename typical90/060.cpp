#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(a) (a).begin(), (a).end()
#define mod 1000000007
using namespace std;
template<class T, class U>
T &chmax(T &a, const U &b){ if(a < b) a = b; return a; }

//106[ms]
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  vector<int> left(n), t(n, mod);
  rep(i, n){
    int pos = lower_bound(all(t), a[i]) - t.begin();
    t[pos] = a[i];
    left[i] = pos;
  }
  t.assign(n, mod);
  int ans = 0;
  for(int i = n - 1; i >= 0; i--){
    int pos = lower_bound(all(t), a[i]) - t.begin();
    t[pos] = a[i];
    chmax(ans, left[i] + pos + 1);
  }
  cout << ans << "\n";
}