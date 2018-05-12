# C-collections

  Basic data structure and Concurrent data structure library for C. 

# Collections

## Basic Data Structure
- [x] ArrayList
- [x] Queue
- [ ] Heap
- [ ] Set
- [ ] Tree
- [ ] HashTable

## Concurrent Data Structure
- [ ] CArrayList
- [ ] CQueue


# Usage

  Three components are there. **Operator**, **Container**, **Iterator**.

### Operator
  Operator is main worker in C-Collection library. The operator takes all the actions of the container and the iterator as arguments.

### Container
  Container is data structure. Because C is not object oriented language, It must work with help of operator.
  
### Iterator
  Iterator is for iterating Container's item. I must work lwith help of operator too.

```C
QueueOp op = queueOp();
Queue queue;
QueueIter *iter;

op.init(&queue);
op.enqueue(&queue, 1);

iter = op.iterator(&queue);
while (op.hasNext(iter)) {
  printf("%d\n", op.next(ieter)  
}

free(iter);
op.free(&queue);
```
