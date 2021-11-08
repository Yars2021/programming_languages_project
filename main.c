#include <stdio.h>
#include "st_string.h"
#include "int_list.h"

int main() {
    st_string* string = st_create("Hello");
    printf("%s\n\n", string->chars);
    st_destroy(string);

    int_list* list = int_list_create();
    int_list_append(list, 123);
    int_list_prepend(list, 987);
    printf("%d", int_list_get_item(list, 1));
    int_list_destroy(list);
    return 0;
}
