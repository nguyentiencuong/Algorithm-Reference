// basic graph structure define use adjacency matrix
struct BasicMatrixGraph {
	int vertex_num, edge_num; // vertex \& edge amount
	bool is_relate[MAX_VERTIX][MAX_VERTIX]; // \verb"is_relate[u][v] == true" imply there``s an edge $(u, v)$
	int build(int vn) {
		vertex_num = vn;
		edge_num = 0;
		fill_matrix(relate, vertex_num, vertex_num, false); // \SourceRef{source:utility}
	}
	// traversal u``s edges:
	// \verb"for (int v = 0; v < graph.vertex_num; ++v) { if (graph.is_relate[u][v]) {/* do something... */ } }"
};
// graph structure define use adjacency matrix for shortest path problem
struct SPMatrixGraph {
	int vertex_num, edge_num; // vertex \& edge amount
	int weight[MAX_VERTIX][MAX_VERTIX]; // \verb"weight[u][v] != INF" imply there``s an edge $(u, v)$
	int build(int vn) {
		vertex_num = vn;
		edge_num = 0;
		fill_matrix(weight, vertex_num, vertex_num, INF);
	}
	// traversal u``s edges:
	// \verb"for (int v = 0; v < graph.vertex_num; ++v) { if (graph.weight[u][v] != INF) {/* do something... */ } }"
};
// template of graph using adjacency list
template<typename edge_type>
struct ListGraph {
	typedef edge_type Edge;
	int vertex_num, edge_num; // vertex \& edge amount
	Edge * head[MAX_VERTEX];
	Edge edges[MAX_EDGE];
	int build(int vn) {
		vertex_num = vn;
		edge_num = 0;
		fill_range(head, head + graph.vertex_num, NULL); // \SourceRef{source:utility}
	}
	Edge * add_edge(int u, int v) {
		Edge * edge = edges + edge_num;
		edge->u = u;
		edge->v = v;
		edge->next = head[u];
		head[u] = edge;
		++edge_num;
		return edge;
	}
	// traversal u``s edges:
	// \verb"for (Edge * edge = graph.head[u]; edge != NULL; edge = edge->next) {/* do something... */ }"
};
// basic graph structure define for graph using adjacency list
struct BasicEdge {
	int u, v; // form, to
	BasicEdge * next; // next weight in adjacency list
};
struct BasicListGraph : ListGraph<BasicEdge> {};
// graph structure define use adjacency list for shortest path problem
struct SPEdge {
	int u, v; // form, to
	int weight; // weight
	SPEdge * next; // next weight in adjacency list
};
struct SPListGraph : ListGraph<SPEdge> {
	void add_edge(int u, int v, int w) {
		SPEdge * edge = add_edge(u, v);
		edge->w = w;
	}
};
// graph structure define use adjacency list for maximum flow problem
struct MFEdge {
	int u, v; // form, to
	int capacity, flow;
	SPEdge * reserve; // point to edge $(v, u)$
	SPEdge * next; // next weight in adjacency list
};
struct MFListGraph : ListGraph<MFEdge> {
	void add_edge(int u, int v, int capacity) {
		MFEdge * edge1 = add_edge(u, v);
		MFEdge * edge2 = add_edge(v, u);
		edge1->capacity = capacity;
		edge2->capacity = 0;
		edge1->flow = capacity;
		edge2->flow = 0;
		edge1->reserve = edge2;
		edge2->reserve = edge1;
	}
};
// bipartite graph
struct BiGraph {
	int x_num, y_num;
	bool edge;
	BiGraph(int xn, int yn) : x_num(xn), y_num(yn), edge(x_num, std::vector<bool>(y_num, false)) { }
};
