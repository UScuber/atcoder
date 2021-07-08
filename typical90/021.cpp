#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < n; i++)
using ll = long long;
#define vi vector<int>
#define vvi vector<vi>
#define all(a) (a).begin(), (a).end()
#define mod 1000000007
using namespace std;

//157[ms]
void dfs(vvi &root, int pos, vi &checked, vi &I){
  checked[pos] = 1;
  for(int &x : root[pos]){
    if(!checked[x]) dfs(root, x, checked, I);
  }
  I.push_back(pos);
}
void dfs2(vvi &root, int pos, vi &checked, ll &cnt){
  checked[pos] = 1;
  cnt++;
  for(int &x : root[pos]){
    if(!checked[x]) dfs2(root, x, checked, cnt);
  }
}
int main(){
  int n,m;
  cin >> n >> m;
  vvi root(n), rroot(n);
  rep(i, m){
    int a,b;
    cin >> a >> b;
    a--; b--;
    root[a].push_back(b);
    rroot[b].push_back(a);
  }
  vi I;
  vi used(n);
  rep(i, n) if(!used[i]) dfs(root, i, used, I);
  reverse(all(I));
  vi checked(n);
  ll ans = 0, cnt = 0;
  for(int &x : I){
    if(checked[x]) continue;
    cnt = 0;
    dfs2(rroot, x, checked, cnt);
    ans += cnt * (cnt - 1) / 2;
  }
  cout << ans << "\n";
}