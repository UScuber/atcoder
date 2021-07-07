#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(a) (a).begin(), (a).end()
using namespace std;
template<class T, class U>
T &chmax(T &a, const U &b){ if(a < b) a = b; return a; }

//528[ms]
const double pi = 3.141592653589;
double angle(const double &a, const double &b){
  double v = abs(a - b);
  if(v > pi) return 2 * pi - v;
  else return v;
}

int main(){
  int n;
  cin >> n;
  vector<int> X(n), Y(n);
  rep(i, n) cin >> X[i] >> Y[i];
  double ans = 0;
  //center
  rep(i, n){
    vector<double> angles(n - 1);
    rep(j, n){
      if(i > j) angles[j] = atan2(Y[j] - Y[i], X[j] - X[i]);
      if(i < j) angles[j - 1] = atan2(Y[j] - Y[i], X[j] - X[i]);
    }
    sort(all(angles));
    rep(j, n){
      if(i == j) continue;
      double deg = atan2(Y[j] - Y[i], X[j] - X[i]);
      int pos = lower_bound(all(angles), deg >= pi ? deg - pi : deg + pi) - angles.begin();
      if(pos == n - 1){
        chmax(ans, angle(deg, angles[n - 2]));
        chmax(ans, angle(deg, angles[0]));
      }else{
        chmax(ans, angle(deg, angles[pos]));
        if(pos) chmax(ans, angle(deg, angles[pos - 1]));
        else chmax(ans, angle(deg, angles[n - 2]));
      }
    }
  }
  ans = 180 * ans / pi;
  printf("%.10lf\n", ans);
}