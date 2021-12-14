#include <iostream>
#include <vector>

//193[ms]
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
template<class T, class U>
T &chmax(T &a, const U &b){ if(a < b) a = b; return a; }

int main(){
  int n,k;
  cin >> n >> k;
  const int len = 5000;
  vector<vector<int>> c(len + 2, vector<int>(len + 2));
  rep(i, n){
    int a,b;
    cin >> a >> b;
    c[a][b]++;
  }
  rep(i, len) rep(j, len)
    c[i + 1][j + 1] += c[i + 1][j] + c[i][j + 1] - c[i][j];
  int ans = 0;
  for(int i = k + 1; i <= len; i++){
    for(int j = k + 1; j <= len; j++){
      chmax(ans, c[i][j] - c[i - k - 1][j] - c[i][j - k - 1] + c[i - k - 1][j - k - 1]);
    }
  }
  cout << ans << "\n";
}