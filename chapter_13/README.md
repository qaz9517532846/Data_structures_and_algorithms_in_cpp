# Chapter 13: Graph Algorithms

本章實作了各種重要的圖算法 (Graph Algorithms)，並整合到原有的 DFS 框架中。

## 檔案結構

### 主要檔案

1. **test.cpp** - 完整的圖算法實作
   - **原有的 DFS 框架**:
     - 通用 DFS 模板類別
     - Components: 計算連通分量
     - FindPath: 尋找路徑
     - FindCycle: 尋找環
   
   - **新增的圖實作**:
     - Graph 類別 (鄰接表表示法)
     - 支援有向圖和無向圖
     - Vertex 和 Edge 類別 (繼承 Decorator)
   
   - **圖算法**:
     - BFS (廣度優先搜索)
     - Dijkstra 最短路徑
     - 拓撲排序 (Topological Sort)
     - Kruskal's MST (使用 Union-Find)
   
   - **測試函數**:
     - testBasicGraph()
     - testBFS()
     - testDijkstra()
     - testTopologicalSort()
     - testKruskalMST()

2. **其他獨立實作** (額外提供的完整實作):
   - Graph.h - 獨立的圖類別
   - MST.h - 最小生成樹算法
   - FloydWarshall.cpp - Floyd-Warshall 算法
   - BellmanFord.cpp - Bellman-Ford 算法
   - GraphTest.cpp - 完整測試程式

3. **輔助檔案**:
   - BadCast.h - 異常處理
   - Decorator.h - 裝飾器模式

## 編譯與執行

### 編譯 test.cpp (主要測試)
```bash
cd chapter_13
g++ -std=c++11 -Wall -o test test.cpp
./test
```

### 編譯其他獨立程式
```bash
# 使用 Makefile 編譯所有獨立程式
make all

# 執行個別程式
./GraphTest
./FloydWarshall
./BellmanFord

# 執行所有測試
make run-all
```

### 清理
```bash
make clean
```

## 程式輸出範例

執行 `./test` 會看到：

```
==================================================
    Chapter 13: Graph Algorithms
==================================================

=== Testing Basic Graph Operations ===
Graph structure:
A -> (B,4) (C,2)
B -> (A,4) (C,1) (D,5)
...

=== Testing BFS ===
BFS: A B C D E F

=== Testing Dijkstra's Algorithm ===
Shortest distances from A:
A -> A: 0
A -> B: 4
A -> C: 2
...

=== Testing Topological Sort ===
Topological order: 4 5 2 0 3 1

=== Testing Kruskal's MST Algorithm ===
Minimum Spanning Tree:
G -- H (weight: 1)
F -- G (weight: 2)
...
Total weight: 35
```

## 算法說明

### 1. 深度優先搜索 (DFS) - 通用框架
- **時間複雜度**: O(V + E)
- **用途**: 圖遍歷、路徑查找、環檢測
- **特色**: 使用模板類別和虛函數實作可擴展的 DFS 框架

### 2. 廣度優先搜索 (BFS)
- **時間複雜度**: O(V + E)
- **用途**: 最短路徑（無權重）、層級遍歷

### 3. Dijkstra 算法
- **時間複雜度**: O((V + E) log V)
- **用途**: 單源最短路徑（非負權重）
- **限制**: 不能處理負權重邊

### 4. 拓撲排序
- **時間複雜度**: O(V + E)
- **用途**: DAG (有向無環圖) 的線性排序
- **應用**: 任務調度、課程安排

### 5. Kruskal's MST 算法
- **時間複雜度**: O(E log E)
- **用途**: 最小生成樹
- **特點**: 使用 Union-Find 資料結構
  - Path Compression (路徑壓縮)
  - Union by Rank (按秩合併)

### 6. Bellman-Ford 算法 (獨立檔案)
- **時間複雜度**: O(VE)
- **用途**: 單源最短路徑（可有負權重）
- **優勢**: 能檢測負權重環

### 7. Floyd-Warshall 算法 (獨立檔案)
- **時間複雜度**: O(V³)
- **用途**: 所有點對最短路徑
- **優勢**: 簡單、可處理負權重

### 8. Prim's MST 算法 (獨立檔案)
- **時間複雜度**: O((V + E) log V)
- **用途**: 最小生成樹
- **特點**: 使用優先佇列

## 設計模式與特色

### 1. 通用 DFS 框架
test.cpp 中的 DFS 實作使用了設計模式：
- **模板方法模式**: DFS 提供框架，子類別實作特定行為
- **裝飾器模式**: Vertex 和 Edge 繼承 Decorator，支援動態屬性

### 2. Graph 類別設計
- 使用鄰接表 (Adjacency List) 表示
- 支援有向圖和無向圖
- Vertex 和 Edge 作為內嵌類別
- 提供 incidentEdges() 與 DFS 框架整合

### 3. Union-Find 優化
- 路徑壓縮: find() 操作時壓縮路徑
- 按秩合併: 將矮樹合併到高樹下

## 使用範例

### 使用內建算法
```cpp
#include "test.cpp"

// 創建圖
Graph<string, int> g(false);
g.addEdge("A", "B", 4);
g.addEdge("B", "C", 3);

// BFS 遍歷
g.BFS("A");

// Dijkstra 最短路徑
map<string, int> distances = g.dijkstra("A");

// 拓撲排序
vector<int> sorted = g.topologicalSort();

// Kruskal's MST
vector<MST<string, int>::Edge> mst = MST<string, int>::kruskal(g);
MST<string, int>::printMST(mst);
```

## 重要概念

### 圖的表示方法
- **鄰接表**: 空間效率高 O(V + E)，適合稀疏圖
- **鄰接矩陣**: 查詢邊快速 O(1)，空間 O(V²)，適合稠密圖

### 圖的分類
- **有向圖 vs 無向圖**
- **加權圖 vs 無權重圖**
- **連通圖 vs 非連通圖**
- **DAG (有向無環圖)**

### Union-Find (並查集)
- **操作**:
  - Find: 查找元素所屬集合 - 近似 O(1)
  - Union: 合併兩個集合 - 近似 O(1)
- **優化**:
  - 路徑壓縮 (Path Compression)
  - 按秩合併 (Union by Rank)

## 應用場景

1. **社交網路分析**: 好友推薦、社群檢測
2. **地圖導航**: 最短路徑規劃
3. **網路路由**: 封包路由、網路拓撲
4. **任務調度**: 依賴關係管理 (拓撲排序)
5. **電路設計**: 最小連線成本 (MST)
6. **遊戲開發**: 尋路算法 (Pathfinding)

## 選擇算法的考量

1. **圖的大小**: 頂點數、邊數
2. **權重類型**: 正權重、負權重、無權重
3. **需求**:
   - 單源最短路徑 → Dijkstra / Bellman-Ford
   - 所有點對最短路徑 → Floyd-Warshall
   - 最小生成樹 → Kruskal / Prim
   - DAG 排序 → 拓撲排序
4. **記憶體限制**: 大圖使用鄰接表

## 注意事項

1. **Dijkstra 不支援負權重**，需要時使用 Bellman-Ford
2. **負權重環**會使最短路徑無定義
3. **拓撲排序**只適用於 DAG，有環則失敗
4. 對於**大型圖**，考慮：
   - 更高效的資料結構 (Fibonacci Heap)
   - 啟發式算法 (A*)
   - 近似算法

## 延伸學習

- A* 算法 (啟發式搜索)
- Strongly Connected Components (Tarjan / Kosaraju)
- Network Flow (Ford-Fulkerson, Edmonds-Karp)
- Bipartite Matching (匹配算法)
- Graph Coloring (圖著色)
- Minimum Cut (最小割)
