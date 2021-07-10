#include <iostream>
#include <string>
#include <algorithm>
using ll = long long;
using namespace std;

//8[ms]
void change_8to9(string &s){
  ll res = 0;
  int n = s.size();
  //8 to 10
  for(int i = 0; i < n; i++){
    res += (s[i]-'0');
    res *= 8;
  }
  res /= 8;
  //10 to 9
  s = "";
  while(res){
    s += (res % 9) + '0';
    res /= 9;
  }
  reverse(s.begin(), s.end());
}
int main(){
  string s; int k;
  cin >> s >> k;
  if(s == "0"){
    cout << "0\n";
    return 0;
  }
  for(int i = 0; i < k; i++){
    change_8to9(s);
    for(char &c : s)
      if(c == '8') c = '5';
  }
  cout << s << "\n";
}