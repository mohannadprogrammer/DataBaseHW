#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
void mergSort (char *);

int cutFile(char *);
void merg(int );
void internal_sort(char *);
void mergFile(char *, char *,int);
int main ()
{
	mergSort("data.txt");

}
void internal_sort(char * file ){
	struct student s[3]={0,"",""};
	size_t p;
	int i=0;	
	FILE *read =fopen(file,"rd");
	while ((p=fread(&s[i],sizeof(struct student),1,read))>0){
			i++;
	}
	fclose(read);
	FILE * write =fopen(file,"wd");
	for (int i =0;i<2;i++){
		
		if (s[i].id > s[i+1].id && s[i].id != 0 &&s[i+1].id != 0)
		{
			struct student temp =s[i];
			s[i]=s[i+1];
			s[i+1]=temp;
		}
	}
	for (int i =0;i<3;i++){
		if (s[i].id !=0)
			fwrite (&s[i],sizeof(struct student ),1,write);
	}
	fclose(write);
}
void mergSort (char * file){
	int num_file =cutFile(file);
	merg(num_file);
	printf("skdflsd");
}
int cutFile (char *file ){

	FILE * read ;
	read =fopen (file,"rd");
	size_t p;
	int num_file=0;
	struct student st ={0,"",""};
	p=fread(&st ,sizeof(struct student ),1,read);
	while (p>0){
		char name[] = "0.txt";		
		name[0]=(char)num_file+65;
		for (int i=0;i<3&& p>0;i++){
		FILE * write ;
		name[0]=(char)num_file+65;
		write =fopen (name,"ab");
		fwrite (&st,sizeof(struct student ),1,write);
		p=fread(&st ,sizeof(struct student ),1,read);
		fclose(write);
		}
		internal_sort(name);
		num_file++;
	}
	fclose(read);
	return num_file ;
}
void merg(int num_file){
	int i =num_file;
	int h =0;
	
	while (num_file > 1){
		h=0;
		for ( int k=0; k <= num_file/2;){		
			char file1[]="0.txt";
			char file2[]="0.txt";
			file1[0]=(char)k+65;
			file2[0]=(char)k+66;
			mergFile(file1,file2,h);
			k=k+2;	
			h++;
		}
		if (num_file % 2==0){
			num_file=num_file/2;
		}else{
			num_file=(num_file/2)+1;
			char file1[]="0.txt";
			char file2[]="0.txt";
			file2[0]=(char)num_file+65;
			file1[0]=(char)i+66;
			rename(file1,file2);
			i=num_file;
		}
	}
	rename("A.txt","data2.txt");
}
void mergFile (char * file1 , char * file2 , int merg_num){
	FILE * p1 ;
	FILE * p2 ;
	FILE *write ;
	size_t c1;
	size_t c2;
	struct student st1={0,"",""};
	struct student st2={0,"",""};
	
	p1 =fopen(file1,"rb");
	p2 =fopen(file2,"rb");
	write=fopen ("temp.txt","ab");
	
	c1 =fread(&st1,sizeof(struct student ),1,p1);
	c2 =fread(&st2,sizeof(struct student ),1,p2);
	
	while (c1 >0 && c2 > 0){
		if (st1.id < st2.id){
			fwrite(&st1,sizeof(struct student ),1,write);
			c1=fread(&st1,sizeof(struct student ),1,p1);
		}else{
			fwrite(&st2,sizeof(struct student ),1,write);
			c2=fread(&st2,sizeof(struct student ),1,p2);
		}
	}
	while (c1 >0 ){
		fwrite(&st1,sizeof(struct student ),1,write);
		c1=fread(&st1,sizeof(struct student ),1,p1);
	}
	while (c2 >0 ){
		fwrite(&st2,sizeof(struct student ),1,write);
		c2=fread(&st2,sizeof(struct student ),1,p2);
	}
	fclose(write);
	fclose(p2);
	fclose(p1);
	char del1 [] ="rm ";
	strcat(del1,file1);
    	char del2[]="rm ";
 	strcat(del2,file2);
    	system(del1);
	system(del2);
	char temp[]="0.txt";
	temp[0]=(char)merg_num+65;
	rename("temp.txt",temp);
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

