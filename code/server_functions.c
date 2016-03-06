//periexei xrhsimes sunarthseis

#include "server.h"
#include "socket.h"
#include "shared_memory.h"

//dhmiourgoume semaphore
void semaphore_dhmiourgia(void){
	//dhmiourgoume thn semaphore kai pernei to onoma apo to SEM_NAME
	//to O_CREAT dhmiorgei mia  semaphore ama dn yparxei
	//to O_RDWR anoigei thn semaphoro kai mporei na kanei anagnwsh kai eggrafh
	//to S_IRUSR o  xrhsths mporei na kanei anagnwsh
	//to S_IWUSR o xrhsths mporei na kanei eggrafh
	//to  1 einai h arxikh timh tou semaphore
	mysemaphore = sem_open(SEM_NAME, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR, 1);
	//h sem_open epistefei thn dieuthinsh ths pio  prosfaths semaphore kai an exei ginei kapoio lathos mas to anaferei
	if(mysemaphore == SEM_FAILED){
		printf("Den mporei na dhmiourgisei semaphore\n");
		exit(1);
	}
}



//diadikasia gia eksodo apo apo paidi
void exit_child(void){
	//kleineoume tn semaphore me to onoma mysemaphore
	sem_close(mysemaphore);
	void socket_aposundesh_child();
	void shared_memory_aposundesh();
}

 void sig_child(int siga) {
        
	pid_t pid;
        int stat;
	
/*Perimenei mexri mia diergasia na stamathsei kai otan auto symvei emfanizei 
katallhlo mhnyma
*/
      while ( ( pid = waitpid( -1, &stat, WNOHANG ) )> 0 ) {		
		
	printf( "Child with pid %d terminated\n", pid );
        }
}
void sig_server(int sigb) {
	//ektelesh();
//Xrhsimopoiei th shemaforo me to onoma mysemaphore 	
	sem_close(mysemaphore);					
//Aposyndeei thn shemaforo me onoma SEM_NAME
	sem_unlink(SEM_NAME);						
	socket_aposundesh_parent();
	shared_memory_aposundesh();
	shared_memory_diagrafh();
	exit(0);
} 
//arxikopoioume olo to susthma mas.Kathe struct desmeuei ena xwro ths mnhmhs
void arxikopoihsh(void){
	
	la = data +1;
	kr=data;
	kr->id=0;
	for(i=0;i<100;i++){
		kr->Z_A[i]=0;
	}
	for(i=0;i<130;i++){
		kr->Z_B[i]=0;
	}
	for(i=0;i<180;i++){
		kr->Z_C[i]=0;
	}
	for(i=0;i<230;i++){
		kr->Z_D[i]=0;
	}
	for(i=0;i<100;i++){
		kr->pelates_anamonh[i]=0;
	}
	kr->epitixia=0;
	kr->gemath_za=0;// to 0 shmenei oti h zwnh  dn exei gemisei
	kr->gemath_zb=0;// to 0 shmenei oti h zwnh  dn exei gemisei
	kr->gemath_zc=0;// to 0 shmenei oti h zwnh  dn exei gemisei
	kr->gemath_zd=0;// to 0 shmenei oti h zwnh  dn exei gemisei
	kr->gemato=0;// to 0 shmenei oti to theatro  dn exei gemisei
	kr->anamonh=0;//h anamonh tou client gia sundesh ston thlefwnith
	
	erg=la +sizeof(struct krathsh) +1;
	for(i=0;i<Nthl;i++){
		erg->thlef[i]=0;
	}
	for(i=0;i<Nbank;i++){
		erg->suskeues_bank[i]=0;
	}
	
		erg->b_anamonh=0;
	
j=0;

}
//edw ginete h epikoinwnia tou kathe client me tous thlefwnites
void epik_thlefwnhth(void){
	
	
	kr->id=kr->id +1;//to id kathe client
	kr->epitixia=0;//arxikopoihsh ths metavlhths ama ginei h krathsh eisithriwn swsta
	
	for(i=0;i<Nthl;i++){//psaxnei na vrei eleuthero thlefwnith kai an nai tou ekxwrei to id tou client
		if(erg->thlef[i]==0){
			erg->thlef[i]=kr->id;
			kr->anamonh=0;
			erg->id_erg=i;
			break;
		}
		else{
			j++;
		}
	}
	if(j==Nthl){//an mpei edw shmainei oti oloi oi thlefwnhtes einai apasxolhmenoi kai o client mpainei se anamonh
		kr->anamonh=1;
		for(i=0;i<100;i++){
			if(kr->pelates_anamonh[i]==0){
				kr->pelates_anamonh[i]=kr->id;
				
				break;
			}
		}
		
	}

}
//edw mpainei o kathe thlefwnths kai psaxnei an uparxoun kenes theseis gia na eksuphrethsoun tous client 
//kai an nai tous vazeis stis katalalles theseis
void krathseis_eisithriwn(void){
	
	kr->kostos=0;//to kostos pou tha plhrwsei o kathe pelaths
	//h metavlhth pistotikh_karta mporei n parei times apo 1-10.epomenos h mia timh(s eauthn tn periptwsh h timh 1)
	//exei pithanothtes n tuxei 10%.Opote oi pithanothtes h pistotikh_karta na einai ekgurh
	// dld n mn exei timh 1 einai 90%	
	if(ekgurh!=1){
		sleep(Tseat);//o xronos p xreiazete o thlefwnthths gia n vrei theseis sto theatro
		if(Zwnh==1 && kr->gemath_za!=1){
			
			for(i=0;i<eisitiria;i++){
				for(j=0;j<100;j++){
					if(j==99 && kr->Z_A[j]!=0){
						kr->gemath_za=1;//an gemisei h zwnh A
					}
					else if(kr->Z_A[j]==0){//an vrei kenh thesh ekxwrei se authn to id tou pelath
						kr->Z_A[j]=kr->id;
					 	kr->kostos=kr->kostos +50;
						kr->epitixia=1;
						kr->teleutaia_thesi=j;
						break;
					}
				}
				
			}

		}
		else if((Zwnh==2 ||Zwnh==3) && kr->gemath_zb!=1){
			
			for(i=0;i<eisitiria;i++){
				for(j=0;j<130;j++){
					if(j==129 && kr->Z_B[j]!=0){
						kr->gemath_zb=1;//an gemisei h zwnh B
					}
					else if(kr->Z_B[j]==0){//an vrei kenh thesh ekxwrei se authn to id tou pelath
						kr->Z_B[j]=kr->id;kr->epitixia=1;
						kr->kostos=kr->kostos + 40;
						kr->epitixia=1;
						kr->teleutaia_thesi=j;
						break;
					}
				}
			}
		}
		else if((Zwnh==4 || Zwnh==5 || Zwnh==6) && kr->gemath_zc!=1){
			
			for(i=0;i<eisitiria;i++){
				for(j=0;j<180;j++){
					if(j==179 && kr->Z_C[j]!=0){
						kr->gemath_zc=1;//an gemisei h zwnh C
					}
					else if(kr->Z_C[j]==0){//an vrei kenh thesh ekxwrei se authn to id tou pelath
						kr->Z_C[j]=kr->id;
						kr->kostos=kr->kostos +35;
						kr->epitixia=1;
						kr->teleutaia_thesi=j;
						break;
					}
				}
			}
		}
		else if((Zwnh==7 || Zwnh==8 || Zwnh==9 || Zwnh==10) && kr->gemath_zd!=1 ){
			
			for(i=0;i<eisitiria;i++){
				for(j=0;j<230;j++){
					if(j==229 && kr->Z_D[j]!=0){
						kr->gemath_zd=1;//an gemisei  h zwnh D
					}
					else if(kr->Z_D[j]==0){//an vrei kenh thesh ekxwrei se authn to id tou pelath
						kr->Z_D[j]=kr->id;
						kr->kostos=kr->kostos +30;
						kr->epitixia=1;
						kr->teleutaia_thesi=j;
						break;
					}
				}
			}
		}
		if(kr->gemath_za==1 && kr->gemath_zb==1 && kr->gemath_zc==1 && kr->gemath_zd==1){
			kr->gemato=1;//an oles einai zwnes einai gemates tote to theatro gemise
		}
		kr->sun_poso=kr->sun_poso + kr->kostos;//to sunoliko kerdos tou theatrou mexri ekeinh thn stigmh


	}	
	//edw tupwnete to theatro..kathe thesh periexei to id tou client
	printf("\n");
	printf("THEATRO!!!!\n");
	printf("-------------------------------------------------------------\n");
	int k=0;
	printf("A Zwnh:\n");
	for(i=0;i<10;i++){
		for (j=0; j<10; j++){
			if (kr->Z_A[k]!= 0) printf("%d",kr->Z_A[k]);
			else printf("*");
			k++;
		}

		printf("\n");
	}

	printf("\n");

	k=0;
	printf("B Zwnh:\n");
	for(i=0;i<10;i++){
		for (j=0; j<13; j++){
			if (kr->Z_B[k] != 0) printf("%d",kr->Z_B[k]);
			else printf("*");
			k++;
		}
		printf("\n");
	}

	printf("\n");
	k=0;
	printf("C Zwnh:\n");
	for(i=0;i<10;i++){
		for (j=0; j<18; j++){
			if (kr->Z_C[k] != 0) printf("%d",kr->Z_C[k]);
			else printf("*");
			k++;
		}
		printf("\n");
	}

	printf("\n");
	k=0;
	printf("D Zwnh:\n");
	for(i=0;i<10;i++){
		for (j=0; j<23; j++){
			if (kr->Z_D[k] != 0) printf("%d",kr->Z_D[k]);
			else printf("*");
			k++;
		}
		printf("\n");
	}

	printf("\n");
	printf("-------------------------------------------------------------\n");
}
//sundeontai oi thlefwnites me tn trapeza kai elenxete h pistotikh_karta
void trapeza(void){
	t=0;
	for(i=0;i<Nbank;i++){//elenxei ama uparxei diathesimh suskeuh gia n sundethei o thlefwniths
		if(erg->suskeues_bank[i]==0){
			erg->suskeues_bank[i]=kr->id;
			break;
		}else{t++;}
	}
	sleep(Tcardc);//xronos m kanei elenxo gia thn karta
	if(pistotikh_karta!=1){ //edw elenxete h karta
		ekgurh=0;
	}else{ekgurh=1;}
	//edw mpainoun oi thlefwnites se anamonh
	if(t=i+1){
		erg->b_anamonh=1;
		for(j=0;j<100;j++){
			if(erg->thl_anamonh[j]==0){
				erg->thl_anamonh[j]=kr->id;
				break;
			}
		}
	}


}

//edw oloklhrwnete h ergasia.apodesmeuetai o thlefwniths me tn client pou eksuphretei
void oloklhrwsh_diadikasias(void){
	
	for(i=0;i<100;i++){
			if(kr->pelates_anamonh[i]==kr->id){
				kr->pelates_anamonh[i]=0;			
			}
	}
	for(i=0;i<Nbank;i++){
		if(erg->suskeues_bank[i]==kr->id){
			erg->suskeues_bank[i]=0;			
		}
	}		
}
