#include "header.h"

void display_database(hash_t *hash_table)
{
    printf("\n--------------------------------------------------------------------------\n");
    printf("%-8s %-15s %-12s %-20s %-10s\n",
           "Index", "Word", "Filecount", "Filename", "Wordcount");
    printf("--------------------------------------------------------------------------\n");

    for (int i = 0; i < 28; i++)
    {
        if (hash_table[i].m_link == NULL)
        {
            continue;
        }

        m_node *temp_m = hash_table[i].m_link;

        while (temp_m != NULL)
        {
            s_node *temp_s = temp_m->s_link;

            /* First sub node */
            if (temp_s != NULL)
            {
                printf("[%2d]      %-15s %-12d %-20s %-10d\n",i,temp_m->words,temp_m->f_count,temp_s->filename,temp_s->w_count);
                
                temp_s = temp_s->s_link;
            }

            /* Remaining sub nodes */
            while (temp_s != NULL)
            {
                printf("%-8s %-15s %-12s %-20s %-10d\n","","","",temp_s->filename,temp_s->w_count);

                temp_s = temp_s->s_link;
            }

            temp_m = temp_m->m_link;
        }
    }

    printf("--------------------------------------------------------------------------\n");
}