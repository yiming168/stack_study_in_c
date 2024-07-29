#include "linkstack.h"

#include <stdio.h>
#include <stdlib.h>

linkstack stack_create() {
    linkstack s;
    if ((s = (linkstack)malloc(sizeof(listnode))) == NULL) {
        printf("malloc s failed\n");
        return NULL;
    }
    s->data = 0;
    s->next = NULL;

    return s;
}
int stack_push(linkstack s, data_t value) {
    linkstack new_node;
    if (s == NULL) {
        printf("s is NULL");
        return -1;
    }
    if ((new_node = (linkstack)malloc(sizeof(listnode))) == NULL) {
        printf("malloc storage for %d failed\n", value);
        return -1;
    }

    new_node->data = value;
    new_node->next = s->next;
    s->next = new_node;

    return 0;
}

data_t stack_pop(linkstack s) {
    if (s == NULL || s->next == NULL) {
        printf("stack is empty or NULL\n");
        return -1;
    }

    linkstack temp = s->next;
    data_t value = temp->data;
    s->next = temp->next;
    free(temp);
    temp = NULL;

    return value;
}
int stack_empty(linkstack s) {
    if (s == NULL) {
        printf("s is NULL");
        return -1;
    }
    return s->next == NULL;
}
data_t stack_top(linkstack s) {
    if (s == NULL || s->next == NULL) {
        printf("stack is empty or NULL\n");
        return -1;
    }
    return s->next->data;
}
void stack_free(linkstack s) {
    linkstack temp;
    if (s == NULL) {
        printf("s is NULL");
        return;
    }
    while (s != NULL) {
        temp = s;
        s = s->next;
        printf("free:%d\n", temp->data);
        free(temp);
    }
}