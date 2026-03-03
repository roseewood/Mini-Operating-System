#ifndef FILESYSTEM_H
#define FILESYSTEM_H

typedef struct {
    int inode;
    char name[32];
    int size;
} File;

void create_file(char *name, int size);
void list_files();

#endif