#include <stdio.h>
#include <unistd.h>
int main()
{
 /* cria um processo-filho */
 fork();
 /* cria outro processo-filho */
 fork();
 /* e cria um outro */
 fork();
 return 0;
}
