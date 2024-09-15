# Fibonacci Heap

## Introduction

A **Fibonacci heap** is a data structure used for implementing priority queues. It is an improvement over traditional binary heap and binomial heap data structures.

The key advantage of a Fibonacci heap is its **fast amortized running time** for operations like **insert**, **merge**, and **extract-min**, making it one of the most efficient data structures for these operations. The running times for key operations are:

- **Insert**: \( O(1) \)
- **Extract-min**: \( O(\log n) \)
- **Merge**: \( O(1) \) amortized

## Structure

A **Fibonacci heap** is a collection of trees where:

- Each tree is a **heap-ordered multi-tree**, meaning each tree has a single root node with children arranged in a heap-ordered manner.
- The trees are organized such that the root node with the smallest key is always at the front of the list.

### Operations

- **Insert**: A new element is inserted as a singleton tree.
- **Merge**: Two heaps are merged by appending the root list of one heap to the root list of another.
- **Extract-min**: The tree with the minimum root is removed, and its children are added to the root list.

## Lazy Consolidation

A unique feature of Fibonacci heaps is **lazy consolidation**, where merging of trees is delayed until necessary. This technique improves the efficiency of the merge operation by consolidating trees in batches.

## Time Complexities

Fibonacci heaps offer better time complexity compared to **Binary Heaps** and **Binomial Heaps**:

1. **Find Min**: \( \Theta(1) \) — Same as Binary Heap, better than Binomial Heap which is \( O(\log n) \).
2. **Delete Min**: \( O(\log n) \) — Same as both Binary and Binomial Heaps.
3. **Insert**: \( \Theta(1) \) — Faster than Binary Heap (\( \Theta(\log n) \)) and equal to Binomial Heap.
4. **Decrease-Key**: \( \Theta(1) \) — Faster than Binary and Binomial Heaps (\( \Theta(\log n) \)).
5. **Merge**: \( \Theta(1) \) — Much faster than Binary (\( \Theta(m \log n) \)) and Binomial Heap (\( \Theta(\log n) \)).

## Example Structure

A Fibonacci Heap maintains a pointer to the minimum value (root of a tree), and all tree roots are connected in a **circular doubly linked list**, making all accessible through the 'min' pointer.

The operations are executed in a "lazy" manner:

- **Merge**: Simply links two heaps.
- **Insert**: Adds a new tree with a single node.
- **Extract Min**: The most complicated operation, it delays the work of consolidating trees, similar to **delete**, where the key is decreased to minus infinity before calling extract-min.

## Interesting Facts

- The reduced time complexity of **Decrease-Key** benefits algorithms like **Dijkstra's** and **Prim's**. Using a Binary Heap, the time complexity is \( O(V \log V + E \log V) \), but with Fibonacci Heap, this improves to \( O(V \log V + E) \).
- Despite promising theoretical time complexity, Fibonacci Heaps may be slower in practice due to high hidden constants.
- Fibonacci numbers are used in the running time analysis. Every node in a Fibonacci Heap has a degree of at most \( O(\log n) \), and the size of a subtree rooted in a node of degree \( k \) is at least \( F\_{k+2} \), where \( F_k \) is the \( k \)-th Fibonacci number.

## Advantages of Fibonacci Heap

- **Fast amortized running time**: \( O(1) \) for insert and merge, and \( O(\log n) \) for extract-min.
- **Lazy consolidation**: Improves efficiency by merging trees in batches.
- **Efficient memory usage**: Lower memory overhead compared to other structures.

## Disadvantages of Fibonacci Heap

- **Increased complexity**: More complex structure and operations compared to binary or binomial heaps.
- **Less well-known**: Fewer resources and support available for implementation and optimization.

# Fibonacci Heap Operations

## Insertion

To insert a node into a Fibonacci heap \( H \), the following algorithm is followed:

1. **Create a new node ‘x’.**
2. **Check whether the heap \( H \) is empty or not.**
   - **If \( H \) is empty:**
     - Make \( x \) the only node in the root list.
     - Set the \( H(\text{min}) \) pointer to \( x \).
   - **Else:**
     - Insert \( x \) into the root list and update \( H(\text{min}) \).

---

## Extract Min

The function for deleting the minimum node and updating the min pointer to the new minimum value in the remaining heap follows this algorithm:

1. **Delete the minimum node.**
2. **Set head to the next minimum node** and add all trees of the deleted node to the root list.
3. **Create an array of degree pointers** based on the degree of the deleted node.
4. **Set the degree pointer to the current node.**
5. **Move to the next node.**
   - If degrees are **different**, set the degree pointer to the next node.
   - If degrees are **the same**, join the Fibonacci trees by the union operation.
6. **Repeat steps 4 and 5** until the heap is fully processed.

---

## Decrease Key

To decrease the value of any element in the heap, the following algorithm is applied:

1. **Decrease the value of the node \( x \) to the new chosen value.**
2. **Check for violations of the min-heap property:**
   - **Case 1:** If the min-heap property is **not violated**, update the min pointer if necessary.
   - **Case 2:** If the min-heap property **is violated** and the parent of \( x \) is unmarked:
     - Cut the link between \( x \) and its parent.
     - Mark the parent of \( x \).
     - Add the tree rooted at \( x \) to the root list and update the min pointer if necessary.
   - **Case 3:** If the min-heap property **is violated** and the parent of \( x \) is marked:
     - Cut the link between \( x \) and its parent \( p[x] \).
     - Add \( x \) to the root list, updating the min pointer if necessary.
     - Cut the link between \( p[x] \) and \( p[p[x]] \).
     - Add \( p[x] \) to the root list, updating the min pointer if necessary.
     - If \( p[p[x]] \) is unmarked, mark it.
     - Else, cut off \( p[p[x]] \) and repeat steps 4.2 to 4.5, treating \( p[p[x]] \) as \( x \).

---

## Deletion

To delete any element in a Fibonacci heap, the following algorithm is followed:

1. **Decrease the value of the node to be deleted \( x \) to a minimum** by using the `Decrease_key()` function.
2. **Heapify** the heap containing \( x \), bringing \( x \) to the root list by the min-heap property.
3. **Apply the `Extract_min()` algorithm** to remove \( x \) from the Fibonacci heap.

---
