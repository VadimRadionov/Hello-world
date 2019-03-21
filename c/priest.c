#include <stdio.h>

char str[] = "у попа была собака, он её любил\n\
она съела кусок мяса, он её убил\n\
в землю закопал\n\
и надпись написал, что ";

void rhyme() { 
  printf("%s", str);
  rhyme();
}

int main() { rhyme(); }
