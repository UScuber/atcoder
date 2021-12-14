#include <iostream>
#include <string>
#include <vector>

//158[ms]
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

vector<int> z_algo(const vector<int> &s){
  int n = s.size();
  vector<int> z(n);
  z[0] = n;
  int i = 1, j = 0;
  while(i < n){
    while(i + j < n && s[j] == s[i + j]) j++;
    z[i] = j;
    if(!j){
      i++;
      continue;
    }
    int k = 1;
    while(k < j && z[k] + k < j) z[i + k++] = z[k];
    i += k;
    j -= k;
  }
  return z;
}
int main(){
  int n;
  string s,t;
  cin >> n >> s >> t;
  vector<int> a(n * 2);
  rep(i, n){
    if(s[i] == 'G') a[i] = 1;
    if(s[i] == 'B') a[i] = 2;
    if(t[i] == 'G') a[i + n] = 2;
    if(t[i] == 'B') a[i + n] = 1;
  }
  int ans = 0;
  rep(i, 3){
    auto z = z_algo(a);
    rep(j, n) if(z[n + j] == n - j) ans++;
    rep(j, n) a[j] = (a[j] + 1) % 3;
  }
  a.assign(n * 2, 0);
  rep(i, n){
    if(s[i] == 'G') a[i + n] = 1;
    if(s[i] == 'B') a[i + n] = 2;
    if(t[i] == 'G') a[i] = 2;
    if(t[i] == 'B') a[i] = 1;
  }
  rep(i, 3){
    auto z = z_algo(a);
    for(int j = 1; j < n; j++) if(z[n + j] == n - j) ans++;
    rep(j, n) a[j] = (a[j] + 1) % 3;
  }
  cout << ans << "\n";
}