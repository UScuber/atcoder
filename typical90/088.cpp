#include <iostream>
#include <vector>

//9[ms]
#define rep(i, n) for(int i = 0; i < n; i++)
using ll = long long;
#define mod 1000000007
using namespace std;

int n,q;
vector<int> a,x,y;
vector<vector<int>> check;
vector<int> v, cnt;
vector<vector<vector<int>>> res(8890);
bool finished = false;
void dfs(int num, int val){
  if(finished) return;
  if(num == n){
    res[val].push_back(v);
    if(res[val].size() == 2) finished = true;
    return;
  }
  dfs(num + 1, val);
  if(cnt[num]) return;
  for(int x : check[num]) cnt[x]++;
  v.push_back(num);
  dfs(num + 1, val + a[num]);
  v.pop_back();
  for(int x : check[num]) cnt[x]--;
}
int main(){
  cin >> n >> q;
  a.resize(n);
  check.resize(n);
  cnt.resize(n);
  x.reserve(q);
  y.resize(q);
  rep(i, n) cin >> a[i];
  rep(i, q){
    cin >> x[i] >> y[i];
    check[--x[i]].push_back(--y[i]);
  }
  dfs(0, 0);
  rep(i, 8890){
    if(res[i].size() != 2) continue;
    rep(j, 2){
      int m = res[i][j].size();
      cout << m << "\n";
      rep(k, m - 1) cout << res[i][j][k] + 1 << " ";
      cout << res[i][j][m - 1] + 1 << "\n";
    }
    return 0;
  }
}