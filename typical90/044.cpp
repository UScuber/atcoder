#include <iostream>
#include <queue>

#define rep(i, n) for(int i = 0; i < n; i++)
#define per(i, n) for(int i = n - 1; i >= 0; i--)
using ll = long long;
#define vi vector<int>
#define vvi vector<vi>
#define vl vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define mod 1000000007
using namespace std;
template<class T, class U>
T &chmax(T &a, const U &b){ if(a < b) a = b; return a; }
template<class T, class U>
T &chmin(T &a, const U &b){ if(a > b) a = b; return a; }
int main(){
  int n,q;
  cin >> n >> q;
  deque<int> a(n);
  rep(i, n) cin >> a[i];

  rep(i, q){
    int t,x,y;
    cin >> t >> x >> y;
    x--; y--;
    if(t == 1) swap(a[x], a[y]);
    if(t == 2){
      int v = a[n - 1];
      a.erase(a.end() - 1);
      a.push_front(v);
    }
    if(t == 3) cout << a[x] << "\n";
  }
}