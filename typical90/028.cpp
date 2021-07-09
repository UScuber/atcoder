#include <iostream>
#include <vector>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

//87[ms]
int main(){
  int n;
  cin >> n;
  vector<vector<int>> a(1002, vector<int>(1002));
  rep(i, n){
    int lx,ly, rx,ry;
    cin >> lx >> ly >> rx >> ry;
    a[ly][lx]++;
    a[ry][lx]--;
    a[ly][rx]--;
    a[ry][rx]++;
  }
  //縦向きに累積和
  rep(i, 1001) rep(j, 1001) a[i + 1][j] += a[i][j];
  vector<int> res(n + 1);
  rep(i, 1001) rep(j, 1001){
    a[i][j + 1] += a[i][j]; //横向きに累積和
    res[a[i][j]]++;
  }
  for(int i = 1; i <= n; i++) cout << res[i] << "\n";
}