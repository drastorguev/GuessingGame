#include <stdio.h>

void transfer(int n, char from, char to, char temp); /* function prototype */

void main( )
{
int n;
printf("Welcome to the Towers of Hanoi\n");
printf("How any disks?" );
scanf("%d", &n);
printf("\n");
transfer( n, 'L' , 'R' , 'C');
}

void transfer( int n, char from, char to, char temp)
/* n = number of disks
from = origin
to = destination
temp = temporary storage */
{
  if(n > 0) {
/* move n-1 disks from t h e i r o r i g i n to the temporary pole */
    transfer(n-1, from, temp, to);
/* move the nth disk from i t s o r i g i n t o i t s destination */
    printf("Move disk %d from %c to %c\n", n, from, to );
/* move the n-1 disks from the temporary pole t o t h e i r destination */
    transfer(n-1, temp, to, from);
  }
  return;
}
