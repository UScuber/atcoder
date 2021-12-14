#include <iostream>
#include <vector>

//74[ms]
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  vector<vector<int>> root(n);
  rep(i, m){
    int a,b;
    cin >> a >> b;
    a--; b--;
    root[a].push_back(b);
    root[b].push_back(a);
  }
  int ans = 0;
  rep(i, n){
    int cnt = 0;
    for(int &x : root[i]) if(x < i) cnt++;
    if(cnt == 1) ans++;
  }
  cout << ans << "\n";
}