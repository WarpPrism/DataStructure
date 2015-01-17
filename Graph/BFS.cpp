// 广度优先搜索伪代码实现
// 非递归
// Basic Principle:
/*If the traversal has just visited a vertex v, then it next visits all 
  the vertices adjacent to v, putting the vertices adjacent to these in
  a waiting list to be traversed after all vertices adjacent to v have 
  been visited.

  Breadth first traversal can be done by using a queue. The head is the
  vertex to be visited. When it is visited, all its adjacent vertices 
  are put in the queue.

  Let v be the first vertex to be visited, and w1, …, wk be the adjacent vertices of v. 
  We will first put v in the queue. 
  Visit v and put w1, …, wk in the queue
  Then visit w1 and put the adjacent vertices of w1 into the queue, …, until all the vertices have been visited.

  广度优先搜索是一种分层的搜索过程, 每向前走一步可能访问一批顶点, 不像深度优先搜索那样有往回退的情况。
  因此, 广度优先搜索不是一个递归的过程。
  为了实现逐层访问, 算法中使用了一个队列,以记忆正在访问的这一层和下一层的顶点,以便于向下一层访问。
  为避免重复访问,需要一个辅助数组visited[]，给被访问过的顶点加标记。 */

template <int max_size>

void Digraph<max_size>::breadth_first(void(*visit)(vertex &)) const
/* Post: The function *visit has been performed at each vertex of the Digraph in
         breadth-first order.
   Uses: Methods of class Queue. */
{
	Queue q;
	bool visited[max_size];
	Vertex v, w, x;
	for (all v in G) visited[v] = false;
	for (all v in G)
		if (!visited[v]) {
			q.append(v);
			while (!q.empty()) {
				q.retrieve(w);
				if (!visited[w]) {
					visited[w] = true;
					(*visit)(w);
					for (all x adjacent to w)
						q.append(x);
				}
				q.serve();
			}
		}
}


从结点v开始访问：
1.v入队；
2.当队非空时
	1.取队头元素w，访问w;
	2.将w所有邻接点入队；
	3.对头元素出队
3.访问未被访问的结点。

