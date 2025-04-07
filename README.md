

#  Graph Algorithms Project – CPP_EX1_25

##  Project Structure

This project implements a custom `Graph` class and several graph traversal and optimization algorithms in C++. It does not use STL containers (`vector`, `map`, etc.) but relies entirely on manually implemented data structures.

### Directory structure:

```
CPP_EX1_25/
├── src/
│   ├── Algorithms.cpp
│   ├── Algorithms.hpp
│   ├── Graph/
│   │   ├── Graph.cpp
│   │   └── Graph.hpp
├── datastructures/
│   ├── Queue.cpp / .hpp
│   ├── Stack.cpp / .hpp
│   ├── PriorityQueue.cpp / .hpp
│   └── UnionFind.cpp / .hpp
├── test/
│   ├── doctest.h
│   └── test.cpp        # Doctest unit tests
├── main/
│   └── main.cpp        # Demonstration program
├── Makefile
└── README.md
```

---

##  How to Run the Project

### 1. Build the project
```bash
make
```

### 2. Run the demo executable
```bash
./prog
```

Or simply:
```bash
make run
```

### 3. Run unit tests
```bash
make test
```

### 4. Check memory with Valgrind
```bash
make valgrind
```

---

##   Graph Class Design

- The `Graph` is initialized with a fixed number of vertices `x`.
- Vertices are indexed from `0` to `x-1`.
- All graphs are assumed to be **simple**:
  - There can be **only one edge** between any two vertices.
  - If by mistake **two edges** are added between the same pair of vertices, only the **last one added** will be retained.
- This behavior is consistent with the assumption stated in the assignment instructions.

---

##  Algorithm Descriptions

- **None** of the implemented algorithms support empty graphs.  
  All will throw an exception if the graph has 0 vertices.

###  `bfs(const Graph& g, int start)`
- **Input**: Connected graph `g`, starting vertex `start`
- **Output**: A new `Graph` representing the BFS traversal tree
- **Throws**: If `start` is invalid

###  `dfsForest(const Graph& g, int start)`
- **Input**: Any graph `g`, starting vertex `start`
- **Output**: A new `Graph` representing the DFS forest
- **Throws**: If `start` is invalid

###  `dijkstra(const Graph& g, int start)`
- **Input**: Graph without negative edge weights, starting vertex `start`
- **Output**: A shortest path tree from `start` to all reachable nodes
- **Throws**: If `start` is invalid or graph has negative weights

###  `prim(const Graph& g)`
- **Input**: A connected graph without negative edge weights
- **Output**: A Minimum Spanning Tree (MST) of the input graph
- **Throws**:
  - If the graph is disconnected
  - If the graph has negative weights
  - If the graph is empty

 **Note**:  
Prim's algorithm here **starts from a random vertex**, so on graphs with **identical weights**, the **resulting MST may vary between executions**.  
However, in such cases, **all MSTs will be structurally valid and equivalent in cost**.

###  `kruskal(const Graph& g)`
- **Input**: A connected graph (even though standard Kruskal doesn't require it)
- **Output**: A Minimum Spanning Tree (MST) using Kruskal's algorithm
- **Throws**:
  - If the graph is disconnected
  - If the graph has negative weights
  - If the graph is empty

 **Note**:  
Although Kruskal normally works with disconnected graphs (returns a forest), in this project, it is **restricted to connected graphs** to match the behavior of Prim, as required by the assignment.




---

##  Custom Data Structures Used

| Structure        | Used in                         |
|------------------|----------------------------------|
| `Queue`          | `bfs()`                          |
| `Stack`          | `dfsForest()` / `dfsTree()`      |
| `PriorityQueue`  | `dijkstra()` and `prim()`        |
| `UnionFind`      | `kruskal()`                      |

All these data structures were implemented manually without STL.

---

##  References & Resources

The implementation of the data structures and algorithms was guided by:

-  Slides from the **Data Structures** course (1st year)
-  Slides from the **Algorithms 1** course (last semester)
- Online references:
  - https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/tutorial/
  - https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/tutorial/
  - https://www.tutorialspoint.com/data_structures_algorithms/stack_algorithm.htm
  - https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/tutorial/


---
##  Author:
| Name           | Student ID |
|----------------|------------|
| Noa Honigstein | 329808554  |

