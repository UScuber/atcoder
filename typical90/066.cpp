#include <iostream>
#include <vector>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

//9[ms]
int main(){
  int n;
  cin >> n;
  vector<int> left(n), right(n);
  rep(i, n) cin >> left[i] >> right[i];
  double ans = 0;
  rep(i, n) for(int j = i+1; j < n; j++){
    double pat = 0;
    for(int k = left[i]; k <= right[i]; k++){
      pat += max(k - left[j] - max(k - right[j] - 1, 0), 0);
    }
    pat /= (right[i] - left[i] + 1);
    pat /= (right[j] - left[j] + 1);
    ans += pat;
  }
  printf("%.10lf\n", ans);
}