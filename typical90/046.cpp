#include <iostream>
#include <vector>
using ll = long long;
using namespace std;

//107[ms]
int main(){
  int n;
  cin >> n;
  vector<ll> cnt(46), ncnt(46), nncnt(46);
  for(int i = 0; i < n; i++){
    int a; cin >> a;
    cnt[a % 46]++;
  }
  for(int i = 0; i < n; i++){
    int b; cin >> b;
    for(int j = 0; j < 46; j++) ncnt[(b + j) % 46] += cnt[j];
  }
  for(int i = 0; i < n; i++){
    int c; cin >> c;
    for(int j = 0; j < 46; j++) nncnt[(c + j) % 46] += ncnt[j];
  }
  cout << nncnt[0] << "\n";
}