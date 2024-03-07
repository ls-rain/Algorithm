#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int num;
int e;
int index = -1;
int index1 = -1;
typedef struct {
	int weight;
	int v1;
	int v2;
}edge;
edge set_of_edges[101];
edge result[101];
typedef struct {
	int parent;
	int depth;
}universe;
universe U[101];
int find(universe* U, int i) {
	int j;
	j = i;
	while (U[j].parent != j) j = U[j].parent;
	return j;
}
void merge(universe* U,int p, int q) {
	if (U[p].depth == U[q].depth) {
		U[p].depth += 1; U[q].parent = p;
	}
	else if(U[p].depth<U[q].depth) U[p].parent= q;
	else U[q].parent = p;
}
void makeset(universe* U, int i) {
	U[i].parent = i;
	U[i].depth = 0;
}
void initial(universe* U, int n){
	for (int i = 1; i <= n; i++)
		makeset(U, i);
}

int equal(int p, int q) {
	if (p == q) return true;
	else return false;
}

void kruskal(int n, int m, edge* E, edge* F) {
	int i, j;
	int p, q;
	edge e;
	for (int i = 0; i < m - 1; i++){
		for (int j = i + 1; j < m; j++){
			if (E[i].weight > E[j].weight){
				edge temp = E[i];
				E[i] = E[j];
				E[j] = temp;
			}
		}
	}
	for (int i = 1; i <= n; i++){
		U[i].parent = 0;
		U[i].depth = 0;
	}

	for (int i = 0; i < m; i++){
		F[i].v1 = 0;
		F[i].v2 = 0;
		F[i].weight = 0;
	}
	initial(U, n);
	int index = 0;
	while (1) {
		e = E[index];
		i = E[index].v1;
		j = E[index].v2;
		p = find(U,i);
		q = find(U,j);
		if (!equal(p, q)) {
			merge(U, p, q);
			F[++index1]=E[index];
		}
		index++;
		int cnt = 0;
		for (int i = 1; i <= m; i++)	{
			if (U[i].parent == i)
				cnt++;
		}
		if (cnt == 1) break;
	}
	cout << "집합F" << endl;
	for (int k = 0; k <= index1; k++) cout << "("<< F[k].v1 << ", " << F[k].v2 << ")"<<endl;
}


int main() {
	int vertex1, vertex2, w;
	int index = 0;
	cout << "입력크기 : ";
	cin >> num;
	cout << "edge 개수 : ";
	cin >> e;
	cout << "vertex1	vertex2		weight"<< endl;
	for (int i = 1; i <= e; i++) {
		cin >> vertex1 >> vertex2 >> w;
		set_of_edges[++index].v1 = vertex1;
		set_of_edges[index].v2 = vertex2;
		set_of_edges[index].weight = w;
	}
	kruskal(num, e, set_of_edges, result);
}
