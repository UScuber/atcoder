#include <iostream>
#include <vector>
using namespace std;

//55[ms]
int main(){
  int n,l,k;
  cin >> n >> l >> k;
  vector<int> a(n + 2);
  for(int i = 0; i < n; i++) cin >> a[i + 1];
  n++;
  a[n] = l;
  int left = 1, right = 1e9;
  while(left + 1 < right){
    int mid = (left + right) / 2;
    int cnt = 0, len = 0;
    //k <= cnt -> ok else ng
    for(int i = 0; i < n; i++){
      len += a[i + 1] - a[i];
      if(len >= mid && l - a[i + 1] >= mid){
        cnt++;
        len = 0;
      }
    }
    if(k <= cnt) left = mid;
    else right = mid;
  }
  cout << left << "\n";
}