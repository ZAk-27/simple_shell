#include "main.h"

int main(int ac, char **argv){
  char *prompt = "SZell $ ";
  char *lineptr;
  size_t n = 0; 
  ssize_t nchars_read;

   /* void variables to declare */
  (void)ac; (void)argv;

    /* creating infnite loop */
    while (1){
      printf("%s", prompt);
      nchars_read = getline(&lineptr, &n, stdin);
      /* verify the getline function failure or use CTRL + D or get EOF  */ 
        if (nchars_read == -1){
            printf("SHell is exiting..\n");
            return (-1);
        }

      printf("%s\n", lineptr);

      /* allocated memory will be free */    
    }
      free(lineptr);

  return (0);
}
