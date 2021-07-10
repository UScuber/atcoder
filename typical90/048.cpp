#include <iostream>
#include <vector>
#include <algorithm>
using ll = long long;
using namespace std;

//152[ms]
int main(){
  int n,k;
  cin >> n >> k;
  vector<int> v(n * 2);
  for(int i = 0; i < n; i++){
    int a,b;
    cin >> a >> b;
    v[i*2] = b;
    v[i*2 + 1] = a - b;
  }
  sort(v.rbegin(), v.rend());
  ll ans = 0;
  for(int i = 0; i < k; i++) ans += v[i];
  cout << ans << "\n";
}