/* do not add other includes */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

double getTime(){
  struct timeval t;
  double sec, msec;
  
  while (gettimeofday(&t, NULL) != 0);
  sec = t.tv_sec;
  msec = t.tv_usec;
  
  sec = sec + msec/1000000.0;
  
  return sec;
}
 
/* for task 1 only */
void usage(void)
{
	fprintf(stderr, "Usage: cachetest1/2 [--repetitions M] [--array_size N]\n");
	exit(1);
}

int main (int argc, char *argv[])
{
  double t1, t2; 
  
  /* variables for task 1 */
  unsigned int M = 10000;
  unsigned int N = 1048576; 
  unsigned int i;
	
  /* declare variables; examples, adjust for task */
	int *a;
	int *b;
	int sum = 0;


  /* parameter parsing task 1 */
  for(i=1; i<(unsigned)argc; i++) {
	  if (strcmp(argv[i], "--repetitions") == 0) {
		  i++;
		  if (i < argc)
			  sscanf(argv[i], "%u", &M);
		  else
			  usage();
	  } else if (strcmp(argv[i], "--array_size") == 0) {
		  i++;
		  if (i < argc)
			  sscanf(argv[i], "%u", &N);
		  else
			  usage();
	  } else usage();
  }

    
  /* allocate memory for arrays; examples, adjust for task */
    a = malloc(N * sizeof(int));
    b = malloc(N * sizeof(int));

	 /* initialise arrray elements */
    for (i = 0; i < N; i++) {
        b[i] = i;
        a[i] = i;
    }

    t1 = getTime();
  /* code to be measured goes here */
  /***************************************/
    for (i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            sum += a[b[j]];
        }
    }

  /***************************************/
	t2 = getTime(); 
  
  /* output; examples, adjust for task */
  printf("time: %6.2f secs\n",(t2 - t1));

  /* IMPORTANT: also print the result of the code, e.g. the sum, 
   * otherwise compiler might optimise away the code */
    printf("The sum is: %d\n", sum);
    printf("Array size N: %d and M: %d\n",N,M);
  
  /* free memory; examples, adjust for task */
    free(a);
    free(b);

  return 0;  
}
