#include "server.h"
#include "socket.h"
#include "shared_memory.h"

int main(void ){

//otan emfanistei ena SIGCHLD shma tote ekteleiete h sig_child
signal(SIGCHLD,sig_child);
//otan emfanistei ena SIGINT signal tote kanoyme exit ton server
signal(SIGINT,sig_server);
//dhmiourgia shared_memory
shared_memory_arxikh();
//sundeoume mia diadikasia sthn shared_memory
shared_memory_sundesh();
//dhmiourgoume semaphore
semaphore_dhmiourgia();
//arxikopoihoume to systhma mas dhmiourgontas pinakes gia ts zwnes twn eisithriwn kai oti allo xreiazomaste
arxikopoihsh();
//dhmiourgoume socket
socket_klish();
//arxikopoioume to socket
socket_arxikop();
//dinoume onoma st socket
socket_bind();
//akouei aithma apo client gia sundesh
socket_listen();
  do{
	socket_dexetai();	
	//dhmiourgoume me thn fork ena paidi
	childpid=fork();
	if(childpid==0){
		//aposundeoume to socket tou patera kai dhmiourgoume shared_memory kai tn sundeoume me to paidi
		socket_aposundesh_parent();
		shared_memory_dhmiourgia();
		shared_memory_sundesh();
		read(connsd,&eisitiria,sizeof(eisitiria));
		read(connsd,&Zwnh,sizeof(Zwnh));
		read(connsd,&pistotikh_karta,sizeof(pistotikh_karta));
		//kanoume lock tn semaphore gia n grapsoume tn krathsh sthn mnhmh
		//sem_wait(mysemaphore);
		do{
			sem_wait(mysemaphore);
			//ginete h epikoinwnia tou client me tous thlefwnites
			epik_thlefwnhth(); 
			sem_post(mysemaphore);
			//ama o client einai se anamonh stelnei mhnuma o server ston client
			write(connsd,&kr->anamonh,sizeof(kr->anamonh));
			if(kr->anamonh==1){					
				kr->anamonh=0;
			}
		}while(kr->anamonh==1);
			
		sem_wait(mysemaphore);//afou grafoume stn mnhmh mesw ths sunarthshs trapeza kanoume lock tn semaphore 
		trapeza();
		sem_post(mysemaphore);//kanoume unlock tn semaphore
		
		sem_wait(mysemaphore);//afou grafoume stn mnhmh mesw ths sunarthshs trapeza kanoume lock tn semaphore 
		krathseis_eisithriwn();
		sem_post(mysemaphore);//kanoume unlock tn semaphore		
		printf("To sunoliko kerdos tou Theatrou ws twra einai: %d EURO\n",kr->sun_poso);
		printf("\n");
		//stelnei times stn client gia n vgalei mhnumata
		write(connsd,&kr->epitixia,sizeof(kr->epitixia));
		write(connsd,&kr->teleutaia_thesi,sizeof(kr->teleutaia_thesi));
		write(connsd,&kr->kostos,sizeof(kr->kostos));
		write(connsd,&kr->id,sizeof(kr->id));
		write(connsd,&kr->gemath_za,sizeof(kr->gemath_za));
		write(connsd,&kr->gemath_zb,sizeof(kr->gemath_zb));
		write(connsd,&kr->gemath_zc,sizeof(kr->gemath_zc));
		write(connsd,&kr->gemath_zd,sizeof(kr->gemath_zd));
		write(connsd,&kr->gemato,sizeof(kr->gemato));
		write(connsd,&ekgurh,sizeof(ekgurh));
		sem_wait(mysemaphore);//afou grafoume stn mnhmh mesw ths sunarthshs trapeza kanoume lock tn semaphore 
		oloklhrwsh_diadikasias();
		sem_post(mysemaphore);//kanoume unlock tn semaphore
		//kanei exit to paidi
		exit_child();
		exit(0);
		
	}
	socket_aposundesh_child();
   }while(kr->gemato==0);//otan gemisei to theatro o server termatizei automata
} 