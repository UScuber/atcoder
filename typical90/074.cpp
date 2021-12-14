#include <iostream>
#include <string>

//9[ms]
using ll = long long;
using namespace std;

int main(){
  int n;
  string s;
  cin >> n >> s;
  ll ans = 0;
  for(int i = 0; i < n; i++)
    ans += (s[i]-'a') * (1LL << i);
  cout << ans << "\n";
}