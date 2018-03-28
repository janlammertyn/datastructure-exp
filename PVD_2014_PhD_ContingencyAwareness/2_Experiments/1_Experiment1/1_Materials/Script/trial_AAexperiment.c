/* 
	Name: trial_AAexperiment.c
	Author: PVD
	Does: Provides trial function used in exp_AAexperiment.c
*/

#define TRIAL				// programming of randomise document is finished
#include "rnd_AAexperiment.c"		// first run rnd_AAexperiment.c-file that randomizes all variables (and runs data_AAexperiment that initializes all vars)

// define timing variables
#define AAITI 		mtt(200)		// intertrialinterval approach-avoidance task 200 ms
#define FIX 		mtt(500)		// presentation fixation cross evaluative priming task and approach-avoidance task 500 ms
#define POSTFIX 	mtt(500)		// post fixation pause evaluative priming task 500 ms
#define PRIME 		mtt(200)		// prime face presentation 200 ms
#define POSTPRIME 	mtt(50)			// post prime pause 50 ms
#define TARGET 		mtt(2000)		// max presentation time target 2000 ms
#define FBTM 		mtt(250)		// feedback time evaluative priming task 250 ms
#define PRIMEITI 	mtt(500+ts_rint(1000))	// random intertrial interval priming task : 500-1500 ms 

// initialize timing variables
struct{
	__int64 junk;
	__int64 t1,e1;
	__int64 t2,e2;
	__int64 tp1,ep1;
	__int64 tp2,ep2;
	__int64 td1,ed1;
	__int64 td2,ed2;
	__int64 tpd1,epd1;
	__int64 tpd2,epd2;
	
} tmp;


/*
	Function for running approach-avoidance trial
*/
void aatrial(int i)	
{
	poll_joystick();	// joystick initialized

	// fixation cross presentation
	ts_vsync(&tmp.junk,&tmp.junk);
	ts_clrscr();
	ts_printf_centre(0, 0, "+");
	ts_wait(FIX);

	// face presentation
	ts_vsync(&tmp.t1,&tmp.e1);
	ts_clrscr();
 	if (aadata[i].face==0){		// if face for this trial is bmp001
		if (((aadata[i].typeface==1)&&(aadata[i].hand==1))||((aadata[i].typeface==2)&&(aadata[i].hand==2))){ 	// if appr face and handedness blue=appr or av face and handedness green=appr
			if (aadata[i].sizeface==0){		// if size = 1
  			ts_blit(bmp[1], 0, 0);			// bmp 001 presented at size 1
			ts_fgcolor(BLUE);
			ts_rect(ax(-.3),ay(-.54),ax(.3),ay(.54)); // blue frame around face
			ts_fgcolor(WHITE);
			}
			if (aadata[i].sizeface==1){		// if size = 2
			ts_blit(bmp[9], 0, 0);			// bmp 001 presented at size 2
			ts_fgcolor(BLUE);
			ts_rect(ax(-.285),ay(-.515),ax(.285),ay(.515));	// blue frame around face
			ts_fgcolor(WHITE);
			}
			if (aadata[i].sizeface==2){		// if size = 3
  			ts_blit(bmp[17], 0, 0);			// bmp 001 presented at size 3
			ts_fgcolor(BLUE);
			ts_rect(ax(-.315),ay(-.565),ax(.315),ay(.565));	// blue frame around face
			ts_fgcolor(WHITE);
			}
			if (aadata[i].sizeface==3){		// if size = 4
  			ts_blit(bmp[25], 0, 0);			// bmp 001 presented at size 4
			ts_fgcolor(BLUE);
			ts_rect(ax(-.33),ay(-.595),ax(.33),ay(.595));	// blue frame around face
			ts_fgcolor(WHITE);
			}
		}
		else{																											// if appr face and handedness green=appr or av face and handedness blue=appr
			if (aadata[i].sizeface==0){		// if size = 1
			ts_blit(bmp[1], 0, 0);			// bmp 001 presented at size 1
			ts_fgcolor(GREEN);
			ts_rect(ax(-.3),ay(-.54),ax(.3),ay(.54)); // green frame around face
			ts_fgcolor(WHITE);
			}
			if (aadata[i].sizeface==1){		// if size = 2
			ts_blit(bmp[9], 0, 0);			// bmp 001 presented at size 2
			ts_fgcolor(GREEN);
			ts_rect(ax(-.285),ay(-.515),ax(.285),ay(.515));	// green frame around face
			ts_fgcolor(WHITE);
			}
			if (aadata[i].sizeface==2){		// if size = 3
			ts_blit(bmp[17], 0, 0);			// bmp 001 presented at size 3
			ts_fgcolor(GREEN);
			ts_rect(ax(-.315),ay(-.565),ax(.315),ay(.565));	// green frame around face
			ts_fgcolor(WHITE);
			}
			if (aadata[i].sizeface==3){		// if size = 4
			ts_blit(bmp[25], 0, 0);			// bmp 001 presented at size 4
			ts_fgcolor(GREEN);
			ts_rect(ax(-.33),ay(-.595),ax(.33),ay(.595));	// green frame around face
			ts_fgcolor(WHITE);
			}
		}
	}
	 if (aadata[i].face==1){	// if face for this trial is bmp002
		if (((aadata[i].typeface==1)&&(aadata[i].hand==1))||((aadata[i].typeface==2)&&(aadata[i].hand==2))){	// if appr face and handedness blue=appr or av face and handedness green=appr
  			if (aadata[i].sizeface==0){		// if size = 1
			ts_blit(bmp[2], 0, 0);			// bmp 002 presented at size 1
			ts_fgcolor(BLUE);
			ts_rect(ax(-.3),ay(-.54),ax(.3),ay(.54)); // blue frame around face
			ts_fgcolor(WHITE);
			}
			if (aadata[i].sizeface==1){		// if size = 2
			ts_blit(bmp[10], 0, 0);			// bmp 002 presented at size 2
			ts_fgcolor(BLUE);
			ts_rect(ax(-.285),ay(-.515),ax(.285),ay(.515));	// blue frame around face
			ts_fgcolor(WHITE);
			}
			if (aadata[i].sizeface==2){
			ts_blit(bmp[18], 0, 0);			// bmp 002 presented at size 3
			ts_fgcolor(BLUE);
			ts_rect(ax(-.315),ay(-.565),ax(.315),ay(.565));	// blue frame around face
			ts_fgcolor(WHITE);
			}
			if (aadata[i].sizeface==3){
			ts_blit(bmp[26], 0, 0);			// bmp 002 presented at size 4
			ts_fgcolor(BLUE);
			ts_rect(ax(-.33),ay(-.595),ax(.33),ay(.595));	// blue frame around face
			ts_fgcolor(WHITE);
			}
		}
		else{																			// if appr face and handedness green=appr or av face and handedness blue=appr
			if (aadata[i].sizeface==0){
			ts_blit(bmp[2], 0, 0);			// bmp 002 presented at size 1
			ts_fgcolor(GREEN);
			ts_rect(ax(-.3),ay(-.54),ax(.3),ay(.54)); // green frame around face
			ts_fgcolor(WHITE);
			}
			if (aadata[i].sizeface==1){
			ts_blit(bmp[10], 0, 0);			// bmp 002 presented at size 2
			ts_fgcolor(GREEN);
			ts_rect(ax(-.285),ay(-.515),ax(.285),ay(.515));	// green frame around face
			ts_fgcolor(WHITE);
			}
			if (aadata[i].sizeface==2){
			ts_blit(bmp[18], 0, 0);			// bmp 002 presented at size 3
			ts_fgcolor(GREEN);
			ts_rect(ax(-.315),ay(-.565),ax(.315),ay(.565));	// green frame around face
			ts_fgcolor(WHITE);
			}
			if (aadata[i].sizeface==3){
			ts_blit(bmp[26], 0, 0);			// bmp 002 presented at size 4
			ts_fgcolor(GREEN);
			ts_rect(ax(-.33),ay(-.595),ax(.33),ay(.595));	// green frame around face
			ts_fgcolor(WHITE);
			}
		}
	}
 	if (aadata[i].face==2){		// if face for this trial is bmp003
		if (((aadata[i].typeface==1)&&(aadata[i].hand==1))||((aadata[i].typeface==2)&&(aadata[i].hand==2))){	// if appr face and handedness blue=appr or av face and handedness green=appr
			if (aadata[i].sizeface==0){
  			ts_blit(bmp[3], 0, 0);			// bmp 003 presented at size 1
			ts_fgcolor(BLUE);
			ts_rect(ax(-.3),ay(-.54),ax(.3),ay(.54)); // blue frame around face
			ts_fgcolor(WHITE);
			}
			if (aadata[i].sizeface==1){
  			ts_blit(bmp[11], 0, 0);			// bmp 003 presented at size 2
			ts_fgcolor(BLUE);				
			ts_rect(ax(-.285),ay(-.515),ax(.285),ay(.515));	// blue frame around face
			ts_fgcolor(WHITE);
			}
			if (aadata[i].sizeface==2){
  			ts_blit(bmp[19], 0, 0);			// bmp 003 presented at size 3
			ts_fgcolor(BLUE);
			ts_rect(ax(-.315),ay(-.565),ax(.315),ay(.565));	// blue frame around face
			ts_fgcolor(WHITE);
			}
			if (aadata[i].sizeface==3){
  			ts_blit(bmp[27], 0, 0);			// bmp 003 presented at size 4
			ts_fgcolor(BLUE);
			ts_rect(ax(-.33),ay(-.595),ax(.33),ay(.595));	// blue frame around face
			ts_fgcolor(WHITE);
			}
		}
		else{																// if appr face and handedness green=appr or av face and handedness blue=appr
			if (aadata[i].sizeface==0){
			ts_blit(bmp[3], 0, 0);			// bmp 003 presented at size 1
			ts_fgcolor(GREEN);
			ts_rect(ax(-.3),ay(-.54),ax(.3),ay(.54)); // green frame around face
			ts_fgcolor(WHITE);
			}
			if (aadata[i].sizeface==1){
			ts_blit(bmp[11], 0, 0);			// bmp 003 presented at size 2
			ts_fgcolor(GREEN);
			ts_rect(ax(-.285),ay(-.515),ax(.285),ay(.515));
			ts_fgcolor(WHITE);
			}
			if (aadata[i].sizeface==2){
			ts_blit(bmp[19], 0, 0);			// bmp 003 presented at size 3
			ts_fgcolor(GREEN);
			ts_rect(ax(-.315),ay(-.565),ax(.315),ay(.565));
			ts_fgcolor(WHITE);
			}
			if (aadata[i].sizeface==3){
			ts_blit(bmp[27], 0, 0);			// bmp 003 presented at size 4
			ts_fgcolor(GREEN);
			ts_rect(ax(-.33),ay(-.595),ax(.33),ay(.595));
			ts_fgcolor(WHITE);
			}
		}
	}
  	if (aadata[i].face==3){		// if face for this trial is bmp004
		if (((aadata[i].typeface==1)&&(aadata[i].hand==1))||((aadata[i].typeface==2)&&(aadata[i].hand==2))){ // if appr face and handedness blue=appr or av face and handedness green=appr
			if (aadata[i].sizeface==0){
  			ts_blit(bmp[4], 0, 0);			// bmp 004 presented at size 1
			ts_fgcolor(BLUE);
			ts_rect(ax(-.3),ay(-.54),ax(.3),ay(.54));
			ts_fgcolor(WHITE);
			}
			if (aadata[i].sizeface==1){
  			ts_blit(bmp[12], 0, 0);			// bmp 004 presented at size 2
			ts_fgcolor(BLUE);
			ts_rect(ax(-.285),ay(-.515),ax(.285),ay(.515));
			ts_fgcolor(WHITE);
			}
			if (aadata[i].sizeface==2){
  			ts_blit(bmp[20], 0, 0);			// bmp 004 presented at size 3
			ts_fgcolor(BLUE);
			ts_rect(ax(-.315),ay(-.565),ax(.315),ay(.565));
			ts_fgcolor(WHITE);
			}
			if (aadata[i].sizeface==3){
  			ts_blit(bmp[28], 0, 0);			// bmp 004 presented at size 4
			ts_fgcolor(BLUE);
			ts_rect(ax(-.33),ay(-.595),ax(.33),ay(.595));
			ts_fgcolor(WHITE);
			}
		}
		else{																// if appr face and handedness green=appr or av face and handedness blue=appr
			if (aadata[i].sizeface==0){
			ts_blit(bmp[4], 0, 0);			// bmp 004 presented at size 1
			ts_fgcolor(GREEN);
			ts_rect(ax(-.3),ay(-.54),ax(.3),ay(.54));
			ts_fgcolor(WHITE);
			}
			if (aadata[i].sizeface==1){
			ts_blit(bmp[12], 0, 0);			// bmp 004 presented at size 2
			ts_fgcolor(GREEN);
			ts_rect(ax(-.285),ay(-.515),ax(.285),ay(.515));
			ts_fgcolor(WHITE);
			}
			if (aadata[i].sizeface==2){
			ts_blit(bmp[20], 0, 0);			// bmp 004 presented at size 3
			ts_fgcolor(GREEN);
			ts_rect(ax(-.315),ay(-.565),ax(.315),ay(.565));
			ts_fgcolor(WHITE);
			}
			if (aadata[i].sizeface==3){
			ts_blit(bmp[28], 0, 0);			// bmp 004 presented at size 4
			ts_fgcolor(GREEN);
			ts_rect(ax(-.33),ay(-.595),ax(.33),ay(.595));
			ts_fgcolor(WHITE);
			}
		}
	}
 	if (aadata[i].face==4){			// if face for this trial is bmp005
		if (((aadata[i].typeface==1)&&(aadata[i].hand==1))||((aadata[i].typeface==2)&&(aadata[i].hand==2))){ // if appr face and handedness blue=appr or av face and handedness green=appr
			if (aadata[i].sizeface==0){
  			ts_blit(bmp[5], 0, 0);			// bmp 005 presented at size 1
			ts_fgcolor(BLUE);
			ts_rect(ax(-.3),ay(-.54),ax(.3),ay(.54));
			ts_fgcolor(WHITE);
			}
			if (aadata[i].sizeface==1){
  			ts_blit(bmp[13], 0, 0);			// bmp 005 presented at size 2
			ts_fgcolor(BLUE);
			ts_rect(ax(-.285),ay(-.515),ax(.285),ay(.515));
			ts_fgcolor(WHITE);
			}
			if (aadata[i].sizeface==2){
  			ts_blit(bmp[21], 0, 0);			// bmp 005 presented at size 3
			ts_fgcolor(BLUE);
			ts_rect(ax(-.315),ay(-.565),ax(.315),ay(.565));
			ts_fgcolor(WHITE);
			}
			if (aadata[i].sizeface==3){
  			ts_blit(bmp[29], 0, 0);			// bmp 005 presented at size 4
			ts_fgcolor(BLUE);
			ts_rect(ax(-.33),ay(-.595),ax(.33),ay(.595));
			ts_fgcolor(WHITE);
			}
		}
		else{																// if appr face and handedness green=appr or av face and handedness blue=appr
			if (aadata[i].sizeface==0){
			ts_blit(bmp[5], 0, 0);			// bmp 005 presented at size 1
			ts_fgcolor(GREEN);
			ts_rect(ax(-.3),ay(-.54),ax(.3),ay(.54));
			ts_fgcolor(WHITE);
			}
			if (aadata[i].sizeface==1){
			ts_blit(bmp[13], 0, 0);			// bmp 005 presented at size 2
			ts_fgcolor(GREEN);
			ts_rect(ax(-.285),ay(-.515),ax(.285),ay(.515));
			ts_fgcolor(WHITE);
			}
			if (aadata[i].sizeface==2){
			ts_blit(bmp[21], 0, 0);			// bmp 005 presented at size 3
			ts_fgcolor(GREEN);
			ts_rect(ax(-.315),ay(-.565),ax(.315),ay(.565));
			ts_fgcolor(WHITE);
			}
			if (aadata[i].sizeface==3){
			ts_blit(bmp[29], 0, 0);			// bmp 005 presented at size 4
			ts_fgcolor(GREEN);
			ts_rect(ax(-.33),ay(-.595),ax(.33),ay(.595));
			ts_fgcolor(WHITE);
			}
		}
	}
	 if (aadata[i].face==5){	// if face for this trial is bmp006
		if (((aadata[i].typeface==1)&&(aadata[i].hand==1))||((aadata[i].typeface==2)&&(aadata[i].hand==2))){ // if appr face and handedness blue=appr or av face and handedness green=appr
			if (aadata[i].sizeface==0){
  			ts_blit(bmp[6], 0, 0);			// bmp 006 presented at size 1
			ts_fgcolor(BLUE);
			ts_rect(ax(-.3),ay(-.54),ax(.3),ay(.54));
			ts_fgcolor(WHITE);
			}
			if (aadata[i].sizeface==1){
  			ts_blit(bmp[14], 0, 0);			// bmp 006 presented at size 2
			ts_fgcolor(BLUE);
			ts_rect(ax(-.285),ay(-.515),ax(.285),ay(.515));
			ts_fgcolor(WHITE);
			}
			if (aadata[i].sizeface==2){
  			ts_blit(bmp[22], 0, 0);			// bmp 006 presented at size 3
			ts_fgcolor(BLUE);
			ts_rect(ax(-.315),ay(-.565),ax(.315),ay(.565));
			ts_fgcolor(WHITE);
			}
			if (aadata[i].sizeface==3){
  			ts_blit(bmp[30], 0, 0);			// bmp 006 presented at size 4
			ts_fgcolor(BLUE);
			ts_rect(ax(-.33),ay(-.595),ax(.33),ay(.595));
			ts_fgcolor(WHITE);
			}
		}
		else{																// if appr face and handedness green=appr or av face and handedness blue=appr
			if (aadata[i].sizeface==0){
			ts_blit(bmp[6], 0, 0);			// bmp 006 presented at size 1
			ts_fgcolor(GREEN);
			ts_rect(ax(-.3),ay(-.54),ax(.3),ay(.54));
			ts_fgcolor(WHITE);
			}
			if (aadata[i].sizeface==1){
			ts_blit(bmp[14], 0, 0);			// bmp 006 presented at size 2
			ts_fgcolor(GREEN);
			ts_rect(ax(-.285),ay(-.515),ax(.285),ay(.515));
			ts_fgcolor(WHITE);
			}
			if (aadata[i].sizeface==2){
			ts_blit(bmp[22], 0, 0);			// bmp 006 presented at size 3
			ts_fgcolor(GREEN);
			ts_rect(ax(-.315),ay(-.565),ax(.315),ay(.565));
			ts_fgcolor(WHITE);
			}
			if (aadata[i].sizeface==3){
			ts_blit(bmp[30], 0, 0);			// bmp 006 presented at size 4
			ts_fgcolor(GREEN);
			ts_rect(ax(-.33),ay(-.595),ax(.33),ay(.595));
			ts_fgcolor(WHITE);
			}
		}
	}
 	if (aadata[i].face==6){	// if face for this trial is bmp007
		if (((aadata[i].typeface==1)&&(aadata[i].hand==1))||((aadata[i].typeface==2)&&(aadata[i].hand==2))){ // if appr face and handedness blue=appr or av face and handedness green=appr
			if (aadata[i].sizeface==0){
  			ts_blit(bmp[7], 0, 0);			// bmp 007 presented at size 1
			ts_fgcolor(BLUE);
			ts_rect(ax(-.3),ay(-.54),ax(.3),ay(.54));
			ts_fgcolor(WHITE);
			}
			if (aadata[i].sizeface==1){
  			ts_blit(bmp[15], 0, 0);			// bmp 007 presented at size 2
			ts_fgcolor(BLUE);
			ts_rect(ax(-.285),ay(-.515),ax(.285),ay(.515));
			ts_fgcolor(WHITE);
			}
			if (aadata[i].sizeface==2){
  			ts_blit(bmp[23], 0, 0);			// bmp 007 presented at size 3
			ts_fgcolor(BLUE);
			ts_rect(ax(-.315),ay(-.565),ax(.315),ay(.565));
			ts_fgcolor(WHITE);
			}
			if (aadata[i].sizeface==3){
  			ts_blit(bmp[31], 0, 0);			// bmp 007 presented at size 4
			ts_fgcolor(BLUE);
			ts_rect(ax(-.33),ay(-.595),ax(.33),ay(.595));
			ts_fgcolor(WHITE);
			}
		}
		else{																// if appr face and handedness green=appr or av face and handedness blue=appr
			if (aadata[i].sizeface==0){
			ts_blit(bmp[7], 0, 0);			// bmp 007 presented at size 1
			ts_fgcolor(GREEN);
			ts_rect(ax(-.3),ay(-.54),ax(.3),ay(.54));
			ts_fgcolor(WHITE);
			}
			if (aadata[i].sizeface==1){
			ts_blit(bmp[15], 0, 0);			// bmp 007 presented at size 2
			ts_fgcolor(GREEN);
			ts_rect(ax(-.285),ay(-.515),ax(.285),ay(.515));
			ts_fgcolor(WHITE);
			}
			if (aadata[i].sizeface==2){
			ts_blit(bmp[23], 0, 0);			// bmp 007 presented at size 3
			ts_fgcolor(GREEN);
			ts_rect(ax(-.315),ay(-.565),ax(.315),ay(.565));
			ts_fgcolor(WHITE);
			}
			if (aadata[i].sizeface==3){
			ts_blit(bmp[31], 0, 0);			// bmp 007 presented at size 4
			ts_fgcolor(GREEN);
			ts_rect(ax(-.33),ay(-.595),ax(.33),ay(.595));
			ts_fgcolor(WHITE);
			}
		}
	}
	 if (aadata[i].face==7){		// if face for this trial is bmp008
		if (((aadata[i].typeface==1)&&(aadata[i].hand==1))||((aadata[i].typeface==2)&&(aadata[i].hand==2))){ // if appr face and handedness blue=appr or av face and handedness green=appr
			if (aadata[i].sizeface==0){
  			ts_blit(bmp[8], 0, 0);			// bmp 008 presented at size 1
			ts_fgcolor(BLUE);
			ts_rect(ax(-.3),ay(-.54),ax(.3),ay(.54));
			ts_fgcolor(WHITE);
			}
			if (aadata[i].sizeface==1){
  			ts_blit(bmp[16], 0, 0);			// bmp 008 presented at size 2
			ts_fgcolor(BLUE);
			ts_rect(ax(-.285),ay(-.515),ax(.285),ay(.515));
			ts_fgcolor(WHITE);
			}
			if (aadata[i].sizeface==2){
  			ts_blit(bmp[24], 0, 0);			// bmp 008 presented at size 3
			ts_fgcolor(BLUE);
			ts_rect(ax(-.315),ay(-.565),ax(.315),ay(.565));
			ts_fgcolor(WHITE);
			}
			if (aadata[i].sizeface==3){
  			ts_blit(bmp[42], 0, 0);			// bmp 008 presented at size 4
			ts_fgcolor(BLUE);
			ts_rect(ax(-.33),ay(-.595),ax(.33),ay(.595));
			ts_fgcolor(WHITE);
			}
		}
		else{																// if appr face and handedness green=appr or av face and handedness blue=appr
			if (aadata[i].sizeface==0){
			ts_blit(bmp[8], 0, 0);			// bmp 008 presented at size 1
			ts_fgcolor(GREEN);
			ts_rect(ax(-.3),ay(-.54),ax(.3),ay(.54));
			ts_fgcolor(WHITE);
			}
			if (aadata[i].sizeface==1){
			ts_blit(bmp[16], 0, 0);			// bmp 008 presented at size 2
			ts_fgcolor(GREEN);
			ts_rect(ax(-.285),ay(-.515),ax(.285),ay(.515));
			ts_fgcolor(WHITE);
			}
			if (aadata[i].sizeface==2){
			ts_blit(bmp[24], 0, 0);			// bmp 008 presented at size 3
			ts_fgcolor(GREEN);
			ts_rect(ax(-.315),ay(-.565),ax(.315),ay(.565));
			ts_fgcolor(WHITE);
			}
			if (aadata[i].sizeface==3){
			ts_blit(bmp[42], 0, 0);			// bmp 008 presented at size 4
			ts_fgcolor(GREEN);
			ts_rect(ax(-.33),ay(-.595),ax(.33),ay(.595));
			ts_fgcolor(WHITE);
			}
		}
	}
  
	//response registration
	if (aadata[i].typeface==1)
  	{	
 		do poll_joystick();
		while (joy[0].stick[0].axis[1].d2==0); // if approached face only register joystick movement up
	}
	else{	
 		do poll_joystick();
		while (joy[0].stick[0].axis[1].d1==0); // if avoided face only register joystick movement down
	}
	ts_clrscr();
	ts_vsync(&tmp.t2,&tmp.e2);

	aadata[i].rt=ttm(tmp.t2-tmp.t1);	// compute response time
	aadata[i].re=ttmu(tmp.e1+tmp.e2);	// compute delay

	// inter-trial interval
	ts_wait(AAITI);
}	   
 
/*
	Function for running evaluative priming task trial
*/
void primetrial(int i)	
{

	// presentation fixation cross
	ts_clrscr();
	ts_vsync(&tmp.junk,&tmp.junk);
	ts_printf_centre(0, ay(.08), "+");
	ts_wait(FIX);

	// prime presentation
	ts_clrscr();
	ts_wait(POSTFIX);
	ts_vsync(&tmp.tp1,&tmp.ep1);
	 if (primedata[i].face==0)
  		ts_blit(bmp[1], 0, 0);
	 if (primedata[i].face==1)
  		ts_blit(bmp[2], 0, 0);
 	 if (primedata[i].face==2)
  		ts_blit(bmp[3], 0, 0);
	 if (primedata[i].face==3)
  		ts_blit(bmp[4], 0, 0);
 	 if (primedata[i].face==4)
  		ts_blit(bmp[5], 0, 0);
	 if (primedata[i].face==5)
  		ts_blit(bmp[6], 0, 0);
 	 if (primedata[i].face==6)
  		ts_blit(bmp[7], 0, 0);
	 if (primedata[i].face==7)
  		ts_blit(bmp[8], 0, 0);
	ts_wait(PRIME);
	ts_vsync(&tmp.tp2,&tmp.ep2);

	// target presentation
	ts_clrscr();
	ts_wait(POSTPRIME);
	ts_vsync(&tmp.t1,&tmp.e1);
  	ts_printf_centre(0, ay(.08), "%s", primedata[i].target);
    
	//response registration
	primedata[i].r=ts_resp(&tmp.t2,&tmp.e2,TARGET);
	ts_clrscr();

  	// evaluation of response 
	if (primedata[i].r==3) {
		ts_fatal("Experiment stopped by user");	// escape breaks down experiment
		}
	if (primedata[i].r==primedata[i].xr)
		primedata[i].corr=1;
	else
		primedata[i].corr=0;

	primedata[i].rt=ttm(tmp.t2-tmp.t1); // reaction time computation
	primedata[i].re=ttmu(tmp.e1+tmp.e2);
	primedata[i].primetime=ttm(tmp.tp2-tmp.tp1);

	// Give feedback on error trials
	if (!primedata[i].corr) {
		ts_fgcolor(RED);
		ts_printf_centre (0, ay(.08), "Fout!");
		ts_fgcolor(WHITE);
		ts_wait (FBTM);
		ts_clrscr();		
	}

	// inter-trial-interval
	ts_wait(PRIMEITI);
}


#ifndef EXP // if exp document is not programmed yet, just run this reduced main function
int main()
{
	int i;
	ts_defkey(M1);
	ts_defkey(M2);
	ts_defkey(KEY_ESC);

	initialise();
	randomise(4,'m');
	for (i = 0; i < NTAATRIALS; i++)
	        aatrial(i);

	for (i = 0; i < NTPRIMETRIALS; i++)
	        primetrial(i);

	aawrite(4);
 	primewrite(4);

	return 0;
}

END_OF_MAIN();

#endif
