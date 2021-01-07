#include <stdio.h>
#include <pthread.h>
#define num 7


void *func(void *id_arg)
{
 
  int id_2;
  id_2=(int)id_arg;
  
  
  printf("Hello SCR. Written by thread %ld\n", id_2);

  pthread_exit(NULL);
}

int main (int arc, char *argv[])
{
  int err;
  pthread_t id[num];
  for(int i=0; i<num; ++i)
    {
      err=pthread_create(&id[i], NULL, func, (void*)&id[i]);

      if(err)
	{
	  printf("Error!");
	}
      
    }
  
  pthread_exit(NULL);
}
