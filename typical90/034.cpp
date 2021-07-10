#include <iostream>
#include <vector>
#include <map>
using namespace std;

//104[ms]
int main(){
  int n,k;
  cin >> n >> k;
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  int right = 0;
  map<int, int> cnt;
  int kinds = 0, ans = 0;
  for(int left = 0; left < n; left++){
    while(right < n && kinds + (cnt[a[right]] == 0) <= k){
      if(cnt[a[right]]++ == 0) kinds++;
      right++;
    }
    ans = max(ans, right - left);
    if(right == left){
      right++;
    }
    if(--cnt[a[left]] == 0) kinds--;
  }
  cout << ans << "\n";
}