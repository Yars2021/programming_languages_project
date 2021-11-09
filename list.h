//
// Created by yaros on 09.11.2021.
//

#ifndef PLPROJECT_LIST_H
#define PLPROJECT_LIST_H

#include <stdlib.h>

#define node(T)                                                                    \
    typedef struct T##_node {                                                      \
        T value;                                                                   \
        struct T##_node *next, *prev;                                              \
    } T##_node;                                                                    \
                                                                                   \
    T##_node* T##_node_create(T V) {                                               \
        T##_node* node = (T##_node*) malloc(sizeof(T##_node));                     \
        node->value = V;                                                           \
        node->next = node->prev = NULL;                                            \
        return node;                                                               \
    }                                                                              \
                                                                                   \
    void T##_node_destroy(T##_node* N) {                                           \
        if (N != NULL) {                                                           \
            if (N->prev == NULL) {                                                 \
                if (N->next != NULL) {                                             \
                    N->next->prev = NULL;                                          \
                }                                                                  \
            } else {                                                               \
                if (N->next == NULL) {                                             \
                    N->prev->next = NULL;                                          \
                } else {                                                           \
                    N->prev->next = N->next;                                       \
                    N->next->prev = N->prev;                                       \
                }                                                                  \
            }                                                                      \
            free(N);                                                               \
        }                                                                          \
    }

#define node_create(T, V) T##_node_create(V)
#define node_destroy(T, N) T##_node_destroy(N)

#define list(T)                                                                    \
    node(T)                                                                        \
    typedef struct {                                                               \
        unsigned int length;                                                       \
        T##_node *head, *tail;                                                     \
    } T##_list;                                                                    \
                                                                                   \
    T##_list* T##_list_create() {                                                  \
        T##_list* list = (T##_list*) malloc(sizeof(T##_list));                     \
        list->length = 0;                                                          \
        list->head = list->tail = NULL;                                            \
        return list;                                                               \
    }                                                                              \
                                                                                   \
    void T##_list_destroy(T##_list* L) {                                           \
        if (L != NULL) {                                                           \
            if (L->tail != NULL && L->head != NULL) {                              \
                while (L->tail != L->head) {                                       \
                    if (L->head != NULL) {                                         \
                        L->head = L->head->next;                                   \
                        T##_node_destroy(L->head->prev);                           \
                    }                                                              \
                }                                                                  \
            }                                                                      \
            free(L);                                                               \
        }                                                                          \
    }                                                                              \
                                                                                   \
    void T##_list_append(T##_list* L, T V) {                                       \
        if (L != NULL) {                                                           \
            T##_node* node = T##_node_create(V);                                   \
            L->length++;                                                           \
            if (L->tail == NULL) {                                                 \
                L->head = L->tail = node;                                          \
            } else {                                                               \
                L->tail->next = node;                                              \
                node->prev = L->tail;                                              \
                L->tail = node;                                                    \
            }                                                                      \
        }                                                                          \
    }                                                                              \
                                                                                   \
    void T##_list_prepend(T##_list* L, T V) {                                      \
        if (L != NULL) {                                                           \
            T##_node* node = T##_node_create(V);                                   \
            L->length++;                                                           \
            if (L->head == NULL) {                                                 \
                L->head = L->tail = node;                                          \
            } else {                                                               \
                L->head->prev = node;                                              \
                node->next = L->head;                                              \
                L->head = node;                                                    \
            }                                                                      \
        }                                                                          \
    }                                                                              \
                                                                                   \
    T##_node* T##_list_get_item(T##_list* L, unsigned int I) {                     \
        if (L != NULL) {                                                           \
            if (L->head == NULL || I < 0 || I >= L->length) {                      \
                return NULL;                                                       \
            } else {                                                               \
                T##_node *current_node;                                            \
                if (I < L->length / 2) {                                           \
                    current_node = L->head;                                        \
                    for (unsigned int i = 0; i < I; i++) {                         \
                        current_node = current_node->next;                         \
                    }                                                              \
                } else {                                                           \
                    current_node = L->tail;                                        \
                    for (unsigned int i = L->length - 1; i > I; i--) {             \
                        current_node = current_node->prev;                         \
                    }                                                              \
                }                                                                  \
                return current_node;                                               \
            }                                                                      \
        }                                                                          \
        return NULL;                                                               \
    }

#define list_create(T) T##_list_create()
#define list_destroy(T, L) T##_list_destroy(L)
#define list_append(T, L, V) T##_list_append(L, V)
#define list_prepend(T, L, V) T##_list_prepend(L, V)
#define list_get_item(T, L, I) T##_list_get_item(L, I)

//void list_push_after(list*, int, unsigned int);
//void list_push_before(list*, int, unsigned int);
//void list_set_value(list*, int, unsigned int);
//void* list_get_first(list*);
//void* list_get_last(list*);
//void list_remove_first(list*);
//void list_remove_last(list*);
//void list_remove_index(list*, unsigned int);

#endif //PLPROJECT_LIST_H
