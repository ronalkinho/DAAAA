#include <iostream>
#include <fstream>
#include <vector>
#include <queue>


using namespace std;

bool resuelveCaso() {
	int N, K, S, E, ini, fin, num;

	cin >> N;


	cin >> K >> S >> E;


	if (N == 0 && K == 0 && S == 0 && E == 0)
		return false;

	vector <int> serpientes(N*N+1, 0);
	vector <int> escaleras(N*N + 1, 0);

	for (int i = 0; i < S; i++) {
		cin >> ini >> fin;
		serpientes[ini] = fin;
	}
	
	for (int i = 0; i < E; i++) {
		cin >> ini >> fin;
		escaleras[ini] = fin;
	}


	//Ahora aplicamos un bfs;

	ini = 1;
	fin = N*N;

	queue<int> q;
	vector<bool> marked(N*N+1, false);
	vector<int> edgeTo(N*N + 1, 0);

	marked[ini] = true;

	bool encontrado = false;
	q.push(ini); // and put it on the queue.


	while (!q.empty() && !encontrado)
	{
		int v = q.front();
		if (v == fin)
			encontrado = true;

		q.pop();// Remove next vertex from the queue.

		for (int i = 1; i <= K; i++) {
			num = v + i;
			if (num <= N*N) {
				if (!marked[num]) {
					if (escaleras[num] != 0) {
						edgeTo[escaleras[num]] = edgeTo[v] + 1; // save last edge on a shortest path,
						marked[escaleras[num]] = true; // mark it because path is known,
						marked[num] = true;
						q.push(escaleras[num]); // and add it to the queue.
					}
					else if (serpientes[num] != 0) {
						edgeTo[serpientes[num]] = edgeTo[v] + 1; // save last edge on a shortest path,
						marked[serpientes[num]] = true; // mark it because path is known,
						marked[num] = true;
						q.push(serpientes[num]); // and add it to the queue.
					}
					else {
						edgeTo[num] = edgeTo[v] + 1; // save last edge on a shortest path,
						marked[num] = true; // mark it because path is known,
						q.push(num); // and add it to the queue.
					}
				}
			}
		
		}
	}

	cout << edgeTo[fin] << endl;

	return true;
}

int main() {


#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


	while (resuelveCaso());

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;

}

