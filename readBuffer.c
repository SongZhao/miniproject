



#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>


#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <stdint.h>

#define COPY_BUFFER_MAXSIZE 1048576

void main()
{
  /* ... */

  unsigned char *buffer = NULL;
  buffer = malloc(COPY_BUFFER_MAXSIZE);
  if (!buffer)
      exit(-1);

  FILE *inFp = fopen("10MB.txt", "r");
  if (inFp == NULL)
  {
    printf("cannot open input file\n");
    exit(0);
  } 
  fseek(inFp, 0, SEEK_END);
  uint64_t fileSize = ftell(inFp);
  rewind(inFp);

  FILE *outFp = fopen("../miniproject/10MB2copy.txt", "w");
  if (outFp == NULL)
  {
    printf("cannot open output file\n");
    exit(0);
  } 

  uint64_t outFileSizeCounter = fileSize; 

  /* we fread() bytes from inFp in COPY_BUFFER_MAXSIZE increments, until there is nothing left to fread() */

  do {
      if (outFileSizeCounter > COPY_BUFFER_MAXSIZE) {
          fread(buffer, 1, (size_t) COPY_BUFFER_MAXSIZE, inFp);
          /* -- make changes to buffer contents at this stage
             -- if you resize the buffer, then copy the buffer and 
                change the following statement to fwrite() the number of 
                bytes in the copy of the buffer */
          fwrite(buffer, 1, (size_t) COPY_BUFFER_MAXSIZE, outFp);
          outFileSizeCounter -= COPY_BUFFER_MAXSIZE;
      }
      else {
          fread(buffer, 1, (size_t) outFileSizeCounter, inFp);
          /* -- make changes to buffer contents at this stage
             -- again, make a copy of buffer if it needs resizing, 
                and adjust the fwrite() statement to change the number 
                of bytes that need writing */
          fwrite(buffer, 1, (size_t) outFileSizeCounter, outFp);
          outFileSizeCounter = 0ULL;
      }
  } while (outFileSizeCounter > 0);
  fclose(inFp);
  fclose(outFp);
  free(buffer);
  printf("\nContents copied\n");

}
