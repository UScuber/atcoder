#include <iostream>
#include <vector>
using namespace std;

//84[ms]
void dfs(vector<vector<int>> &root, int pos, vector<int> &checked){
  for(int x : root[pos]){
    if(checked[x]) continue;
    //1^3 = 2, 2^3 = 1
    checked[x] = 3 ^ checked[pos];
    dfs(root, x, checked);
  }
}
int main(){
  int n;
  cin >> n;
  vector<vector<int>> root(n);
  for(int i = 0; i < n - 1; i++){
    int a,b;
    cin >> a >> b;
    a--; b--;
    root[a].push_back(b);
    root[b].push_back(a);
  }
  vector<int> checked(n);
  checked[0] = 1;
  dfs(root, 0, checked);

  int cnt = 0;
  for(int i = 0; i < n; i++) if(checked[i] == 1) cnt++;
  int v = 1;
  if(cnt < n / 2) v++;
  int rest = 0;
  for(int i = 0; i < n; i++){
    if(checked[i] == v){
      cout << i + 1;
      rest++;
      if(rest == n / 2){
        cout << "\n";
        break;
      }else cout << " ";
    }
  }
}