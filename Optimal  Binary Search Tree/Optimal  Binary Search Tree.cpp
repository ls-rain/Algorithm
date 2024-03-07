#include <iostream>
using namespace std;

int num;
float pos[101];
float res;
int Path[101][101];

void optsearchtree(int n, float p[], float& minavg, int R[101][101]) {
	int i, j, k, diagonal;
	float A[101][101];
	for (i = 0; i <= n+1; i++)
		for (j = 0; j <= n; j++) A[i][j] = 0;
	for (i = 1; i <= n; i++) {
		A[i][i - 1] = 0;
		A[i][i] = p[i];
		R[i][i] = i;
		R[i][i - 1] = 0;
	}
	A[n + 1][n] = 0;
	R[n + 1][n] = 0;
	for (diagonal = 1; diagonal <= n - 1; diagonal++) {
		for (i = 1; i <= n - diagonal; i++) {
			j = i + diagonal;
			float min = 999;
			for(k = i;  k<=j; k++){
				if (A[i][k - 1] + A[k + 1][j] < min) {
					min = A[i][k - 1] + A[k + 1][j];
					R[i][j] = k;
				}
			}
			float sum = 0;
			for (int m = i; m <= j; m++) sum += p[m];
			A[i][j] = min + sum;

		}
	}
	cout << "A" << endl;
	for (int b = 1; b <= n+1; b++) {
		for (int c = 0; c <= n; c++) {
			cout << A[b][c] << ' ';
		}
		cout << endl;
	}
	cout << "R" << endl;
	for (int b = 1; b <= n+1; b++) {
		for (int c = 0; c <= n; c++) {
			cout << R[b][c] << ' ';
		}
		cout << endl;
	}
	minavg = A[1][n];
}



int main(){
	cout << "입력크기 : ";
	cin >> num;
	for (int i = 1; i <= num; i++) {
		cout << "p" << i << " : ";
		cin >> pos[i];
	}
	optsearchtree(num, pos, res, Path);
	cout << res;

}
