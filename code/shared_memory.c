#include "shared_memory.h"


void shared_memory_arxikh(void){
	
     shm_id=shmget(SHM_KEY,SHM_SIZE,0600| IPC_CREAT);
     if(shm_id<=0){
                   printf("den mporei na dhmiourghthei shared memory\n");
                   //exit(1);
                   }
    else{printf("Epituxhs arxiki shared memory\n");}
}
     
void shared_memory_dhmiourgia(void){
     
	shm_id=shmget(SHM_KEY,SHM_SIZE,0600);
     if(shm_id<=0){
                   printf("den mporei na parei shared memory\n");
                   //exit(1);
                   }
	 else{printf("Epituxhs dhmiourgia shared memory\n");}     
	}
     
void shared_memory_sundesh(void){
	     
	data = shmat(shm_id,NULL,0);
     if(data==(char *)-1){
                    printf("den mporei na sundethei se shared memory\n");
                    //exit(1);
                    }
	 else{printf("Epituxhs sundesh shared memory\n");}     
	}

void shared_memory_aposundesh(void){
     error = shmdt(data);
     if (error==-1){
                    printf("den mporei na aposundethei apo shared memory\n");
                    //exit(1);
                    }
	 else{printf("Epituxhs aposundesh shared memory\n");}    
	 }

void shared_memory_diagrafh(void){
      
	error = shmctl(shm_id,IPC_RMID,NULL);
     if(error==-1){
                   printf("den mporei na diagrapsei thn shared memory\n");
                   //exit(1);
                   }
	 else{printf("Epituxhs diagrafh shared memory\n");}    
	 }


     