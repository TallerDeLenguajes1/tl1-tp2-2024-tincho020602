#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20
int main(){ 
int i;
//<<<<<<< HEAD
srand(time(NULL));

//=======
float vt[N];
srand(time(NULL));
//>>>>>>> Opcion_2
for(i = 0;i<N; i++)
{
*(vt+1)=1+rand()%100;
printf("%2.f ", *(vt+1));
}
return 0;
}
