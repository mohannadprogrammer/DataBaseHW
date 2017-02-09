#include<stdio.h>
#include<stdlib.h>
//student struct 

struct student {
    int id;
    char name[10];
    char dep[10];
};

//prototypes 
void meragSort (char *);
int cutFile(char *);

int main ()
{
	return 0;
}

int cutFile (char *file )
{

	FILE * read ;
	read =fopen (file,"rd");
	int num_file=0;
	struct student st ={0,"",""};
	while (read()){

	}
	return num_file ;
}
