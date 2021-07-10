#include <iostream>
#include <vector>
using ll = long long;
using namespace std;

//7[ms]
int main(){
  int n; ll k;
  cin >> n >> k;
  vector<int> cnt(100000);
  int check = 1, last = n;
  while(true){
    cnt[last] = check;
    int num = last;
    while(num){
      last += num % 10;
      num /= 10;
    }
    last %= 100000;
    check++;
    if(cnt[last]) break;
  }
  if(k >= cnt[last]){
    k -= cnt[last] - 1;
    k %= check - cnt[last];
    n = last;
  }
  for(int i = 0; i < k; i++){
    int num = n;
    while(num){
      n += num % 10;
      num /= 10;
    }
    n %= 100000;
  }
  cout << n << "\n";
}