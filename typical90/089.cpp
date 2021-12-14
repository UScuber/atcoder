#include <iostream>
#include <vector>
#include <algorithm>

//118[ms]
#define rep(i, n) for(int i = 0; i < n; i++)
using ll = long long;
#define all(a) (a).begin(), (a).end()
#define mod 1000000007
using namespace std;

template<class T> struct bit{
  bit(int x){
    while(x > n) n *= 2;
    d.resize(n);
  }
  T sum(int l, int r){
    return sum(r) - sum(l);
  }
  void add(int i, T x){
    i++;
    while(i <= n){
      d[i - 1] += x;
      i += i & -i;
    }
  }
  private:
  int n = 1;
  vector<T> d;
  T sum(int i){
    T tot = 0;
    while(i > 0){
      tot += d[i - 1];
      i -= i & -i;
    }
    return tot;
  }
};
int n; ll K;
void compress(vector<int> &a){
  vector<int> x = a;
  sort(all(x));
  x.erase(unique(all(x)), x.end());
  rep(i, n){
    a[i] = lower_bound(all(x), a[i]) - x.begin();
  }
}
int main(){
  cin >> n >> K;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  compress(a);
  bit<int> seg(n);
  int left = n - 1;
  ll cnt = 0;
  vector<int> c(n);
  for(int right = n - 1; right >= 0; right--){
    while(left >= 0 && cnt + seg.sum(0, a[left]) <= K){
      cnt += seg.sum(0, a[left]);
      seg.add(a[left], 1);
      left--;
    }
    c[right] = left;
    if(right == left){
      seg.add(a[left], -1);
      left--;
    }
    cnt -= seg.sum(a[right] + 1, n);
    seg.add(a[right], -1);
  }
  vector<int> dp(n + 1), dp2(n + 1);
  dp2[0] = dp[0] = 1;
  rep(i, n){
    if(c[i] < 0) dp[i + 1] = dp2[i];
    else dp[i + 1] = (dp2[i] - dp2[c[i]] + mod) % mod;
    dp2[i + 1] = (dp2[i] + dp[i + 1]) % mod;
  }
  cout << dp[n] << "\n";
}