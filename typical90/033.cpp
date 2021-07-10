#include <iostream>
using namespace std;

//10[ms]
int main(){
  int h,w;
  cin >> h >> w;
  if(h == 1 || w == 1) cout << h * w << "\n";
  else cout << ((h+1) / 2) * ((w+1) / 2) << "\n";
}