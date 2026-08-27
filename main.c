#include "header.h"

int main(int argc, char *argv[]){
    int option;
    Slist_t *head=NULL;
    hash_t hash_table[28];

    /* Check CLA */
    if (argc <= 1){
        printf("Error: Invalid Command lines\n");
        return 0;
    }

     /* Validate CLA files */
    for (int i = 1; i < argc; i++){
        validation(&head, argv[i]);
    }

    for (int i = 0; i < 28; i++){
        hash_table[i].index = i;
        hash_table[i].m_link = NULL;
    }

    while(1){
        printf("\n\t\t\t:::Inverted Search Project:::\n");
        printf("1.Create\n2.DIsplay\n3.Save\n4.Search\n5.Update\n");
        printf("Enter the option : ");
        scanf("%d",&option);

        switch(option){
            case 1:
                create_database(hash_table,head);
                break;

            case 2:
                display_database(hash_table);
                break;

            case 3:
                save_database(hash_table);
                break;

            case 4:
                search_database(hash_table);
                break;

            case 5:
                update_database(hash_table,&head);
                break;

            default:
                printf("Invalid option\n");
            
        }

    }

}