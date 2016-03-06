#ifndef SOCKET_H
#define SOCKET_H

#include "server.h"
//exei ta header pou xreazontai gia thn epikoinonia tou socket
#include <sys/socket.h>
//exei header gia to unix domain socket
#include <sys/un.h>

//onoma pou exoume  gia to  socket
#define UNIXSTR_PATH "./eisitiria_Theatrikiis_parastashs.socket"
//oura sundesewn ths listen()
#define LISTENQ 30

//oi metavlites pou tha xrisimopoihsoume sta socket arxeia
 int sd, bindsd, listensd, connsd,error;
 //domh pou krataei th dieuthinsi tou server kai client
 struct sockaddr_un clientaddr, serveraddr;
 //domi pou krataei megethos dieuthinshs tou socket
 socklen_t clientaddrlen;
 
 //kalei to socket
 void socket_klish(void);
 //arxikopoiei to socket
 void socket_arxikop(void);
 //dinei onoma sto socket
 void socket_bind(void);
 //akouei aitima client gia sundesh me tn server
 void socket_listen(void);
 //dexete sundesh sto socket
 void socket_dexetai(void);
 // kleinoun to sd-paidi kai sd-pateras
 void socket_aposundesh_child(void);
 void socket_aposundesh_parent(void);
 void socket_sundesh(void);
 #endif
 