#include <stdio.h>
#include <stdlib.h>
struct student {
    int id;
    char name[10];
    char dep[10];
};
int getPostion(struct student );
void insert (struct student);
void display (void);
int search (int );
void delet (int );
int main()
{
	//system("echo >data.txt");

    while (1){
            printf("make your chooes : \n %s %s %s %s %s %s"
           ,"1-insert in order .\n"
           ,"2-search record. \n"
           ,"3-delete record .\n"
           ,"4-display .\n"
           ,"5-update .\n"
           ,"6-exit . \n"
           );
    int chooes ;
    scanf("%d",&chooes);
    switch(chooes){
    case 1:
        printf("enter new student information , (id , name , department )");
        struct student newStudent={0,"",""};
        scanf("%d %s %s",&newStudent.id,newStudent.name,newStudent.dep);
        insert(newStudent);
        break;
    case 2:
        printf("enter student ID that you wont to search :");
        int id ;
        scanf("%d",&id);
        int pos=search(id);
        if(pos==-1){
            printf("these ID is not belong to any student :( !! \n ");
        }else{
            FILE *read;
            read=fopen("data.txt","rb");
            struct student found={0,"",""};
            fseek(read,sizeof(struct student)*pos,SEEK_SET);
            fread(&found,sizeof(struct student ),1,read);
            printf("ID :  %d\n Name:  %s\n Department :   %s\n\n\n ",found.id , found.name , found.dep);
            fclose(read);
        }
        break;
    case 3:
        printf("enter the student ID that you wont to delete");
        int id1 ;
        scanf("%d",&id1);
        int l =search(id1);
        if (l==-1){
            printf("these ID is not belong to any student :( !! \n ");
            }else{
            delet(id1);
            }
        break;
    case 4:
        display();
        break;
    case 5 :
        {
        printf("enter student ID that you wont to update :");
        int id ;
        scanf("%d",&id);
        int pos=search(id);
        if(pos==-1){
            printf("these ID is not belong to any student :( !! \n ");
        }else{
            FILE *read;
            read=fopen("data.txt","r+b");
            struct student found={0,"",""};
            fseek(read,sizeof(struct student)*pos,SEEK_SET);
            fread(&found,sizeof(struct student ),1,read);
            printf("enter new information ,(name , department)");
            scanf("%s %s",found.name,found.dep);
            fseek(read,sizeof(struct student)*pos,SEEK_SET);
            fwrite(&found,sizeof(struct student ),1,read);
            printf("information updated .");
            fclose(read);
        }
        break;
        }
    case 6:
        printf("are you sure you wont to exit ?(n/no )( y/yes)");
        char c ;
        scanf("%s",&c);

        if (c=='n'){

        }else
            return 0;
        break;
    }
    }
    return 0;
}

void insert (struct student newStudent ){
     FILE *write ;
     write=fopen("data.txt","ab");
     fwrite(&newStudent,sizeof(struct student),1,write);
     fclose(write);
     printf("these id is exist !!\n ");

}
void shifting (int pos,struct student newStudent){
    FILE *write;
    write=fopen("data.txt","r+b");
    int size =number_s();
    int count ;
    struct student curr={0,"",""};
    int num =1;
     for (count =size; count >=pos-1;count--){
        fseek(write,-sizeof(struct student)*num,SEEK_END);
        fread(&curr,sizeof(struct student ),1,write);
        fseek(write,-sizeof(struct student)*(num-1),SEEK_END);
        fwrite(&curr,sizeof(struct student ),1,write);
        num++;
     }
    fseek(write,sizeof(struct student)*(pos-1),SEEK_SET);
    fwrite(&newStudent,sizeof(struct student ),1,write );
    fclose(write);
}
int getPostion(struct student newStudent ){
    FILE *update;
    update=fopen("data.txt","rb");
    size_t p;
    int count=0,check=0;
    struct student curr={0,"",""};
    while((p=fread(&curr,sizeof(struct student ),1,update))>0){
        count++;
        if(curr.id>newStudent.id){
            check=-1;
            break;
        }

    }
    fclose(update);
    if(check==0)
        return -1;
    else
        return count;
}
void display (){
    FILE *pointer ;
    size_t p ;
    pointer = fopen ("data.txt", "rb");
    struct student s ={-1,"",""};

    while((p=fread(&s,sizeof(struct student ),1 ,pointer))>0){
        printf("id = %d , name =%s , department = %s \n ",s.id,s.name,s.dep);
        s.id=0;
    }
    if (s.id==-1){
        printf("no record !! \n \n \n");
    }
    fclose(pointer);
    }
int search(int id ){
	
    FILE *pointer ;int number_of_byte=0;int check =0;
    size_t p ;

    pointer = fopen ("data.txt", "r+b");
    struct student s ={0,"",""};
    while((p=fread(&s,sizeof(struct student ),1 ,pointer))>0){
        if(id ==s.id){
            check=1;
            break;
        }
        number_of_byte++;
    }

    fclose(pointer);
    if (check)
        return number_of_byte;
    else
        return -1;
}
int number_s(){
    FILE *pointer ;
    int number_of_byte=0;
    size_t p ;
    pointer = fopen ("data.txt", "rb");
    struct student s ={0,"",""};
    while((p=fread(&s,sizeof(struct student ),1 ,pointer))>0){
        number_of_byte++;
    }

    fclose(pointer);
    return number_of_byte;
}
void delet(int id ){
     FILE * read ,*write;
     read=fopen("data.txt","rb");
     size_t p;
     write =fopen("data2.txt","wb");
     struct student curr ={0,"",""};
    while((p=fread(&curr,sizeof(struct student ),1 ,read))>0){
        if(id ==curr.id){

        }else{
            fwrite(&curr,sizeof(struct student ),1,write);
        }
    }
    fclose(read);
    fclose(write);
    system("del data.txt");
    rename("data2.txt","data.txt");
    printf("success delet operation \n \n \n ");
}
