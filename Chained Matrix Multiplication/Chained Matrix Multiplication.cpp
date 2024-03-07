#include <iostream>
using namespace std;

int Path[101][101];
int diagonal[101];
int s;

int minmult(int n, const int d[], int P[101][101]) {
	int i, j, k, diagonal;
	int M[101][101];
	for (int i = 1; i <= n; i++) M[i][i] = 0;
	for (diagonal = 1; diagonal <= n - 1; diagonal++) {
		for (int i = 1; i <= n - diagonal; i++) {
			int min = 99999;
			j = i + diagonal;
			for (int k = i; k <= j - 1; k++) {
				if (min > M[i][k] + M[k + 1][j] + d[i - 1] * d[k] * d[j]){
					M[i][j] = M[i][k] + M[k + 1][j] + d[i - 1] * d[k] * d[j];
					min = M[i][k] + M[k + 1][j] + d[i - 1] * d[k] * d[j];
					P[i][j] = k;
					}
				else M[i][j] = min;
			}
		}
	}
	return M[1][n];
}

void order(int i, int j) {
	if (i == j) cout << "A" << i;
	else {
		int k = Path[i][j];
		cout << "(";
		order(i, k);
		order(k + 1, j);
		cout << ")";
	}
}

int main(){
	cin >> s;
	for (int i = 1; i <= s; i++) {
		cout << "A" << i << " : ";
		cin >> diagonal[i-1];
		cin >> diagonal[i];
	}
	cout << "최소 곱셈 횟수 : " << minmult(s, diagonal, Path) << endl;
	cout << "곱셈 최적 순서 : " << " ";
	order(1, s);
}
