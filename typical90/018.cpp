#include <iostream>
#include <cmath>
using ll = long long;
using namespace std;

//10[ms]
const double pi = 3.141592653589;
int main(){
  ll x,y,q;
  double t,l;
  cin >> t >> l >> x >> y >> q;
  l /= 2;
  for(int i = 0; i < q; i++){
    double e; cin >> e;
    double rad = -pi/2 - 2*e/t*pi;
    double dy = l * cos(rad);
    double dist = sqrt(x*x + (dy-y)*(dy-y));
    double res = atan2(l * sin(rad) + l, dist);
    res = 180 * res / pi;
    printf("%.10lf\n", res);
  }
}