#include <iostream>
#include <queue>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

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