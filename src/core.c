#include "core.h"

void BufferClear(char *buffer, int size){
    for(int i = 0; i < size; i++){
        buffer[i] = 0;
    }
}

char *CR_LoadFile(const char *path, int *size){
    FILE *f = fopen(path, "r");

    if(f == NULL){
        return NULL;
    }

    fseek(f, 0, SEEK_END);
    int fsize = ftell(f);
    fseek(f, 0, SEEK_SET);

    char *final = (char *)malloc(fsize + 1);
    BufferClear(final, fsize);
    fread(final, 1, fsize, f);
    fclose(f);

    final[fsize] = 0;

    if(size != NULL)
        *size = fsize;
        
    return final;
}

List CR_CreateList(){
    return NULL;
}

List CR_NextList(List l){
    return l->next;
}

List CR_AddList(List l, void *data){
    List new_head = malloc(sizeof(struct NODE));
    new_head->data = data;
    new_head->next = l;
    return new_head;
}

List CR_RemoveFromList(List l){
    List tmp = l->next;
    free(l);
    return tmp;
}

int CR_IsListEmpty(List l){
    return l == NULL;
}