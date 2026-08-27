#include "header.h"

void save_database(hash_t *hash_table){
  char file[20];
  printf("Enter the file name: ");
  scanf("%s",file);

 
  char *ptr=strrchr(file,'.');
  if(ptr==NULL || strcmp(ptr,".txt")!=0){
    printf("Not validate file\n");
    return;
  }

  FILE *fp=fopen(file,"w");
  if(fp==NULL){
    printf("File opens Fails\n");
    return;
  }

  for(int i=0; i<28;i++){
    if(hash_table[i].m_link==NULL){
        continue;
    }

    m_node *temp_m=hash_table[i].m_link;
    while(temp_m!=NULL){
        fprintf(fp,"#;%d;%s;%d;",i,temp_m->words,temp_m->f_count);
        s_node *temp_s=temp_m->s_link;
        while(temp_s!=NULL){
            fprintf(fp,"%s;%d;#\n",temp_s->filename,temp_s->w_count);
            temp_s=temp_s->s_link;
        }
       temp_m=temp_m->m_link;

    }
    
}
fclose(fp);


}