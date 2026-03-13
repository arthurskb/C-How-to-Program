### 12.1
* **a)** referential
* **b)** `malloc`
* **c)** stack
* **d)** predicates
* **e)** First in First Out FIFO
* **f)** link
* **g)** `free`
* **h)** queue
* **i)** tree
* **j)** Last in First Out LIFO
* **k)** binary
* **l)** root
* **m)** Child or subtree
* **n)** leaf
* **o)** preorder, inorder, postorder

---

### 12.2
A linked list can insert and delete nodes anywhere, which differs from a stack that can only insert and delete it's top node.

---

### 12.3
As said in exercise 12.2, a stack can only insert and delete it's top node, meanwhile a queue can only insert into it's last node(tail) and only delete it's first node(head).

---

### 12.4
* **a)** `GradeNodePtr startPtr = NULL;`
* **b)**
```c
GradeNodePtr newPtr = malloc(sizeof(GradeNode));
newPtr-> = 91.5;
strcpy(newPtr->lastName, "Jones");
newPtr->nextPtr = NULL;
```
* **c)**
```c
//Adams:
//previousPtr points to NULL
//currentPtr points to startPtr
newPtr->nextPtr = currentPtr;
startPtr = newPtr;

//Thompson:
//previousPtr points to "Smith"
//currentPtr points to NULL
newPtr->nextPtr = currentPtr;
previousPtr->nextPtr = newPtr;

//Pritchard:
//previousPtr points to Jones
//currentPtr points to Smith
newPtr->nextPtr = currentPtr;
previousPtr->nextPtr = newPtr;
```
* **d)**
```c
currentPtr = startPtr;
while (currentPtr != NULL) {
  printf("%s %d -> ", currentPtr->lastName, currentPtr->grade);
  currentPtr = currentPtr->nextPtr;
}
```
* **e)**
```c
currentPtr = startPtr;
while (currentPtr != NULL) {
  GradeNodePtr tempPtr = currentPtr;
  currentPtr = currentPtr->nextPtr;
  free(tempPtr);
}
startPtr = NULL:
```

---

### 12.5
* **In-Order:** 11 18 19 28 32 40 44 49 69 71 72 83 92 97 99 (Access left node, prints, Access right node)
* **Pre-Order:** 49 28 18 11 19 40 32 44 83 71 69 72 97 92 99 (Prints, Access left node, Access right node)
* **Post-Order:** 11 19 18 32 44 40 28 69 72 71 92 99 97 83 49 (Access left node, Access right node, prints)

---

### 12.18
To perform a duplicate elimination using a one-dimensional array, we would need to make comparisons with elements in the array, until we find a duplicate, or worse comparing every element in the entire array, if it's an unique element. Meanwhile, binary-search-tree-based duplicate elimination relies on cutting half elements at each step in the worst case. In a grosse oversimplified generalized way, we could argue that every duplication check performs log n comparisons using the tree, instead of n comparisons using the one-dimensional array.
