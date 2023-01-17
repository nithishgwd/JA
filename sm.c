#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>

int main()
{
 key_t key =ftok("write",65);
 int shmid = shmget(key,1024,0666|IPC_CREAT);
 char *str = (char*)shmat(shmid,(void*)0,0);
 printf("write data");
 gets(str);
 printf("data written in mem is %s ",str);
 shmdt(str);
 return 0;
} 
