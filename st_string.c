//
// Created by yaros on 08.11.2021.
//

#include <stdlib.h>
#include <string.h>
#include "st_string.h"

st_string* st_create(char* line) {
    st_string* str = (st_string*) malloc(sizeof(st_string));
    str->length = strlen(line);
    str->chars = malloc(str->length + 1);
    strcpy_s(str->chars, str->length + 1, line);
    str->chars[str->length] = '\0';
    return str;
}

void st_destroy(st_string* line) {
    if (line != NULL) {
        if (line->chars != NULL) {
            free(line->chars);
        }
        free(line);
    }
}