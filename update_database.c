#include "header.h"

void update_database(hash_t *hash_table)
{
    char  file[20];
    printf("Enter the file name: ");
    scanf("%s", file);

    char *ptr = strrchr(file, '.'); 
    if (ptr == NULL || strcmp(ptr, ".txt") != 0) {
        printf("Not validate file\n");
        return;
    }

    FILE *fp = fopen(file, "r");

}