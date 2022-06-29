#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <stdbool.h>
int main(){
	setlocale(LC_ALL, "English");
  int inputArray[42], evenNumbersArray[25], oddNumbersArray[25], i=0, j=0, g=0, cattleNumber;
  for(i=0;i<42;i++){
    inputArray[i] = 0;
    evenNumbersArray[i] = 0;
    oddNumbersArray[i] = 0;
  }
  printf("+++++++++++++++ Let´s write the fourty two numbers of cattles +++++++++++++++++++++++++\n");
  printf("\n");
  for(i=0;i<42;i++){
    printf("Write the number of cattle %d:\t", i+1);
    scanf("%d", &cattleNumber);
    printf("\n");
    fflush(stdin);
    system("cls");
    for(j=0;j<42;j++){
      if(cattleNumber == inputArray[j]){
        printf("Number already included:\n");
        printf("Write again the number of cattle %d:\t", i+1);
        scanf("%d", &cattleNumber);
        printf("\n");
      }
    }
    inputArray[i] = cattleNumber;
  }
  system("cls");
  j=0;
  for(i=0;i<42;i++){
    if(inputArray[i] % 2 == 0){
      evenNumbersArray[j] = inputArray[i];
      j++;
    }else{
      oddNumbersArray[g] = inputArray[i];
      g++;
    }
  }
  printf("All of cattle in pasture one: ");
  for(i=0;i<21;i++){
    printf("%d - ", evenNumbersArray[i]);
  }
  printf("\n");
   printf("All of cattle in pasture two: ");
  for(i=0;i<21;i++){
    printf("%d - ", oddNumbersArray[i]);
  }
  return 0;
}
