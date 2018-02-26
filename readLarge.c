#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>


#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/time.h>

void main()
{
	FILE *fptr;
	printf("reading 1MB file");
	char ch, c;
	fptr = fopen("../../miniproject/1MB.txt", "r");
	if(fptr == NULL)
	{
		printf("cannot open file \n");
		exit(0);
	}
	ch = fgetc(fptr);
	while(ch != EOF)
	{
		printf("%c\n", ch);
		ch = fgetc(fptr);
	}
	fclose(fptr);

	//Write 1 MB file
	FILE *fptr1, *fptr2;
 
    // Open file for reading
    fptr1 = fopen("../../miniproject/1MB.txt", "r");
    if (fptr1 == NULL)
    {
        printf("cannot open file\n");
        exit(0);
    }

    // Open another file for writing
    fptr2 = fopen("../../miniproject/1MBcopy.txt", "w");
    if (fptr2 == NULL)
    {
        printf("cannot open file\n");
        exit(0);
    }
 
    // Read contents from file
    c = fgetc(fptr1);
    while (c != EOF)
    {
        fputc(c, fptr2);
        c = fgetc(fptr1);
    }
 
    printf("\nContents copied");
 
    fclose(fptr1);
    fclose(fptr2);
}
