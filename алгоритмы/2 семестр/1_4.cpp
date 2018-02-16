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

class CMatrixGraph : public IGraph {
private:
    int ** graph;
    int n;
public:
    CMatrixGraph (int N) : n(N) {
        graph=new int*[N];
        for (int i(0);i<N;++i) {
            graph[i] = new int[N];
        }
        for (int i(0);i<N;++i) {
            for (int j(0);j<N;++j) {
                graph[i][j]=0;
            }
        }
    }

    int VerticesCount() const {
        return n;
    }

    void AddEdge(int from, int to) {
        graph[from][to]=1;
    }

    void GetNext(int vertex, std::vector<int>& vertices) const {
        for (int i(0);i<VerticesCount();++i) {
            if (graph[vertex][i]) {
                vertices.push_back(i);
            }
        }
    }

    void GetPrev(int vertex, std::vector<int>& vertices) const {
        for (int i(0);i<VerticesCount();++i) {
            if (graph[i][vertex]) {
                vertices.push_back(i);
            }
        }
    }

    void debAg () const {
        cout << endl;
        for (int i(0); i<VerticesCount(); ++i) {
            cout << i << " ";
            for (int j(0);j<VerticesCount();++j) {
                if (graph[i][j]) cout << j << " ";
            }
            cout << endl;
        }
    }

    void Stock () {
        vector <int> tmp;
        for (int i(0);i<VerticesCount();++i) {
            tmp.clear();
            GetNext(i,tmp);
            if (tmp.size()==0) {
                tmp.clear();
                GetPrev(i,tmp);
                if (tmp.size()==VerticesCount()-1) {
                    cout << "YES" << endl;
                    return;
                }
            }
        }
        cout << "NO" << endl;
    }



};


int main () {
    int n, m, a, b;
    cin >> n;
    CMatrixGraph G(n);
    for (int i(0);i<n;++i) {
        for (int j(0);j<n;++j) {
            cin >> a;
            if (a) {
                G.AddEdge(i,j);
            }
        }
    }
    G.Stock();



}


