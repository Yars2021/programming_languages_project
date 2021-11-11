#include <stdio.h>
#include "st_string.h"
#include "list.h"

define_list(int)
define_list(int_list)

int main() {
    st_string* string = st_create("Hello");
    printf("%s\n\n", string->chars);
    st_destroy(string);

    list(int)* list1 = list_create(int);
    list_append(int, list1, 123);
    list_prepend(int, list1, -100000);
    list_append(int, list1, 5555);
    list_prepend(int, list1, 6666);

    for (int i = 0; i < list1->length; i++) {
        printf("%d\n", list_get_item(int, list1, i)->value);
    }

    printf("\n\n");
    list_remove_first(int, list1);

    for (int i = 0; i < list1->length; i++) {
        printf("%d\n", list_get_item(int, list1, i)->value);
    }

    printf("\n\n");
    list_clear(int, list1);

    printf("%d\n", list1->length);

    list_destroy(int, list1);
    return 0;
}
