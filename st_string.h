//
// Created by yaros on 08.11.2021.
//

#ifndef PLPROJECT_ST_STRING_H
#define PLPROJECT_ST_STRING_H

typedef struct {
    char* chars;
    unsigned int length;
} st_string;

st_string* st_create(char*);
void st_destroy(st_string*);

#endif //PLPROJECT_ST_STRING_H
