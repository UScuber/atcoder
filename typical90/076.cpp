#include <iostream>
#include <vector>

//44[ms]
#define rep(i, n) for(int i = 0; i < n; i++)
using ll = long long;
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<ll> a(n * 2);
  ll tot = 0;
  rep(i, n){
    cin >> a[i];
    a[i + n] = a[i];
    tot += a[i];
  }
  if(tot % 10){
    cout << "No\n";
    return 0;
  }
  tot /= 10;
  n *= 2;
  int right = 0;
  ll cnt = 0;
  for(int left = 0; left < n; left++){
    while(right < n && cnt + a[right] <= tot){
      cnt += a[right];
      right++;
    }
    if(cnt == tot){
      cout << "Yes\n";
      return 0;
    }
    if(left == right) right++;
    else cnt -= a[left];
  }
  cout << "No\n";
}