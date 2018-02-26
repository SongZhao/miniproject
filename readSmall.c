#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>

#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <stdint.h>

#define COPY_BUFFER_MAXSIZE 2048

void main()
{
  /*
  unsigned char *buffer = NULL;
  buffer = malloc(COPY_BUFFER_MAXSIZE);
  if (!buffer)
      exit(-1);
*/
  FILE *inFp = fopen("../miniproject/10MB.txt", "r");
  if (inFp == NULL)
  {
    printf("cannot open input file\n");
    exit(0);
  } 
  fseek(inFp, 0, SEEK_END);
  uint64_t fileSize = ftell(inFp);
  rewind(inFp);

  FILE *outFp1, *outFp2;
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
char path1[50] = "o";
char path2[12] = "1";
char path3[50] = "2";
for(i = 0; i < 20; i++){
  unsigned char *buffer = NULL;
  unsigned char *buffer1 = NULL;
  buffer = malloc(COPY_BUFFER_MAXSIZE);
  buffer1 = malloc(COPY_BUFFER_MAXSIZE);
  uint64_t outFileSizeCounter = fileSize; 
  if (!buffer)
      exit(-1);
  if (!buffer1)
      exit(-1);
  strcat(path1,path2);
  strcat(path3,path2);
  outFp1 = fopen(path1 , "w");
  //printf("path is %s", path1);	 
  outFp2 = fopen(path3 , "w");
  if (outFp1 == NULL)
  {              
     printf("cannot open output file1, path is %s\n", path1);
     exit(0);
  }
  do {   

      if (outFileSizeCounter > COPY_BUFFER_MAXSIZE) {
          fread(buffer, 1, (size_t) COPY_BUFFER_MAXSIZE, inFp);
          fwrite(buffer, 1, (size_t) COPY_BUFFER_MAXSIZE, outFp1);
          outFileSizeCounter -= COPY_BUFFER_MAXSIZE;
	  fsync(outFp1);
          fread(buffer1, 1, (size_t) COPY_BUFFER_MAXSIZE, inFp);
          fwrite(buffer1, 1, (size_t) COPY_BUFFER_MAXSIZE, outFp2);
          fsync(outFp2);
         // printf("write\n");
      }
      else {
          fread(buffer, 1, (size_t) outFileSizeCounter, inFp);
          fwrite(buffer, 1, (size_t) outFileSizeCounter, outFp1);
          fread(buffer1, 1, (size_t) COPY_BUFFER_MAXSIZE, inFp);
          fwrite(buffer1, 1, (size_t) COPY_BUFFER_MAXSIZE, outFp2);
          outFileSizeCounter = 0ULL;
          fsync(outFp1);
      }
  } while (outFileSizeCounter > 0);
  fclose(outFp1);
  fclose(outFp2);
  free(buffer);
  free(buffer1);
  }
  fclose(inFp);
  printf("\nContents copied\n");

}
