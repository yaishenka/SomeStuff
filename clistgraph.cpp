#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

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
        //graph[to].push_back(from); если неориентированный
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
};

int main () {
    int n = 5;
    CListGraph G(n);
    G.AddEdge(0, 4);
    G.AddEdge(1, 2);
    G.AddEdge(2, 3);
    G.AddEdge(3, 4);
    G.debAg();
    CListGraph G1 = CListGraph(G);
    G1.debAg();
}


