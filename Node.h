#include "Record.h"


typedef struct Node {
    Record value;
    struct Node *next;
} Node;