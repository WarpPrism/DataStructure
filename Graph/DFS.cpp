// 深度优先搜索的伪代码实现
// 递归方法实现
/*Basic Principle:
  Start to traverse from a vertex v0. 
  Let w1,w2, …, wk be the vertices adjacent to v0. Then we shall traverse
  from w1  until we traverse all the vertices to which it is adjacent before
  returning to traverse w2, …,wk .
  In case there are vertices which have not been visited, then chose one 
  vertex and start depth first traversal until all vertices are visited.*/

/*对于图的遍历，为了确保每个顶点在遍历过程中只被访问一次，需要为每个顶点建立
一个访问标志visited[i]，在遍历开始之前，将它们设为 “FALSE”，一旦第i个顶点被
访问，则令 visited[i] 为 "TRUE"。*/

template <int max_size>
void Digraph<max_size>::depth_first(void (*visit)(Vertex &)) const
/* Post: The function *visit has been performed at each vertex of the Digraph
   in depth-first order
   Uses: Method traverse to produce the recursive depth-first order. */
{
    bool visited[max_size];
    Vertex v;
    for (all v in G) visited[v] = false; // 辅助数组初始化为false，表示未访问。
    for (all v in G) if (!visited[v])
    	traverse(v, visited, visit);
}

template <int max_size>
void Digraph<max_size>::traverse(Vertex &v, bool visited[], void (*visit)(Vertex &)) const
/* Pre: v is a vertex of the Digraph.
   Post: The depth-first traversal, using function *visit, has been copleted for v and
         for all vertices that can be reached from v.
   Uses: traverse recursively. */
{
	Vertex w;
	visited[v] = true;
	(*visit)(v);
	for (all w adjacent to v)
		if (!visited[w])
			traverse(w, visited, visit);
}
