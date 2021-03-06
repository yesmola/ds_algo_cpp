# Data Structure & Algorithm 
*implementation of some popular data structures and algorithms by c++*

## 数据结构
### 栈 Stack

### 队列 queue

### 链表 LinkedList

### [并查集 Disjoint Set Union](./data_structure/DisjointSetUnion.cpp)
并查集是一种树形的数据结构支持 **查找(Find)** 和 **合并(Union)** 操作。 

**查找(Find)**: 判断两个元素是否在同一个集合内/是否有同一个祖先。

**合并(Union)**：合并两个集合/类别。

### 堆
堆一一棵树，并且具有如下性质：每个节点对应一个键值且每个节点的键值都大于等于/小于等于父节点的键值。

堆的分类：二叉堆、配对堆、左偏树、二项堆、斐波那契堆
| 操作 | 二叉堆 | 配对堆 | 左偏树 | 二项堆 |
| :----: | :----: | :----: | :----: | :----: |
| 插入 | O(log n) | | | |
| 查询 | O(1） | | | |
| 删除 | O(log n) | | | |
| 合并 | O(n) | | | |
| 修改 | O(log n) | | | |

#### [二叉堆 Binary Heap](./data_structure/BinaryHeap.cpp)
二叉堆是一棵完全二叉树，每个节点存有一个元素。

大根堆：父节点堆键值大于等于子节点，cpp默认的priority_queue就是一个大根堆。

二叉堆的实现利用数组模拟，h[i]的子节点为h[2i]和h[2i+1]

### [ST表](./data_structure/STTable.cpp)
用于解决Range Maximum/Minimum Query,RMQ 区间查询最值问题

预处理时间复杂度O(n long n)，查询时间复杂度O(1)。

但是ST表不支持区间修改。

### [树状数组](./data_structure/BinaryIndexTree.cpp)
解决RMQ问题，支持单点修改、区间查询。利用差分数组也可以实现区间修改。

建表n次修改 O(n log n)

修改和查询 O(log n)

和ST表相比：可以支持修改。

和线段树相比：树状数组可以做的线段树都可以做，但是树状数组代码简洁清晰一些，如果解决一些单点修改问题，树状数组较为简单。

### [线段树](./data_structure/SegmentTree.cpp)
线段树可以在O(log n)的时间复杂度实现单点修改，区间修改，区间查询最大值、最小值、区间求和。

