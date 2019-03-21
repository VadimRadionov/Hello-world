#include <stdio.h>

char str0[] = "No more bottles of beer on the wall, no more bottles of beer.\n\
We've taken them down and passed them around; now we're drunk and passed out!\n";

char str1[] = "1 bottle of beer on the wall, 1 bottle of beer.\n\
Take one down, pass it around, no more bottles of beer on the wall...\n";

void rhyme(int bottle_count) { 
  if (bottle_count == 0) { printf("%s", str0); return; }
  else if (bottle_count == 1)  { printf("%s", str1); }
  else
    { printf("%d bottles of beer on the wall, %d bottles of beer.\n", bottle_count, bottle_count); 
      if (bottle_count == 2)
	{ printf("Take one down, pass it around, 1 bottle of beer on the wall...\n"); }
      else
	{ printf("Take one down, pass it around, %d bottles of beer on the wall...\n", bottle_count-1); }
    }
  rhyme(bottle_count-1);
}

int main() { rhyme(99); }
