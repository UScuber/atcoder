#include <iostream>
#include <vector>
using namespace std;

//771[ms]
int main(){
  int h,w;
  cin >> h >> w;
  vector<vector<int>> a(h, vector<int>(w));
  vector<int> c(h), r(w);
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      cin >> a[i][j];
      c[i] += a[i][j];
      r[j] += a[i][j];
    }
  }
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      int ans = c[i] + r[j] - a[i][j];
      cout << ans << (j == w-1 ? "\n" : " ");
    }
  }
}