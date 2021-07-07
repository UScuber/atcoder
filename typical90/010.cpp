#include <iostream>
#include <vector>
using namespace std;

//227[ms]
int main(){
  int n;
  cin >> n;
  vector<vector<int>> cnt(2, vector<int>(n + 1));
  for(int i = 0; i < n; i++){
    int c; cin >> c;
    cin >> cnt[c - 1][i + 1];
  }
  for(int i = 0; i < n; i++){
    cnt[0][i + 1] += cnt[0][i];
    cnt[1][i + 1] += cnt[1][i];
  }
  int q;
  cin >> q;
  for(int i = 0; i < q; i++){
    int l,r;
    cin >> l >> r;
    cout << cnt[0][r] - cnt[0][l-1] << " ";
    cout << cnt[1][r] - cnt[1][l-1] << "\n";
  }
}