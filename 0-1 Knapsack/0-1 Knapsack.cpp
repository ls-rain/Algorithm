#include <iostream>
#include <string>
using namespace std;

int n, W;
int maxprofit, numbest;  
string include[101];
string bestset[101];

typedef struct knap {
	int p, w;
}knap;
knap knapStruct[101];

bool promising(int i, int profit, int weight) {
	int j, k;
	int totweight;
	float bound;
	if (weight >= W) return false;
	else {
		j = i + 1;
		bound = profit;
		totweight = weight;
		while ((j <= n) && (totweight + knapStruct[j].w <= W)) {
			totweight = totweight + knapStruct[j].w;
			bound = bound + knapStruct[j].p;
			j++;
		}
		k = j;
		if (k <= n)
			bound = bound + (W - totweight)*knapStruct[k].p / knapStruct[k].w;
		return bound > maxprofit;
	}
}
void knapsack(int i, int profit, int weight) {
	if (weight <= W && profit > maxprofit) {
		maxprofit = profit;
		numbest = i;
		for (int k = 1; k <= i; k++) bestset[k] = include[k];
	}
	if (promising(i, profit, weight)) {
		include[i + 1] = "YES";
		knapsack(i + 1, profit + knapStruct[i + 1].p, weight + knapStruct[i + 1].w);
		include[i + 1] = "NO";
		knapsack(i + 1, profit, weight);
	}
}
int main() {
	cout << "n : ";
	cin >> n;
	cout << "W : ";
	cin >> W;
	cout << "p[i]	w[i]" << endl;
	for (int i = 1; i <= n; i++) cin >> knapStruct[i].p >> knapStruct[i].w;
	knapsack(0, 0, 0);
	cout << "bestset : ";
	for (int i = 1; i <= numbest; i++) {
		cout << bestset[i] << " ";
	}
	cout << endl;
	cout << "maxprofit : " << maxprofit;
}
