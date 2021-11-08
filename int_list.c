//
// Created by yaros on 08.11.2021.
//

#include <stdlib.h>
#include "int_list.h"

int_node* int_node_create(int value) {
    int_node* node = (int_node*) malloc(sizeof(int_node));
    node->value = value;
    node->next = node->prev = NULL;
    return node;
}

void int_node_destroy(int_node* node) {
    if (node != NULL) {
        if (node->prev == NULL) {
            if (node->next != NULL) {
                node->next->prev = NULL;
            }
        } else {
            if (node->next == NULL) {
                node->prev->next = NULL;
            } else {
                node->prev->next = node->next;
                node->next->prev = node->prev;
            }
        }
        free(node);
    }
}

int_list* int_list_create() {
    int_list* list = (int_list*) malloc(sizeof(int_list));
    list->length = 0;
    list->head = list->tail = NULL;
    return list;
}

void int_list_destroy(int_list* list) {
    if (list != NULL) {
        if (list->tail != NULL && list->head != NULL) {
            while (list->tail != list->head) {
                if (list->head != NULL) {
                    list->head = list->head->next;
                    int_node_destroy(list->head->prev);
                }
            }
        }
        free(list);
    }
}

void int_list_append(int_list* list, int value) {
    if (list != NULL) {
        int_node* node = int_node_create(value);
        list->length++;
        if (list->tail == NULL) {
            list->head = list->tail = node;
        } else {
            list->tail->next = node;
            node->prev = list->tail;
            list->tail = node;
        }
    }
}

void int_list_prepend(int_list* list, int value) {
    if (list != NULL) {
        int_node* node = int_node_create(value);
        list->length++;
        if (list->head == NULL) {
            list->head = list->tail = node;
        } else {
            list->head->prev = node;
            node->next = list->head;
            list->head = node;
        }
    }
}

int_node* int_list_get_item(int_list* list, int index) {
    if (list != NULL) {
        if (list->head == NULL || index < 0 || index >= list->length) {
            return NULL;
        } else {
            int_node *current_node;
            if (index < list->length / 2) {
                current_node = list->head;
                for (unsigned int i = 0; i < index; i++) {
                    current_node = current_node->next;
                }
            } else {
                current_node = list->tail;
                for (unsigned int i = list->length - 1; i > index; i--) {
                    current_node = current_node->prev;
                }
            }
            return current_node;
        }
    }
    return NULL;
}