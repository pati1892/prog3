//**************************************
// undirected Graphs
// implementation via adjacency lists
// assumption: 
// nodes are enumerated by numbers 0 .. Nodes()-1
// after creation, the number of nodes is fixed
//**************************************

using System;
using System.Collections.Generic;
using System.Text;

namespace UndirectedGraph
{
	public class Graph
	{
		readonly private int V;
		readonly private List<int>[] adj;

		// Creates an empty graph with V nodes
		public Graph(int V){
			if (V < 0) throw new ArgumentException("Number of vertices should not be negative\n");
			this.V = V;
			adj = new List<int>[V];
			for (int v = 0; v < V; v++)
				adj[v] = new List<int>();
		}

		// Creates a graph as copy of G
		public Graph(Graph G){
			this.V = G.Nodes();
			adj = new List<int>[V];
			for (int v = 0; v < G.V; v++)
			{
				adj[v] = new List<int>();
				for(int e = 0; e < G.adj[v].Count; e++)
					adj[v].Add(G.adj[v][e]);
			}
		}

		// Prints the graph
		public void Display(){
			for (int v = 0; v < V; v++)
			{
				System.Console.Write(v + ": ");
				for (int e = 0; e < adj[v].Count; e++)
					System.Console.Write(adj[v][e] + " ");
				System.Console.WriteLine();
			}
		}
		
		// Adds an edge
		public void AddEdge(int v, int w)
		{
			adj[v].Add(w);
			adj[w].Add(v);
		}

		// Deletes an edge
		public void DeleteEdge(int v, int w)
		{
			adj[v].Remove(w);
			adj[w].Remove(v);
		}

		// Returns first node
		public int Base()
		{
			if (V == 0)  throw new ApplicationException("Graph is empty\n");
			return 0;
		}

		// Returns number of nodes
		public int Nodes()
		{
			return V;
		}

		// Returns first node connected to node 
		public int NextNode(int v)
		{
			return adj[v][0];
		}

		// Returns all nodes connected to node (readonly)
		public List<int> AllNodes(int v)
		{
			return adj[v];
		}

		// Returns node degree
		public int Degree(int v)
		{
			return adj[v].Count;
		}

		// Returns whether graph is connected
		public bool Connected()
		{
			// Trivially connected
			if (V < 2) return true;
			// Try to visit all nodes using depth first search
			bool[] visited = new bool[V];
			for (int v = 0; v < V; v++) visited[v] = false;
			Stack<int> nextNodes = new Stack<int>();
			visited[0] = true;
			nextNodes.Push(0);
			while (nextNodes.Count > 0)
			{
				int v = nextNodes.Pop();
				List <int> neighbors = AllNodes(v);
				foreach (int w in neighbors)
				{
					if (!visited[w])
					{
						visited[w] = true;
						nextNodes.Push(w);
					}
				}
			}
			for (int v = 0; v < V; v++)
				if (!visited[v]) return false;
			return true;
		}   

	}
}
