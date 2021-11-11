//
// Created by yaros on 09.11.2021.
//

#ifndef PLPROJECT_LIST_H
#define PLPROJECT_LIST_H

#include <stdlib.h>

#define define_node(T)                                                             \
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

#define define_list(T)                                                             \
    define_node(T)                                                                 \
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
    void T##_list_append(T##_list* L, T V) {                                       \
        if (L != NULL) {                                                           \
            T##_node* node = node_create(T, V);                                    \
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
            T##_node* node = node_create(T, V);                                    \
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
    }                                                                              \
                                                                                   \
    void T##_list_push_after(T##_list* L, T V, unsigned int I) {                   \
    }                                                                              \
                                                                                   \
    void T##_list_push_before(T##_list* L, T V, unsigned int I) {                  \
    }                                                                              \
                                                                                   \
    void T##_list_set_value(T##_list* L, T V, unsigned int I) {                    \
    }                                                                              \
                                                                                   \
    T##_node* T##_list_get_first(T##_list* L) {                                    \
        return L->head;                                                            \
    }                                                                              \
                                                                                   \
    T##_node* T##_list_get_last(T##_list* L) {                                     \
        return L->tail;                                                            \
    }                                                                              \
                                                                                   \
    void T##_list_remove_first(T##_list* L) {                                      \
        if (L != NULL && L->length > 0) {                                          \
            L->length--;                                                           \
            if (L->length > 0) {                                                   \
                L->head = L->head->next;                                           \
            }                                                                      \
            node_destroy(T, L->head->prev);                                        \
        }                                                                          \
    }                                                                              \
                                                                                   \
    void T##_list_remove_last(T##_list* L) {                                       \
        if (L != NULL && L->length > 0) {                                          \
            L->length--;                                                           \
            if (L->length > 0) {                                                   \
                L->tail = L->tail->prev;                                           \
            }                                                                      \
            node_destroy(T, L->tail->next);                                        \
        }                                                                          \
    }                                                                              \
                                                                                   \
    void T##_list_clear(T##_list* L) {                                             \
        if (L != NULL) {                                                           \
            while (L->length > 0) {                                                \
                list_remove_first(T, L);                                           \
                list_remove_last(T, L);                                            \
            }                                                                      \
        }                                                                          \
    }                                                                              \
                                                                                   \
    void T##_list_remove_index(T##_list* L, unsigned int I) {                      \
    }                                                                              \
                                                                                   \
    void T##_list_destroy(T##_list* L) {                                           \
        if (L != NULL) {                                                           \
            list_clear(T, L);                                                      \
            free(L);                                                               \
        }                                                                          \
    }                                                                              \

#define list(T) T##_list
#define list_create(T) T##_list_create()
#define list_destroy(T, L) T##_list_destroy(L)
#define list_append(T, L, V) T##_list_append(L, V)
#define list_prepend(T, L, V) T##_list_prepend(L, V)
#define list_get_item(T, L, I) T##_list_get_item(L, I)
#define list_push_after(T, L, V, I) T##_list_push_after(L, V, I)
#define list_push_before(T, L, V, I) T##_list_push_before(L, V, I)
#define list_set_value(T, L, V, I) T##_list_set_value(L, V, I)
#define list_get_first(T, L) T##_list_get_first(L)
#define list_get_last(T, L) T##_list_get_last(L)
#define list_remove_first(T, L) T##_list_remove_first(L)
#define list_remove_last(T, L) T##_list_remove_first(L)
#define list_clear(T, L) T##_list_clear(L)
#define list_remove_index(T, L, I) T##_list_remove_index(L, I)

#endif //PLPROJECT_LIST_H
