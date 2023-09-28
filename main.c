#include "main.h"
#include <stdio.h>
#include <stdint.h>
#include <plugins.h>
#include <stdbool.h>
#include <orbis/libkernel.h>
#define db 0x003FC000
struct proc_info procInfo;
struct proc_rw datawrite;
OrbisPthread engine;
char auth[16];
unsigned char verid1[1]={0};
unsigned char verid2[1]={0};
unsigned char verid3[1]={0};
void procrw(u64 cd,void *dw,u64 s,u64 flag){
datawrite.address=cd+db;
datawrite.data=dw;
datawrite.length=s;
datawrite.write_flags=flag;
sys_sdk_proc_rw(&datawrite);}
void *spectrengine(void *args){
procrw(0x01661B18,verid1,1,0);
procrw(0x01661B1D,verid2,1,0);
procrw(0x01661B1F,verid3,1,0);
if(verid1[0]==(unsigned char)2&&verid2[0]==(unsigned char)201&&verid3[0]==(unsigned char)192){
procrw(0x02C0CACE,AC101A,288,1);
procrw(0x02C0CA54,AC101B,122,1);
procrw(0x0183E6F9,AC101C,49,1);
procrw(0x028BF0EB,AC101D,19,1);
procrw(0x00DDB279,AC101E,14,1);
procrw(0x0184877E,AC101F,7,1);
procrw(0x01661B74,AC101G,3,1);
procrw(0x01661EAB,AC101H,3,1);
procrw(0x0183E5CF,AC101I,2,1);
procrw(0x017B1D49,AC101I,2,1);
procrw(0x0183E731,AC101I,2,1);
procrw(0x01C46469,AC101J,1,1);
procrw(0x0183E6EB,AC101K,1,1);}
scePthreadExit(NULL);
return NULL;}
int32_t attr_module_hidden module_start(size_t argc,const void *args){
if(sys_sdk_proc_info(&procInfo)){return 0;}
memcpy(auth, procInfo.titleid, sizeof(auth));
if(auth[4]=='2'&&auth[5]=='5'&&auth[6]=='3'&&auth[7]=='6'&&auth[8]=='8'){
scePthreadCreate(&engine, NULL, spectrengine, NULL, "spectrengine");}
else{if(auth[4]=='3'&&auth[5]=='2'&&auth[6]=='5'&&auth[7]=='9'&&auth[8]=='8'){
scePthreadCreate(&engine, NULL, spectrengine, NULL, "spectrengine");}
else{if(auth[4]=='3'&&auth[5]=='2'&&auth[6]=='5'&&auth[7]=='9'&&auth[8]=='9'){
scePthreadCreate(&engine, NULL, spectrengine, NULL, "spectrengine");}
else{if(auth[4]=='3'&&auth[5]=='2'&&auth[6]=='6'&&auth[7]=='0'&&auth[8]=='0'){
scePthreadCreate(&engine, NULL, spectrengine, NULL, "spectrengine");}}}}
return 0;}
int32_t attr_module_hidden module_stop(size_t argc,const void *args){
return 0;}