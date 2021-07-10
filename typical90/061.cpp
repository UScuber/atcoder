#include <iostream>
#include <queue>
using namespace std;

//169[ms]
int main(){
	int q;
	cin >> q;
	deque<int> que;
	for(int i = 0; i < q; i++){
		int t,x;
		cin >> t >> x;
		if(t == 1) que.push_front(x);
		if(t == 2) que.push_back(x);
		if(t == 3) cout << que[x - 1] << "\n";
	}
}