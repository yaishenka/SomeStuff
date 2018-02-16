#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

struct IGraph {
    virtual ~IGraph() {}
    virtual void AddEdge(int from, int to) = 0;

    virtual int VerticesCount() const  = 0;

    virtual void GetNext(int vertex, std::vector<int>& vertices) const = 0;
    virtual void GetPrev(int vertex, std::vector<int>& vertices) const = 0;
};

class CListGraph : public IGraph {
private:
    vector < vector <int> > graph;
    int* color;
    int n;
public:
    CListGraph (int N) : graph(N), n(N) {}

    CListGraph (const IGraph* Graph) : graph(Graph->VerticesCount()), n(Graph->VerticesCount()) {
        for (int i(0); i < n; ++i)
            Graph->GetNext(i, graph[i]);
    }

    int VerticesCount() const {
        return n;
    }

    void AddEdge(int from, int to) {
        if (from >= n || to >= n || from < 0 || to < 0)
            return;
        graph[from].push_back(to);
        graph[to].push_back(from); //если неориентированный
    }

    void GetNext(int vertex, std::vector<int>& vertices) const {
        if (vertex >= n || vertex < 0)
            return;
        vertices = graph[vertex];
    }

    void GetPrev(int vertex, std::vector<int>& vertices) const {
        if (vertex >= n || vertex < 0)
            return;
        for(int j(0); j < n; ++j) {
            for(auto i : graph[j]) {
                if (i == vertex)
                    vertices.push_back(j);
            }
        }
    }
    void debAg () const {
        for (int i(0); i<n; ++i) {
            cout << i << ": ";
            for (auto g : graph[i] ) {
                cout << g << " ";
            }
            cout << endl;
        }
    }
    int bfs (int from, int to);

};

int CListGraph:: bfs (int from, int to) {
	queue<int> myqueue;
	int distanse [VerticesCount()];
	int par[VerticesCount()];
	int path [VerticesCount()];
	for (int i(0); i<n; ++i){
		distanse[i] = 0;
		path[i] = 0;
	}
    path[from] = 1;
	myqueue.push(from);
	while (!myqueue.empty()) {
		int u=myqueue.front();
		myqueue.pop();
		for (int a : graph[u]) {
			if (!path[a]) {
				path[a]=path[u];
				par[a]=u;
				distanse[a]=distanse[u]+1;
				myqueue.push(a);
			} else if (distanse[a]==distanse[u]+1) {
				path[a]+=path[u];
			}
		}
	}
	return path[to];
}

int main () {
    int n, m, a, b;
    cin >> n >> m;
    CListGraph G(n);
    for (int i(0); i < m; ++i)
    {
        cin >> a >> b;
        G.AddEdge(a, b);
    }
    int to,from;
    cin >> from >> to;
    cout << G.bfs(from, to) << endl;
}


