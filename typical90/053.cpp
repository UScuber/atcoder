#include <iostream>
#include <vector>
#include <cmath>
#define rep(i, n) for(int i = 0; i < n; i++)
using ll = long long;
#define mod 1000000007
using namespace std;
template<class T, class U>
T &chmax(T &a, const U &b){ if(a < b) a = b; return a; }
const int len = 1596;
const double rt5 = sqrt(5);

//49[ms]
void solve(){
  int n;
  cin >> n;
  if(n <= 15){
    int mx = 0;
    rep(i, n){
      cout << "? " << i+1 << "\n";
      int a; cin >> a;
      chmax(mx, a);
    }
    cout << "! " << mx << "\n";
    return;
  }
  vector<int> a(len, -1);
  for(int i = n; i < len; i++) a[i] = -mod - i;
  int left = -1, right = len;
  int l = 609;
  int r = 986;
  while(left + 3 < right){
    if(a[l] == -1){
      cout << "? " << l+1 << "\n";
      cin >> a[l];
    }
    if(a[r] == -1){
      cout << "? " << r+1 << "\n";
      cin >> a[r];
    }
    if(a[l] < a[r]){
      left = l;
      l = r;
      r = right - r + left;
    }else{
      right = r;
      r = l;
      l = left - l + right;
    }
  }
  int ans = 0;
  for(int i = left + 1; i < right; i++){
    if(a[i] == -1){
      cout << "? " << i+1 << "\n";
      cin >> a[i];
    }
    chmax(ans, a[i]);
  }
  cout << "! " << ans << "\n";
}
int main(){
  int t;
  cin >> t;
  rep(i, t) solve();
}