#include <iostream>
#include <vector>
using namespace std;

//96[ms]
vector<vector<int>> grundy(51, vector<int>(1400, -1));
int calc(int x, int y){
  if(grundy[x][y] != -1) return grundy[x][y];
  int cnt[1400] = {};
  if(x >= 1) cnt[calc(x - 1, y + x)]++;
  for(int i = 1; i <= y / 2; i++)
    cnt[calc(x, y - i)]++;
  int res = 0;
  while(cnt[res]) res++;
  return grundy[x][y] = res;
}
int main(){
  int n;
  cin >> n;
  vector<int> w(n), b(n);
  for(int i = 0; i < n; i++) cin >> w[i];
  for(int i = 0; i < n; i++) cin >> b[i];
  int res = 0;
  for(int i = 0; i < n; i++) res ^= calc(w[i], b[i]);
  if(res) cout << "First\n";
  else cout << "Second\n";
}