#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 10

void generatePseudorandom (int prand[SIZE]) {
  srand(time(NULL));
  for(int i=0; i<SIZE; i++)
    prand[i] = rand()%SIZE;
}
void encrypt( int prand[SIZE], int numberToEncrypt[SIZE] ) {
  for (int i=0; i<SIZE; i++)
    numberToEncrypt[i] = numberToEncrypt[i] ^ prand[i];
}
void decrypt ( int prand[SIZE], int numberToDecrypt[SIZE] ) {
  for (int i=0; i<SIZE; i++)
    numberToDecrypt[i] = numberToDecrypt[i] ^ prand[i];
}
void printLoop ( int array[SIZE] ){
  for(int i=0; i<SIZE; i++)
    printf("%d ", array[i]);
}

int main()
{
  int prand[SIZE], number[SIZE] = {5,3,2,4,5,6,2,2,3,9}; //edit to SIZE

  printf("Original Value:     ");
  printLoop(number);

  generatePseudorandom(prand);
  printf("\nPseudorandom Value: ");
  printLoop(prand);

  printf("\nEncrypted Value:    ");
  encrypt( prand, number );
  printLoop(number);

  printf("\nDecrypted Value:    ");
  decrypt( prand, number );
  printLoop(number);

  return 0;
}
