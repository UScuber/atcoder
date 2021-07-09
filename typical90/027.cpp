#include <iostream>
#include <string>
#include <set>
using namespace std;

//246[ms]
int main(){
  int n;
  cin >> n;
  set<string> cnt;
  for(int i = 0; i < n; i++){
    string s;
    cin >> s;
    if(!cnt.count(s)) cout << i + 1 << "\n";
    cnt.insert(s);
  }
}