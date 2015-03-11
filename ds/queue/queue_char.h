#ifndef QUEUE_char_H
#define QUEUE_char_H

// Auto-generated header file for a queue of char
// values.  This queue has no exception handling but
// prints a message on stdout and calls exit(1).
// Author: drs.

typedef struct queue_char_implementation queue_char;

queue_char * new_bounded_queue_char(int max);
queue_char * new_unbounded_queue_char();
int queue_char_isempty(queue_char *q);
int queue_char_isfull(queue_char *q);
int queue_char_size(queue_char *q);
void queue_char_enqueue(queue_char *q, char x);
char queue_char_dequeue(queue_char *q);
char queue_char_front(queue_char *q);
void queue_char_print(queue_char *q, void (* item_print)(char item));
void queue_char_release(queue_char *q);

#endif
