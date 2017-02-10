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
void displayl(char *);


//prototypes 
void meragSort (char *);
int cutFile(char *);

int main ()
{
	//struct student s ={0,"ddd","dd"};
	//scanf("%d",&s.id);
	//insert (s);
	display();
	printf ("\n \n \n ");
	displayl("A.txt");
	printf ("\n \n \n ");
	displayl("B.txt");
	printf ("\n \n \n ");
	displayl("C.txt");
	//cutFile ("data.txt");
}

int cutFile (char *file ){

	FILE * read ;
	read =fopen (file,"rd");
	size_t p;
	int num_file=0;
	struct student st ={0,"",""};
	p=fread(&st ,sizeof(struct student ),1,read);
	while (p>0){
		for (int i=0;i<3&& p>0;i++){
		FILE * write ;
		char name[] = "0.txt";
		name[0]=(char)num_file+65;
		write =fopen (name,"ab");
		fwrite (&st,sizeof(struct student ),1,write);
		p=fread(&st ,sizeof(struct student ),1,read);
		fclose(write);
		}
	num_file++;
	}
	fclose(read);
	return num_file ;
}
void insert (struct student newStudent ){
     FILE *write ;
     write=fopen("data.txt","ab");
     fwrite(&newStudent,sizeof(struct student),1,write);
     fclose(write);
     printf("these id is exist !!\n ");
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
void displayl (char * m){
    FILE *pointer ;
    size_t p ;
    pointer = fopen (m, "rb");
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
