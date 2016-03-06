#ifndef SHARED_MEMORY_H
#define SHARED_MEMORY_H

#include "server.h"
//perilamvanei oti einai aparethto gia thn shared memory
#include <sys/types.h>
// perilamvanei to use system V style IPC
#include <sys/ipc.h>
//perilamvanei dilwseis toy shm commands
#include <sys/shm.h>
//orizei shm key AM:5076
#define SHM_KEY 5076
//orizei megethos toy smh segment
#define SHM_SIZE 5000
//metavlhtes pou kratane to id tou shared memory segment
int shm_id;
//xrisimopoioume tn error giA elenxous
int error;
//pointer se char xrisimopouountai stn shared_memory.Deixnoun panta  sthn arxh ts shered memory
 char *data;
 //dhmiourgei shared memory alla kaleite prin apo thn prwth fork()
 void shared_memory_arxikh(void);
 //dhmiourgei shared memory gia kathe diergasia paidi
 void shared_memory_dhmiourgia(void);
 //sundeei mia diergasia sthn shared memory
 void shared_memory_sundesh(void);
 //aposundeei mia diergasia apo thn shared memery
 void shared_memory_aposundesh(void);
 //diagrafei thn shared memory
 void shared_memory_diagrafh(void);

#endif