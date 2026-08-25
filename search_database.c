#include "header.h"

void search_database(hash_t *hash_table)
{
    char words[100];

    printf("Enter the word: ");
    scanf("%99s", words);

    int index;

    /* Find hash index */
    if (words[0] >= 'a' && words[0] <= 'z')
    {
        index = words[0] - 'a';
    }
    else if (words[0] >= 'A' && words[0] <= 'Z')
    {
        index = words[0] - 'A';
    }
    else if (words[0] >= '0' && words[0] <= '9')
    {
        index = 26;
    }
    else
    {
        index = 27;
    }

    /* Start searching from calculated index */
    m_node *temp_m = hash_table[index].m_link;

    while (temp_m != NULL){
        if (strcmp(temp_m->words, words) == 0){
            printf("\n--------------------------------------------------------------------------\n");
            printf("%-8s %-15s %-12s %-20s %-10s\n", "Index", "Word","Filecount","Filename","Wordcount");
            printf("--------------------------------------------------------------------------\n");

            s_node *temp_s = temp_m->s_link;

            /* First file */
            if (temp_s != NULL){
                printf("[%-2d]    %-15s %-12d %-20s %-10d\n",index,temp_m->words,temp_s->filename,temp_s->w_count);
                temp_s = temp_s->s_link;
            }

            /* Remaining files */
            while (temp_s != NULL){
                printf("%-8s %-15s %-12s %-20s %-10d\n","","","",temp_s->filename,temp_s->w_count);
                temp_s = temp_s->s_link;
            }

            printf("--------------------------------------------------------------------------\n");

            return;
        }

        temp_m = temp_m->m_link;
    }

    printf("DATA_NOT_FOUND\n");
}