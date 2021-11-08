#include <stdio.h>
#include "st_string.h"

int main() {
    st_string* string = st_create("Hello");
    printf("%s", string->chars);
    st_destroy(string);
    return 0;
}
