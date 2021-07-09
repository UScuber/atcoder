#include <iostream>
#include <string>
#include <algorithm>
using ll = long long;
#define all(a) (a).begin(), (a).end()
using namespace std;

//50[ms]
ll n,b, ans = 0;
void dfs(string s, int v){
  ll cnt = 1;
  for(char c : s) cnt *= c - '0';
  cnt += b;
  string str = to_string(cnt);
  sort(all(str));
  if(str == s && cnt <= n) ans++;
  if((int)s.size() == 11) return;
  for(int i = v; i < 10; i++){
    dfs(s + char(i + '0'), i);
  }
}
int main(){
  cin >> n >> b;
  dfs("", 1);
  string str = to_string(b);
  for(char &c : str) if(c == '0'){
    if(n >= b) ans++;
    break;
  }
  cout << ans << "\n";
}