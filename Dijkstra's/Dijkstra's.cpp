#include <iostream>
#include <set>
#include <string>
using namespace std;

int num;
int weight[101][101];
set<string> edge;

void dijkstra(int n, const int W[101][101], set<string>& F) {
	int i;
	int vnear = 0;
	int touch[101];
	int length[101];
	string e;
	F.clear();
	for (i = 2; i <= n; i++) {
		touch[i] = 1;
		length[i] = W[1][i];
	}
	for (int k = 1; k <= n - 1; k++) {
		int min = 9999;
		for (i = 2; i <= n; i++) {
			if (0 <= length[i] && length[i]<=min) {
				min = length[i];
				vnear = i;
			}
		}
		e = "(" + to_string(touch[vnear]) + ", " + to_string(vnear) + ")";
		F.insert(e);
		for (i = 2; i <= n; i++) {
			if (length[vnear] + W[vnear][i] < length[i]) {
				length[i] = length[vnear] + W[vnear][i];
				touch[i] = vnear;
			}
		}
		length[vnear] = -1;
	}
}


int main(){
	cout << "입력크기 : ";
	cin >> num;
	cout << "가중치인접행렬" << endl;
	for (int i = 1; i <= num; i++)
		for (int j = 1; j <= num; j++) cin >> weight[i][j];
	cout << "집합 F의 엣지 목록" << endl;
	dijkstra(num, weight, edge);
	for (auto s : edge) cout << s;
}
