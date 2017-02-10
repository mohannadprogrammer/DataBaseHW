#include<stdio.h>
#include<stdlib.h>
//student struct 

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


//prototypes 
void meragSort (char *);
int cutFile(char *);

int main ()
{
	struct student s={1,"mohannah","sw"};
s.id =putint();
insert (s);
	return 0;}

int cutFile (char *file ){

	FILE * read ;
	read =fopen (file,"rd");
	size_t p;
	int num_file=0;
	struct student st ={0,"",""};
	while ((p=fread(&st ,sizeof(struct student ),1,read))>0){
		for (int i=0;i<3&& p>0;i++){
		FILE * write ;
//		write =fopen ();

		}
	num_file++;
	}
	return num_file ;
}
void insert (struct student newStudent ){
     FILE *write ;
     write=fopen("data.txt","ab");
     fwrite(&newStudent,sizeof(struct student),1,write);
     fclose(write);
     printf("these id is exist !!\n ");
}
