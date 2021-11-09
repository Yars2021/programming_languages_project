#include <stdio.h>
#include "st_string.h"
#include "list.h"

define_list(int)
define_list(int_list)

int main() {
    st_string* string = st_create("Hello");
    printf("%s\n\n", string->chars);
    st_destroy(string);

    int_list* list1 = int_list_create();
    int_list_append(list1, 123);
    int_list_prepend(list1, 4343);
    printf("%d\n\n", int_list_get_item(list1, 0)->value);

    list(int)* list2 = list_create(int);
    list_prepend(int, list2, 100000);
    list_append(int, list2, -100000);
    printf("%d\n\n", list_get_item(int, list2, 1)->value);

    int_list_list* list_of_lists = int_list_list_create();
    int_list_list_append(list_of_lists, *list1);
    int_list_list_append(list_of_lists, *list2);

    printf("%d\n\n", int_list_get_item(&int_list_list_get_item(list_of_lists, 1)->value, 0)->value);
    printf("%d\n\n", list_get_item(int, &list_get_item(int_list, list_of_lists, 1)->value, 0)->value);

    int_list_destroy(list1);
    list_destroy(int, list2);
    int_list_list_destroy(list_of_lists);
    return 0;
}
