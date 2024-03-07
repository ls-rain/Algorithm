#include <iostream>
using namespace std;
int n, weight;
int W[101][101];
int D[101][101];
int P[101][101];

void floyd2(int num, int We[101][101], int Dist[101][101], int Path[101][101]) {
	int i, j, k;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			Path[i][j] = 0;
	Dist = We;
	for (k = 1; k <= n; k++)
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				if (Dist[i][k] + Dist[k][j] < Dist[i][j]) {
					Path[i][j] = k;
					Dist[i][j] = Dist[i][k] + Dist[k][j];
				}
	cout << "- - - - - 최단거리 - - - - -";
	for (int i = 1; i <= n; i++) {
		cout << endl;
		for (int j = 1; j <= n; j++)
			cout << Dist[i][j] << " ";
	}
	cout << '\n' << "- - - - - 경로 - - - - -";
	for (int i = 1; i <= n; i++) {
		cout << endl;
		for (int j = 1; j <= n; j++)
			cout << Path[i][j] << " ";
	}
}
int main(){
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) cin >> W[i][j];
	floyd2(n, W, D, P);
}
