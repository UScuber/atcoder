#include <iostream>
#include <vector>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main(){
  int n,k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  int cnt = 0;
  rep(i, n){
    int b; cin >> b;
    cnt += abs(a[i] - b);
  }
  if(k < cnt || (k-cnt) & 1){
    cout << "No\n";
  }else{
    cout << "Yes\n";
  }
}