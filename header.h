#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//linked list
typedef struct node{
    char file[30];
    struct node *link;
}Slist_t;

//struture for main node
typedef struct mainnode{
    char words[30];
    int f_count;
    struct mainnode *m_link;
    struct subnode *s_link;
}m_node;

//struture for sub node
typedef struct subnode{
    char filename[30];
    int w_count;
    struct subnode *s_link;
}s_node;

//struture for hash table
typedef struct hash{
    int index;
    struct mainnode *m_link;
}hash_t;

void validation(Slist_t **head, char *file);
void create_database(hash_t *hast_table,Slist_t *head);
void display_database(hash_t *hast_table);
void save_database(hash_t *hast_table);
void search_database(hash_t *hast_table);
void update_database(hash_t *hast_table,Slist_t **head);