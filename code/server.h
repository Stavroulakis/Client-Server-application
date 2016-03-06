//perilamvanoume  ta panta gia tn server kai s dhlwseis twn sunarthisewn ths server_function
#ifndef SERVER_H
#define SERVER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
//aparaithto gia socket kai shared_memory
#include <sys/types.h>	
#include <time.h>
//aparaithto  gia ta semaphores
#include <sys/stat.h>
#include <semaphore.h>	
#include <fcntl.h>
//aparaithto  gia signals
#include <signal.h>
#include <sys/wait.h>
//standar times
#define Nthl 10
#define Nbank 4
#define Tseat 6
#define Tcardc 2
#define Twait 10
#define Ttransf 30
//onoma semaphore
#define SEM_NAME "Theatro"
//pointer tupou sem_t pou theloume gia ts semaphore
sem_t *mysemaphore;
void sig_child(int siga);
void sig_server(int sigb);
pid_t childpid;
//metavlhtes pou xreiazomate
int i,eisitiria,Zwnh,pistotikh_karta,j,t,ekgurh;
int k;
char *la;//deikhs p deixnei stn mnhmh
char *data;//deikhs p deixnei stn mnhmh
struct krathsh *kr;//deikths tupoy struct pou deixnei sthn struct kathsh
struct ergazomenoi *erg;//deikths tupoy struct pou deixnei sthn struct ergazomenoi
struct krathsh{
	int pelates_anamonh[100];
	int sun_poso;//sunoliko poso theatrou
	int kostos;//poso kathe client
	int Z_A[100]; //zwnh A
	int Z_B[130];//zwnh B
	int Z_C[180];//zwnh C
	int Z_D[230];//zwnh D
	int gemath_za;
	int gemath_zb;
	int gemath_zc;
	int gemath_zd;
	int gemato;
	int id;
	int epitixia;
	int teleutaia_thesi;
	int anamonh;
};

struct ergazomenoi{
	int thlef[Nthl];
	int suskeues_bank[Nbank];
	int thl_anamonh[100];
	int id_erg;
	int b_anamonh;
};

void arxikopoihsh(void);
void epik_thlefwnhth(void);
void krathseis_eisithriwn(void);
void oloklhrwsh_diadikasias(void);
void trapeza(void);
#endif