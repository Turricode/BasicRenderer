#pragma once

#include <stdlib.h>
#include <stdio.h>

typedef struct NODE{
    void *data;
    struct NODE *next;
}*List;

char *CR_LoadFile(const char *path, int *size);

List CR_CreateList();
List CR_NextList(List l);
List CR_AddList(List l, void *data);
List CR_RemoveFromList(List l);

int CR_IsListEmpty(List l);