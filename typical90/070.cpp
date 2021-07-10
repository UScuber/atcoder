#include <iostream>
#include <vector>
#include <algorithm>
using ll = long long;
using namespace std;

//85[ms]
int main(){
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  for(int i = 0; i < n; i++) cin >> x[i] >> y[i];
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  ll ans = 0;
  for(int i = 0; i < n; i++){
    ans += abs(x[n/2] - x[i]);
    ans += abs(y[n/2] - y[i]);
  }
  cout << ans << "\n";
}