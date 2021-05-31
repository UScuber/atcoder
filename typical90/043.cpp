#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <climits>
 
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
int dy[] = {-1,1,0,0};
int dx[] = {0,0,-1,1};
int main(){
  int h,w;
  int sy,sx,ty,tx;
  cin >> h >> w >> sy >> sx >> ty >> tx;
  sy--; sx--; ty--; tx--;
  vector<vector<char>> a(h, vector<char>(w));
  rep(i, h) rep(j, w) cin >> a[i][j];

  deque<tuple<int,int,int>> que;
  vector<vvi> checked(h, vvi(w, vi(4, mod)));
  rep(i, 4) que.push_back({sy, sx, i});
  checked[sy][sx] = {0,0,0,0};

  while(!que.empty()){
    int posy, posx,r;
    tie(posy, posx, r) = que.front();
    que.pop_front();
    rep(i, 4){
      if(checked[posy][posx][i] > checked[posy][posx][r] + 1){
        que.push_back({posy,posx,i});
        checked[posy][posx][i] = checked[posy][posx][r] + 1;
      }
    }
    int y = posy + dy[r];
    int x = posx + dx[r];
    if(y < 0 || x < 0 || y >= h || x >= w || a[y][x] == '#') continue;
    if(checked[y][x][r] > checked[posy][posx][r]){
      que.push_front({y,x,r});
      checked[y][x][r] = checked[posy][posx][r];
    }
  }
  
  int ans = mod;
  rep(i, 4) chmin(ans, checked[ty][tx][i]);
  cout << ans << "\n";
}