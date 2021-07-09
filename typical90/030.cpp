#include <iostream>
#include <vector>
using namespace std;

//234[ms]
int main(){
  int n,k;
  cin >> n >> k;
  vector<int> c(n + 1);
  for(int i = 2; i <= n; i++){
    if(!c[i]) for(int j = i; j <= n; j += i) c[j]++;
  }
  int ans = 0;
  for(int i = 0; i < n; i++) if(c[i + 1] >= k) ans++;
  cout << ans << "\n";
}