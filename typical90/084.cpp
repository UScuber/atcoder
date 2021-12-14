#include <iostream>
#include <string>
#include <vector>

//42[ms]
#define rep(i, n) for(int i = 0; i < n; i++)
using ll = long long;
using namespace std;

int main(){
  int n;
  string s;
  cin >> n >> s;
  vector<int> a(n, -1), b(n, -1);
  rep(i, n){
    if(s[i] == 'o') a[i] = i;
    else if(i) a[i] = a[i - 1];
    if(s[i] == 'x') b[i] = i;
    else if(i) b[i] = b[i - 1];
  }
  ll ans = 0;
  rep(i, n){
    if(s[i] == 'o') if(a[i] != -1) ans += b[i] + 1;
    if(s[i] == 'x') if(b[i] != -1) ans += a[i] + 1;
  }
  cout << ans << "\n";
}