#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(a) (a).begin(), (a).end()
using ll = long long;
using namespace std;

//81[ms]
int main(){
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < n; i++) cin >> b[i];
  sort(all(a));
  sort(all(b));
  ll ans = 0;
  for(int i = 0; i < n; i++) ans += abs(a[i] - b[i]);
  cout << ans << "\n";
}