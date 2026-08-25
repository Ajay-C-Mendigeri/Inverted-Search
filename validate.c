#include "header.h"
#include<string.h>
#include<stdlib.h>

void validation(Slist_t **head, char *file){
    

    char *ptr;
    Slist_t *temp;
    Slist_t *new;

    

    ptr = strrchr(file, '.');

    if(ptr == NULL || strcmp(ptr, ".txt") != 0){
        printf("Not .txt file\n");
        return;
    }

    FILE *fp=fopen(file,"r");
    if(fp==NULL){
        printf("File open fails\n");
        return;
    }

    char ch=fgetc(fp);
    if(ch==EOF){
        printf("Empty file\n");
        fclose(fp);
        return;
    }

    fclose(fp);

    temp=*head;
    while(temp!=NULL){
        if(strcmp(temp->file,file)==0){
            //printf("Duplicate file\n");
            return;
        }

        temp=temp->link;
    }

    new=malloc(sizeof(Slist_t));
    if(new==NULL){
        printf("Failed\n");
        return;
    }

    strcpy(new->file,file);
    new->link=NULL;

    if(*head==NULL){
        *head=new;
    }
    else{
        temp=*head;

        while(temp->link!=NULL){
            temp=temp->link;
        }
        temp->link=new;
    }

    
}