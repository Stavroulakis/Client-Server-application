#ifndef CLIENT_H
#define CLIENT_H
//aparaithta headers
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#define Nthl 10
#define Nbank 4
#define Tseat 6
#define Tcardc 2
#define Twait 10
#define Ttransf 30
#define UNIXSTR_PATH "./eisitiria_Theatrikiis_parastashs.socket"
//metevlhtes pou xrhshmopoioume
int epitixia,teleutaia_thesi,kostos,id;
int gemath_za;
int gemath_zb;
int gemath_zc;
int gemath_zd;
int gemato;
int apanthsh;
int anamonh;
char buf[500];
int eisitiria;
int Zwnh;
int pistotikh_karta;
char *arg_v[10];
int sd,len;


void krathsh(void);
void socket_klish(void);
void socket_arxikop(void);
void socket_sundesh(void);

#endif