/**
 * C collection Queue: queue.h
 *
 * Copyright (c) 2018 Junsulime
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */


#ifndef QUEUE_H
#define QUEUE

#include "container.h"

struct _Node {
    int item;
    struct _Node *next;
};

typedef struct {
    struct _Node *head;
    struct _Node *tail;

    int length;
} Queue;

typedef struct {
    Queue *_queue;
    struct _Node *current;
} QueueIter;

typedef struct {
    void (*init)(Queue *queue);
    
    void (*free)(Queue *queue);
    
    int (*contain)(Queue *queue, int e);

    int (*isEmpty)(Queue *queue);

    QueueIter* (*iterator)(Queue *queue);

    int (*hasNext)(QueueIter *iterator);

    int (*next)(QueueIter *iterator);

    void (*enqueue)(Queue *queue, int e);

    int (*dequeue)(Queue *queue);

    void (*clear)(Queue *queue);

    int (*length)(Queue *queue);

} QueueOp;

QueueOp queueOp();

void queueInit(Queue *queue);

void queueFree(Queue *queue);

int queueContain(Queue *queue, int e);

int queueIsEmpty(Queue *queue);

QueueIter* queueIterator(Queue *queue);

int queueHasNext(QueueIter *iterator);

int queueNext(QueueIter *iterator);

void queueEnqueue(Queue *queue, int e);

int queueDequeue(Queue *queue);

int queueLength(Queue *queue);

#endif  // QUEUE_H
