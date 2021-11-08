//
// Created by yaros on 08.11.2021.
//

#ifndef PLPROJECT_INT_LIST_H
#define PLPROJECT_INT_LIST_H

typedef struct item {
    int value;
    struct item *next, *prev;
} int_node;

int_node* int_node_create(int);
void int_node_destroy(int_node*);

typedef struct {
    unsigned int length;
    int_node *head, *tail;
} int_list;

int_list* int_list_create();
void int_list_destroy(int_list*);

void int_list_append(int_list*, int);
void int_list_prepend(int_list*, int);
int_node* int_list_get_item(int_list*, int);
int int_list_push_after(int_list*, int, int);
int int_list_push_before(int_list*, int, int);
int int_list_set_value(int_list*, int, int);
int int_list_get_first(int_list*);
int int_list_get_last(int_list*);
void int_list_remove_first(int_list*);
void int_list_remove_last(int_list*);
void int_list_remove_index(int_list*, int);

#endif //PLPROJECT_INT_LIST_H
