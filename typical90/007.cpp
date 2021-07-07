#include <iostream>
#include <vector>
#include <algorithm>
#define all(a) (a).begin(), (a).end()
using namespace std;

//638[ms]
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  sort(all(a));
  int q;
  cin >> q;
  for(int i = 0; i < q; i++){
    int b; cin >> b;
    int pos = lower_bound(all(a), b) - a.begin();
    int ans = abs(a[pos] - b);
    if(pos) ans = min(ans, abs(b - a[pos - 1]));
    cout << ans << "\n";
  }
}