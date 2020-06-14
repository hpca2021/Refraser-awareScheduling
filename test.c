#include <stdio.h>
#include <stdlib.h>

int main(){
  int *prioArr;
  int numOfProcess = 0;
  int i = 0;
  FILE *prioFile;
  prioFile = fopen("process_prio_map.dat", "r");

  fscanf(prioFile, "%d\n", &numOfProcess);

  if (numOfProcess <= 0) return 1;
  else
    prioArr = (int*) malloc(sizeof(int)*numOfProcess);

  for (i = 0; i < numOfProcess; i++) {
    fscanf(prioFile, "%d,", &prioArr[i]);
    printf("%d,", prioArr[i]);
  }

  printf("\nCheck %d \n", numOfProcess);

  free(prioArr);
  fclose(prioFile);
}
