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
 


int main (int argc, char *argv[])
{
  double t1, t2; 
  
  /* variables for task 2 */

  unsigned int N = 1000; 
  unsigned int i;
  unsigned int j;
  unsigned int k;
  
	
  /* declare variables; examples, adjust for task */
	double **a;
	double **b;
	double **c;
	double **temp;
	double sum;


    
  /* allocate memory for arrays; examples, adjust for task */
    a = (double **)malloc(N * sizeof(double *));
    b = (double **)malloc(N * sizeof(double *));
    c = (double **)malloc(N * sizeof(double *));
    temp = (double **)malloc(N * sizeof(double *));
    
    for(i = 0; i < N; i++){
    	a[i] = (double *)malloc(N * sizeof(double));
    	b[i] = (double *)malloc(N * sizeof(double));
    	c[i] = (double *)malloc(N * sizeof(double));
    	temp[i] = (double *)malloc(N * sizeof(double));
    }
    

	 /* initialise arrray elements */
    for (i = 0; i < N; i++) {
    	for(j = 0; j < N; j++){
          a[i][j] = i;
          b[i][j] = i;
          temp[i][j] = 1;
        }
    }

    t1 = getTime();
    
  /* code to be measured goes here */
  /***************************************/
   for (i = 0; i < N; i++) {
         for (j = 0; j < N; j++) {
	
         	temp[j][i] = b[i][j];
 
	   }
     }

  
    for (i = 0; i < N; i++) {
         for (j = 0; j < N; j++) {
         sum = 0.0;
               for (k = 0; k < N; k++) {
                    sum += (a[i][k] * temp[j][k]);
                }
                c[i][j] = sum;
            }
        }

  /***************************************/
	t2 = getTime(); 
  
  /* output; examples, adjust for task */
  printf("time: %6.2f secs\n",(t2 - t1));

  /* IMPORTANT: also print the result of the code, e.g. the sum, 
   * otherwise compiler might optimise away the code */
    printf("The first element is: %f and last element is: %f\n", c[0][0], c[999][999]);

  
  /* free memory; examples, adjust for task */
    free(a);
    free(b);
    free(c);

  return 0;  
}
