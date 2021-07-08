#include <iostream>
using ll = long long;
using namespace std;

//6[ms]
int main(){
  ll a,b,c;
  cin >> a >> b >> c;
  ll d = 1;
  for(int i = 0; i < b; i++) d *= c;
  if(a < d) cout << "Yes\n";
  else cout << "No\n";
}