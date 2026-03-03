#include <stdio.h>
#include <string.h>
#include "kernel.h"
#include "filesystem.h"

File file_table[MAX_FILES];
int file_count = 0;

void create_file(char *name, int size) {
    if (file_count >= MAX_FILES) {
        printf("File limit reached\n");
        return;
    }

    file_table[file_count].inode = file_count + 1;
    strcpy(file_table[file_count].name, name);
    file_table[file_count].size = size;

    printf("File %s created with inode %d\n",
           name,
           file_table[file_count].inode);

    file_count++;
}

void list_files() {
    for (int i = 0; i < file_count; i++) {
        printf("Inode: %d | Name: %s | Size: %d\n",
               file_table[i].inode,
               file_table[i].name,
               file_table[i].size);
    }
}