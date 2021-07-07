#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//55[ms]
int main(){
  int n;
  cin >> n;
  if(n & 1){
    return 0;
    cout << "\n";
  }
  vector<string> ans;
  for(int i = (1 << n) - 1; i >= 0; i--){
    int cnt0 = 0;
    string s = "";
    for(int j = 0; j < n; j++){
      s += (i >> j & 1) ? ')' : '(';
      if(i >> j & 1){
        cnt0--;
        if(cnt0 < 0) goto out;
      }else cnt0++;
    }
    if(!cnt0) ans.push_back(s);
    out:
    continue;
  }
  sort(ans.begin(), ans.end());
  for(auto &s : ans) cout << s << "\n";
}