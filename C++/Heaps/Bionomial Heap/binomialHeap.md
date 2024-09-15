# Binomial Heap

A Binomial Heap is an extension of Binary Heap that provides faster union or merge operations,
along with other operations provided by Binary Heap.

## What is a Binomial Heap?

A Binomial Heap is a collection of Binomial Trees.

### Binomial Tree Definition

- A Binomial Tree of order 0 has 1 node.
- A Binomial Tree of order k can be constructed by taking two binomial trees of order k-1 and
  making one the leftmost child of the other.

### Properties of a Binomial Tree of Order k

A Binomial Tree of order k has the following properties:

1. It has exactly \( 2^k \) nodes.
2. It has a depth of k.
3. There are exactly \({k \choose i}\) nodes at depth i for i = 0, 1, ..., k.
4. The root has a degree of k, and the children of the root are themselves Binomial Trees of order k-1, k-2,...0 from left to right.

## Examples of Binomial Trees

### k = 0 (Single Node)

```
  o
```

### k = 1 (2 nodes)

[We take two k = 0 order Binomial Trees, and make one a child of the other]

```
  o
 /
o
```

### k = 2 (4 nodes)

[We take two k = 1 order Binomial Trees, and make one a child of the other]

```
     o
   /   \
  o     o
 /
o
```

### k = 3 (8 nodes)

[We take two k = 2 order Binomial Trees, and make one a child of the other]

```
        o
     /  | \
    o   o  o
   / \  |
  o   o o
 /
o
```

Each binomial tree follows this recursive structure, allowing for efficient union and merge operations in Binomial Heaps.

## Binomial Heap Example

A Binomial Heap is a set of Binomial Trees where each Binomial Tree follows the Min Heap property. And there can be at most one Binomial Tree of any degree.

### Example 1:

```
12------------10--------------------20
             /  \                 /  | \
           15    50             70  50  40
           |                  / |    |
           30               80  85  65
                            |
                           100
```

A Binomial Heap with 13 nodes. It is a collection of 3 Binomial Trees of orders 0, 2, and 3 from left to right.

### Example 2:

```
    10--------------------20
   /  \                 /  | \
 15    50             70  50  40
 |                  / |    |
 30               80  85  65
                  |
                 100
```

A Binomial Heap with 12 nodes. It is a collection of 2 Binomial Trees of orders 2 and 3 from left to right.

## Binary Representation of a Number and Binomial Heaps

A Binomial Heap with n nodes has the number of Binomial Trees equal to the number of set bits in the binary representation of n.

For example, let n be 13, there are 3 set bits in the binary representation of n (00001101), hence 3 Binomial Trees.

We can also relate the degree of these Binomial Trees with positions of set bits. With this relation, we can conclude that there are \( O(\log n) \) Binomial Trees in a Binomial Heap with n nodes.

## Operations of Binomial Heap

The main operation in Binomial Heap is `union()`. All other operations mainly use this operation.

### Insert(H, k)

Inserts a key 'k' to Binomial Heap 'H'. This operation first creates a Binomial Heap with a single key 'k', then calls union on H and the new Binomial heap.

### Get Min(H)

A simple way to get `min()` is to traverse the list of the roots of Binomial Trees and return the minimum key. This implementation requires \( O(\log n) \) time. It can be optimized to \( O(1) \) by maintaining a pointer to the minimum key root.

### Extract Min(H)

This operation also uses `union()`. We first call `getMin()` to find the minimum key Binomial Tree, then we remove the node and create a new Binomial Heap by connecting all subtrees of the removed minimum node. Finally, we call `union()` on H and the newly created Binomial Heap. This operation requires \( O(\log n) \) time.

### Delete(H)

Like Binary Heap, the delete operation first reduces the key to minus infinity, then calls `extractMin()`.

### Decrease Key(H)

`decreaseKey()` is also similar to Binary Heap. We compare the decreased key with its parent and if the parent’s key is more, we swap keys and recur for the parent. We stop when we either reach a node whose parent has a smaller key or we hit the root node. The time complexity of the `decreaseKey()` is \( O(\log n) \).

## Union Operation in Binomial Heap

Given two Binomial Heaps H1 and H2, `union(H1, H2)` creates a single Binomial Heap.

### Steps of Union Operation

1. The first step is to simply merge the two Heaps in non-decreasing order of degrees. In the following diagram, figure(b) shows the result after merging.
2. After the simple merge, we need to ensure that there is at most one Binomial Tree of any order. To do this, we need to combine Binomial Trees of the same order.

3. Traverse the list of merged roots, keeping track of three pointers: `prev`, `x`, and `next_x`.

### 4 Possible Cases While Traversing the List of Roots

1. **Case 1**: Orders of `x` and `next_x` are not the same, we simply move ahead.
2. **Case 2**: If the order of `next_next_x` is also the same, move ahead.
3. **Case 3**: If the key of `x` is smaller than or equal to the key of `next_x`, then make `next_x` a child of `x` by linking it with `x`.
4. **Case 4**: If the key of `x` is greater, then make `x` the child of `next_x`.
