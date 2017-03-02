/*
Breadth-First Search (BFS)

Input:
	const int N; // number of vertices
	vector<int> g[N]; // directed unweighted graph 
	int s; // starting vertex

Output:
	int d[N]; // d[i] = distance(s, i)
*/

const int N = ...;
vector<int> g[N];
int s = ...;

int main()
{
	const int INF = N + 228;
	static int d[N];
	fill(d, d + N, INF);
	d[s] = 0;

	static int q[N];
	int ql = 0, qr = 1;
	q[0] = s;	
	
	while(ql != qr)
	{
		int v = q[ql++];
		for(int i : g[v])
		{
			if(d[i] == INF)
			{
				d[i] = d[v] + 1;
				q[qr++] = i;
			}
		}
	}
}
