#include <bits/stdc++.h> /* этот хедер доступен только под gcc и по сути является просто инклудом с кучей других часто используемых инклудов */
using namespace std;

int main(){

	/* обозначения:
					n - число вершин,
					m - число рёбер,
					g[][] - граф,
					s - начало пути,
					t - конец пути,
					q - очередь на обработку вершин,
					d[] - расстояния от s (-1, если вершина недостижима из s)
	*/

	int n, m;
	cin >> n >> m;

	/* храним граф в виде "вектора векторов", т. е. g[v] содержит вектор-список всех соседней v */
	/* выбор такой структуры обусловлен тем, что вектор легко автоматически масштабируется */
	vector< vector<int> > g(n);

	while(m--){ /* цикл исполнится ровно m раз, я гарантирую это */
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	int s, t;
	cin >> s >> t;

	vector<int> d(n, -1); /* изначально будем считать недостижимыми все вершины, кроме s */
	d[s] = 0;

	queue<int> q;
	q.push(s);

	while(!q.empty()){
		int v = q.front(); /* записываем id первой вершины в очереди */
		q.pop(); /* ...и сразу же её оттуда удаляем */
		for(int u : g[v]) /* уникальная фишка C++11, означает "перебрать все элементы g[v], копируя их при каждой итерации в u; просто перебираем всех соседей v */
			if(d[u] == -1) /* следует читать как "если вершина u не была посещена ранее" */
				d[u] = d[v] + 1, q.push(v); /* устанавливаем расстояние и пихаем u в конец очереди */
	}

	cout << d[t];

	return 0;
}