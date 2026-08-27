#include "header.h"

//Adds filename to the list if not present 
static void add_to_list(Slist_t **head, char *filename)
{
    Slist_t *temp = *head;

    while (temp != NULL){
        if (strcmp(temp->file, filename) == 0){
            return;   /* already tracked, skip duplicate */
        }
        temp = temp->link;
    }

    Slist_t *new = malloc(sizeof(Slist_t));
    if (new == NULL){
        printf("Failed\n");
        return;
    }

    strcpy(new->file, filename);
    new->link = NULL;

    if (*head == NULL){
        *head = new;
    }
    else{
        temp = *head;
        while (temp->link != NULL){
            temp = temp->link;
        }
        temp->link = new;
    }
}

void update_database(hash_t *hash_table, Slist_t **head)
{
    char file[30];

    printf("Enter the saved database file name: ");
    scanf("%29s", file);

    char *ptr = strrchr(file, '.');
    if (ptr == NULL || strcmp(ptr, ".txt") != 0){
        printf("Not a .txt file\n");
        return;
    }

    FILE *fp = fopen(file, "r");
    if (fp == NULL){
        printf("File open fails\n");
        return;
    }

    int ch = fgetc(fp);
    if (ch != '#'){
        printf("Invalid database file format\n");
        fclose(fp);
        return;
    }
    rewind(fp);

    int index, fcount, wcount;
    char word[30], filename[30];

    //read each word entry: #;index;word;fcount;
    while (fscanf(fp, " #;%d;%29[^;];%d;", &index, word, &fcount) == 3){

        m_node *main_n = malloc(sizeof(m_node));
        if (main_n == NULL){
            printf("Failed\n");
            fclose(fp);
            return;
        }

        strcpy(main_n->words, word);
        main_n->f_count = fcount;
        main_n->s_link = NULL;

        main_n->m_link = hash_table[index].m_link;
        hash_table[index].m_link = main_n;

        s_node *temp = NULL;

        // read fcount sub entries: filename;wcount;#
        for (int k = 0; k < fcount; k++){
            if (fscanf(fp, " %29[^;];%d;#", filename, &wcount) != 2){
                printf("Corrupted database file\n");
                fclose(fp);
                return;
            }

            s_node *sub_n = malloc(sizeof(s_node));
            if (sub_n == NULL){
                printf("Failed\n");
                fclose(fp);
                return;
            }

            strcpy(sub_n->filename, filename);
            sub_n->w_count = wcount;
            sub_n->s_link = NULL;

            if (temp == NULL){
                main_n->s_link = sub_n;
            }
            else{
                temp->s_link = sub_n;
            }
            temp = sub_n;

            //Track this source filename to prevent duplicates
            add_to_list(head, filename);
        }
    }

    fclose(fp);
    printf("Database updated successfully\n");
}