



#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>

#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <stdint.h>

#define COPY_BUFFER_MAXSIZE 1048576

void main()
{
  /*

  unsigned char *buffer = NULL;
  buffer = malloc(COPY_BUFFER_MAXSIZE);
  if (!buffer)
      exit(-1);
*/
  FILE *inFp = fopen("10MB.txt", "r");
  if (inFp == NULL)
  {
    printf("cannot open input file\n");
    exit(0);
  } 
  fseek(inFp, 0, SEEK_END);
  uint64_t fileSize = ftell(inFp);
  rewind(inFp);

  FILE *outFp;
/*
  FILE *outFp = fopen("../miniproject/10MB2copy.txt", "w");
  if (outFp == NULL)
  {
    printf("cannot open output file\n");
    exit(0);
  } 
*/
  uint64_t outFileSizeCounter = fileSize; 

  /* we fread() bytes from inFp in COPY_BUFFER_MAXSIZE increments, until there is nothing left to fread() */

int i;
char c[1];
char path1[50] = "outputfile";
char path2[12] = "1";
for(i = 0; i < 10; i++){
  unsigned char *buffer = NULL;
  buffer = malloc(COPY_BUFFER_MAXSIZE);
  uint64_t outFileSizeCounter = fileSize; 
  if (!buffer)
      exit(-1);
  strcat(path1,path2);
  outFp = fopen(path1 , "w");
  printf("path is %s", path1);	 
  if (outFp == NULL)
  {              
     printf("cannot open output file\n");
     exit(0);
  }
  do {   

      if (outFileSizeCounter > COPY_BUFFER_MAXSIZE) {
          fread(buffer, 1, (size_t) COPY_BUFFER_MAXSIZE, inFp);
          fwrite(buffer, 1, (size_t) COPY_BUFFER_MAXSIZE, outFp);
          outFileSizeCounter -= COPY_BUFFER_MAXSIZE;
      }
      else {
          fread(buffer, 1, (size_t) outFileSizeCounter, inFp);
          fwrite(buffer, 1, (size_t) outFileSizeCounter, outFp);
          outFileSizeCounter = 0ULL;
      }
  } while (outFileSizeCounter > 0);
  fclose(outFp);
  free(buffer);
  }
  fclose(inFp);
  printf("\nContents copied\n");

}
