#include "header.h"


void create_database(hash_t *hash_table,Slist_t *head){
  Slist_t *temp=head;

    while (temp != NULL){
        FILE *fp = fopen(temp->file, "r");
            if(fp==NULL){
                printf("File opens fails\n");
                temp = temp->link;
                continue;
            }

        char words[30];

        while(fscanf(fp,"%29s",words)!=EOF){
            int index;
            if(words[0] >= 'a' && words[0] <= 'z'){
                index = words[0] - 'a';
            }
            else if(words[0] >= 'A' && words[0] <= 'Z'){
                index = words[0] - 'A';
            }
            else if(words[0] >= '0' && words[0] <= '9'){
                index = 26;
            }
            else{
                index = 27;
            }

            //printf("%s->index %d\n",words,index);
            printf("[%d]->%s\n",index,words);

            m_node *main=hash_table[index].m_link;     //check main node exist or not

            if(main==NULL){                             //initially hash table is empty
                main=malloc(sizeof(m_node));            //create main node
                if(main==NULL){
                    printf("Failed\n");
                    fclose(fp);
                    return;
                }

                strcpy(main->words,words);

                main->f_count=1;
                main->m_link=NULL;

                s_node *sub=malloc(sizeof(s_node));         //create sub node
                if(sub==NULL){
                    printf("Failed\n");
                    free(main);
                    fclose(fp);
                    return;
                }

                strcpy(sub->filename,temp->file);
                sub->w_count=1;
                sub->s_link=NULL;

                main->s_link=sub;

                hash_table[index].m_link=main;
            }
            else{                                                             //main already exist
                m_node *prev_main=NULL;

                while(main!=NULL && strcmp(main->words,words)!=0){
                    prev_main=main;
                    main=main->m_link;
                }

                if(main==NULL){                                                 //suppose word does not exist create another main
                    main=malloc(sizeof(m_node));
                    if(main==NULL){
                        printf("Failed\n");
                        fclose(fp);
                        return;
                    }

                    strcpy(main->words,words);
                    main->f_count=1;
                    main->m_link=NULL;


                    s_node *sub=malloc(sizeof(s_node));          
                    if(sub==NULL){
                        printf("Failed\n");
                        free(main);
                        fclose(fp);
                        return;
                    
                    }

                    strcpy(sub->filename,temp->file);
                    sub->w_count=1;
                    sub->s_link=NULL;

                    main->s_link=sub;
                    prev_main->m_link=main;


                }
                else{                                                          //word already exist 
                    s_node *sub=main->s_link;
                    s_node *prev_sub=NULL;

                    while(sub!=NULL && strcmp(sub->filename,temp->file)!=0){
                        prev_sub=sub;
                        sub=sub->s_link;
                    }
                    if(sub!=NULL){
                        sub->w_count++;
                    }
                    else{
                        sub=malloc(sizeof(s_node));

                        if(sub==NULL){
                            printf("Failed\n");
                            fclose(fp);
                            return;
                        }

                        strcpy(sub->filename,temp->file);
                        sub->w_count=1;
                        sub->s_link=NULL;

                        prev_sub->s_link=sub;

                        main->f_count++;
                    }
                }

            }
        }

        fclose(fp);
        temp=temp->link;

    }

    printf("Database created successfully\n");

}