//
//	hsp3cnv(3.5b5) generated source
//	[main.ax]
//
#include "hsp3r.h"

#define _HSP3CNV_DATE "2024/12/17"
#define _HSP3CNV_TIME "19:06:01"
#define _HSP3CNV_MAXVAR 3
#define _HSP3CNV_MAXHPI 32
#define _HSP3CNV_VERSION 0x360
#define _HSP3CNV_BOOTOPT 4096

/*-----------------------------------------------------------*/

static PVal *Var_0;
static PVal *Var_1;
static PVal *Var_2;

/*-----------------------------------------------------------*/

void __HspEntry( void ) {
	// Var initalize
	Var_0 = &mem_var[0];
	Var_1 = &mem_var[1];
	Var_2 = &mem_var[2];

	// _HspVar0 ="Hello, HSP3!"
	PushStr("Hello, HSP3!"); 
	VarSet(Var_0,0);
	//  1, 0
	PushInt(0); 
	PushInt(1); 
	Extcmd(94,2);
	TaskSwitch(0);
}

static void L0000( void ) {
	// redraw 0
	PushInt(0); 
	Extcmd(27,1);
	// pos , -512
	PushInt(-512); 
	PushDefault();
	Extcmd(17,2);
	// mes _HspVar0
	PushVAP(Var_0,0); 
	Extcmd(15,1);
	// _HspVar1 =(ginfo(12)(14)-ginfo(14))/2
	PushFuncEnd(); 	PushInt(12); 
PushExtvar(256,1); PushFuncEnd(); 	PushInt(14); 
PushExtvar(256,1); CalcSubI(); PushInt(2); CalcDivI(); 
	VarSet(Var_1,0);
	// _HspVar2 =((ginfo(13)(15)-ginfo(15))/2)-24
	PushFuncEnd(); 	PushInt(13); 
PushExtvar(256,1); PushFuncEnd(); 	PushInt(15); 
PushExtvar(256,1); CalcSubI(); PushInt(2); CalcDivI(); PushInt(24); CalcSubI(); 
	VarSet(Var_2,0);
	//  16777215
	PushInt(16777215); 
	Extcmd(78,1);
	// pos _HspVar1, _HspVar2
	PushVAP(Var_2,0); 
	PushVAP(Var_1,0); 
	Extcmd(17,2);
	// mes _HspVar0
	PushVAP(Var_0,0); 
	Extcmd(15,1);
	// redraw 1
	PushInt(1); 
	Extcmd(27,1);
	// await 16
	PushInt(16); 
	Prgcmd(8,1);
	TaskSwitch(2);
}

static void L0002( void ) {
	// goto *L0000
	TaskSwitch(0);
	return;
	TaskSwitch(1);
}

static void L0001( void ) {
	// stop 
	Prgcmd(17,0);
	return;
	// goto 
	Prgcmd(0,0);
	return;
}

//-End of Source-------------------------------------------

CHSP3_TASK __HspTaskFunc[]={
(CHSP3_TASK) L0000,
(CHSP3_TASK) L0001,
(CHSP3_TASK) L0002,
(CHSP3_TASK) 0,

};

/*-----------------------------------------------------------*/


/*-----------------------------------------------------------*/

void __HspInit( Hsp3r *hsp3 ) {
	hsp3->Reset( _HSP3CNV_MAXVAR, _HSP3CNV_MAXHPI );
	hsp3->SetDataName( 0 );
	hsp3->SetFInfo( 0, 0 );
	hsp3->SetLInfo( 0, 0 );
	hsp3->SetMInfo( 0, 0 );
}

/*-----------------------------------------------------------*/

