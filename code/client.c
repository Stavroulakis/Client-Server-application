#include "client.h"
#include "socket.h"
int main (int arg_c, char argv[])
{
	printf("KALWS HRTHATE STHN KRATHSH EISITIRIWN!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	krathsh();
	return 0;
}

void krathsh(void){	
	socket_klish();
	socket_arxikop();
	socket_sundesh();
	srand((unsigned int)getpid());//xwris auto h sunarthsh rand tha evgaze panta tis idies times
	//edw me tuxaio tropo vazoume times sts metavlhtes pou xreazomaste:eisitiria,Zwnh,pistotikh_karta
	eisitiria=rand()%4 +1;
	Zwnh=rand()%10 +1;//perontas times apo 1-10 exoume:timh 1->10% pithanothes->zwnh A
	//timh 2,3 ->20% pithanotites->zwnh B,timh 4,5,6 ->30% pithanotites->zwnh C,timh 7,8,9,10->40% pithanotites->zwnh D
 	pistotikh_karta=rand()% 10 +1;
	//times pou stelnei o client stn server
	write(sd,&eisitiria,sizeof(eisitiria));
	write(sd,&Zwnh,sizeof(Zwnh));
	write(sd,&pistotikh_karta,sizeof(pistotikh_karta));
	//tupwnoume tis times pou exoun prokupsei stis metavlhtes apo thn rand()
	printf("Exete zhthsei %d eisitiria!!!\n",eisitiria);
	if(Zwnh==1){
			printf("Exete zhthsei eisitiria stn A Zwnh \n");
		}else if(Zwnh==2 ||Zwnh==3){
			printf("Exete zhthsei eisitiria stn B Zwnh \n");
		}else if(Zwnh==4 || Zwnh==5 || Zwnh==6){
			printf("Exete zhthsei eisitiria stn C Zwnh \n");
		}else if(Zwnh==7 || Zwnh==8 || Zwnh==9 || Zwnh==10){
			printf("Exete zhthsei eisitiria stn D Zwnh \n");
		}
	printf("H pistotikh sas karta exei thn timh: %d \n ",pistotikh_karta);
	//times pou dexete o client apo ton  server
	read(sd,&anamonh,sizeof(anamonh));
	read(sd,&epitixia,sizeof(epitixia));
	read(sd,&teleutaia_thesi,sizeof(teleutaia_thesi));
	read(sd,&kostos,sizeof(kostos));
	read(sd,&id,sizeof(id));
	read(sd,&gemath_za,sizeof(gemath_za));
	read(sd,&gemath_zb,sizeof(gemath_zb));
	read(sd,&gemath_zc,sizeof(gemath_zc));
	read(sd,&gemath_zd,sizeof(gemath_zd));
	read(sd,&gemato,sizeof(gemato));
	read(sd,&pistotikh_karta,sizeof(pistotikh_karta));
	printf("--------------------------------------------\n");
	//analoga me tis times twn metavlhtwn pou exei steilei o server ,o client tupwnei analoga mhnumata
	if(anamonh==1){
		printf("Sugnwmh oloi oi thlefwnites einai apasxolhmenoi.Parakalw perimenete\n");
		sleep(Twait);
		}
		if(epitixia==1){
		printf("H krathsh sas oloklhrwthike epitixws\n");
		printf("To anagnwristiko ts krathshs sas einai %d\n",id);
		printf("Oi theseis sas einai:");
		if(Zwnh==1){
			for(i=0;i<eisitiria;i++){printf("A%d ",teleutaia_thesi-i);}
		}else if(Zwnh==2 ||Zwnh==3){
			for(i=0;i<eisitiria;i++){printf("B%d ",teleutaia_thesi-i);}
		}else if(Zwnh==4 || Zwnh==5 || Zwnh==6){
			for(i=0;i<eisitiria;i++){printf("C%d ",teleutaia_thesi-i);}
		}else if(Zwnh==7 || Zwnh==8 || Zwnh==9 || Zwnh==10){
			for(i=0;i<eisitiria;i++){printf("D%d ",teleutaia_thesi-i);}
		}
		printf("\n");
		printf("Kai to kostos ths sunallaghs einai %d EURO\n",kostos);
	}else if(pistotikh_karta==1){
		printf("H pistotikh sas karta den einai egkurh\n");
	}else if((gemath_za==1 || gemath_zb==1 || gemath_zc==1 ||gemath_zd==1) && gemato!=1 ){
		printf("Den yparxoyn diathesimes theseis se aythn tn zwnh\n");
	}else if(gemath_za==1 && gemath_zb==1 && gemath_zc==1 && gemath_zd==1){
		printf("Sugnwmh alla den uparxoun alles theseis.To theatro  gemise\n");
	}
	printf("--------------------------------------------\n");

}




//sunarthsh pou dimiourgei to socket
void socket_klish(void){
 
//dhmiourgei ena unbound socket se ena tomea epikoinonias.
 //kai epistrefei ena file discriptor sto sd
 // AF_LOCAL proteinei topiko tomea epikoinonias
 // to SOCK_STREAM einai miden kai etsi to default protocol
 // gia autn tn oikogeneia prokeite na xrhsimopoihthei
 sd= socket(AF_LOCAL, SOCK_STREAM, 0);
 //to sd tha einai an exoume epituxhs oloklhrwsh mn arnitikos allws se lathos
 // tha einai -1
 if(sd==-1){
          printf("Can not create socket\n");
          exit(1);
          }
else{printf("Epituxhs socket klisi \n");}
}

void socket_arxikop(void){
 //afairoume proigoumeno  socket me idio filename    
   //  unlink(UNIXSTR_PATH);
 //midenizoyme ola ta pedia t serveraddr
      bzero(&serveraddr, sizeof(serveraddr));
 //thetoume tn socket type local
      serveraddr.sun_family = AF_LOCAL;
 //thetoume onoma tou socket
       strcpy(serveraddr.sun_path, UNIXSTR_PATH);
printf("Epituxhs socket arxikop \n");
 }

 void socket_sundesh(void){
     
//orizei to  megethos to clientaddr sto clientaddrlen 
      //Exagei thn prwth syndesh sthn oura anamonhs
  //syndeseis dhmioyrgoun ena neo socket me to idio socket type protocol
  //kai th dieuthinsh ths oikogenias opws to sd
  //kai desmeuei sdaccept file descriptor gia auto to socket.
  connsd = connect(sd, (struct sockaddr *) &serveraddr,sizeof(serveraddr));
  //to connsd tha exei timi 0 an exei oloklirwthei swsta alliws -1
  if(connsd==-1){
                 printf("Den mporei na dextei tn sundesh\n");
                 exit(1);
                 }
else{printf("Epituxhs socket sundesh \n");} 
 }  

