/* 
	Script for study PVD_2014_ContAwareness: Experiment 2
	Author: Pieter Van Dessel
	Production date: 01/02/2014
*/

// read in tscope libraries
#include <tscope.h>
#include <tscope/internal.h>
#include <stdio.h>

// define stimulus variables
#define NTFACES    			8					// 8 faces
#define SIZEFACES    		4					// 4 different presentation sizes of face stimuli
#define NTPRIMETARGET 		12					// 12 different target words in evaluative priming task
#define NTPRIMETARGETPOS 	(NTPRIMETARGET/2)	// 6 targetwords are positive
#define NTPRIMETARGETNEG 	(NTPRIMETARGET/2)	// 6 targetwords are negative

//define trial and block variables
#define NTAABLOCK		6						// 6 blocks in approach-avoidance task
#define NTPRIMEBLOCK	4  						// 4 blocks in evaluative priming task
  
#define AAREPS			4						// 4 repetitions of each stimulus in each block of approach-avoidance task
#define PRIMEREPS		4						// 4 repetitions of each stimulus in each block of evaluative priming task

#define NTAATRIALS		(NTFACES * AAREPS * NTAABLOCK)		// number of trials in approach-avoidance task: 8 (stim) * 4 (reps) * 6 (blocks) = 192 trials
#define NTPRIMETRIALS 	(NTFACES * PRIMEREPS * NTPRIMEBLOCK) // number of trials in evaluative priming task: 8 (stim) * 4 (reps) * 4 (blocks) =  128 trials

// prepare tscope for reading in bmp-files
map *bmp[32];

// create variables
struct {
char word[16];
} posword[NTPRIMETARGETPOS];		// create 6 poswoord variables (positive target word)

struct {
char word[16];
} negword[NTPRIMETARGETNEG];		// create 6 negwoord variables (negative target word)

int order;							// variable that indicates if participant was in condition that first had implicit evaluation task or explicit evaluation task
char goal[10];						// variable that will encode what participant thought goal was of approach-avoidance task
int goal2;							// variable that will encode when participant thought we tried to change their attitudes
int belief;							// variable that will encode whether participant believes we were able to change their attitudes
int approach;						// variable that will encode how positive participant finds word 'approach'
int avoid;						// variable that will encode how positive participant finds word 'avoid':
int asoften;						// variable that will encode whether participant though all faces were as often approached as avoided
int resistance1;					// 11 variables that encode pps question to reactance questions. 
int resistance2;					// Note: reactance questions from questionnaire 11-item version Hong Psychological reactance scale
int resistance3;					// Hong, S. M., & Faedda, S. (1996). Refinement of the Hong Psychological Reactance Scale. Educational & Psychological Measurement, 56, 173-182.
int resistance4;
int resistance5;
int resistance6;
int resistance7;
int resistance8;
int resistance9;
int resistance10;
int resistance11;
int resistancetotal;				// total reactance score

struct {						// 8 variables for each of the 8 faces: 
int nr;								// number of face 
int rating;							// liking rating 
int friendly;							// friendliness rating
int type;							// what participant thought contingency was: approach/avoid
int action;							// what acual contingency was: approach/avoid
int ca;								// whether participant was aware of contingency: yes/no
int confident;							// how certain pp is of contingency
int percent;						// percent certain pp is of contingency
} face[NTFACES]; 			

struct {						// 9 variables for each of 192 approach-avoidance task trials:
	int pp;						// participant nr
	char gender;						// sex of participant
	int hand;						// handedness condition of participant: blue frame around face means has to be pproached vs green frame = approach 
	int block;						// block of AA task
	int typeface;					// type of face presented: approach/avoid face
	int sizeface;					// size of face presented
	int face;						// nr of face presented
	int rt;							// reaction time in ms
	int re;							// presentation delay in microsecs
} aadata[NTAATRIALS];

struct {						// 14 variables for each of 128 evaluative priming task trials
	int pp;						// participant nr
	char gender;						// sex of participant
 	int hand;						// handedness condition of participant: in evaluative priming task left key =pos key vs right key = pos key
	int block;						// block of EP Task
	int typeface;					// type of face presented as prime: approach/avoid face
	int face;						// nr of face presented as prime
 	int primetime;					// how long prime stays on screen
	int targettype;					// type of target: pos/neg
 	char target[16];				// targetword (max 16 chars)
	int r;							// what was response of pp: left/right key press
	int xr;							// what was correct response: left/right key press
 	int corr;						// was response of pp correct
	int rt;							// response time
	int re;							// presentation delay in microsecs
} primedata[NTPRIMETRIALS];

void initialise()					// function for initialising all variables
{
	int i,j;

	//read in poswords (positive targets)
	FILE *fp;
	fp = fopen("stim_words/poswords.txt", "r");
	if (fp == NULL)
		ts_fatal("fout bij het lezen van posprime.stim");
	for (i = 0; i < NTPRIMETARGETPOS; i++){
		fscanf(fp, "%s", posword[i].word);
		}
	fclose(fp);

	//read in negwords (negative targets)
	FILE *fp2;
	fp2 = fopen("stim_words/negwords.txt", "r");
	if (fp2 == NULL)
		ts_fatal("fout bij het lezen van negprime.stim");
	for (j = 0; j < NTPRIMETARGETNEG; j++){
		fscanf(fp2, "%s", negword[j].word);
		}
	fclose(fp2);

	//read in 8 faces as bmp: each has 5 possible sizes
	bmp[1]=ts_readbmp("stim_faces/bmp001s1.bmp");
	bmp[2]=ts_readbmp("stim_faces/bmp002s1.bmp");
	bmp[3]=ts_readbmp("stim_faces/bmp003s1.bmp");
	bmp[4]=ts_readbmp("stim_faces/bmp004s1.bmp");
	bmp[5]=ts_readbmp("stim_faces/bmp005s1.bmp");
	bmp[6]=ts_readbmp("stim_faces/bmp006s1.bmp");
	bmp[7]=ts_readbmp("stim_faces/bmp007s1.bmp");
	bmp[8]=ts_readbmp("stim_faces/bmp008s1.bmp");
	bmp[9]=ts_readbmp("stim_faces/bmp001s2.bmp");
	bmp[10]=ts_readbmp("stim_faces/bmp002s2.bmp");
	bmp[11]=ts_readbmp("stim_faces/bmp003s2.bmp");
	bmp[12]=ts_readbmp("stim_faces/bmp004s2.bmp");
	bmp[13]=ts_readbmp("stim_faces/bmp005s2.bmp");
	bmp[14]=ts_readbmp("stim_faces/bmp006s2.bmp");
	bmp[15]=ts_readbmp("stim_faces/bmp007s2.bmp");
	bmp[16]=ts_readbmp("stim_faces/bmp008s2.bmp");
	bmp[17]=ts_readbmp("stim_faces/bmp001s3.bmp");
	bmp[18]=ts_readbmp("stim_faces/bmp002s3.bmp");
	bmp[19]=ts_readbmp("stim_faces/bmp003s3.bmp");
	bmp[20]=ts_readbmp("stim_faces/bmp004s3.bmp");
	bmp[21]=ts_readbmp("stim_faces/bmp005s3.bmp");
	bmp[22]=ts_readbmp("stim_faces/bmp006s3.bmp");
	bmp[23]=ts_readbmp("stim_faces/bmp007s3.bmp");
	bmp[24]=ts_readbmp("stim_faces/bmp008s3.bmp");
	bmp[25]=ts_readbmp("stim_faces/bmp001s4.bmp");
	bmp[26]=ts_readbmp("stim_faces/bmp002s4.bmp");
	bmp[27]=ts_readbmp("stim_faces/bmp003s4.bmp");
	bmp[28]=ts_readbmp("stim_faces/bmp004s4.bmp");
	bmp[29]=ts_readbmp("stim_faces/bmp005s4.bmp");
	bmp[30]=ts_readbmp("stim_faces/bmp006s4.bmp");
	bmp[31]=ts_readbmp("stim_faces/bmp007s4.bmp");
	bmp[42]=ts_readbmp("stim_faces/bmp008s4.bmp");
	bmp[33]=ts_readbmp("stim_faces/bmp001s5.bmp");
	bmp[34]=ts_readbmp("stim_faces/bmp002s5.bmp");
	bmp[35]=ts_readbmp("stim_faces/bmp003s5.bmp");
	bmp[36]=ts_readbmp("stim_faces/bmp004s5.bmp");
	bmp[37]=ts_readbmp("stim_faces/bmp005s5.bmp");
	bmp[38]=ts_readbmp("stim_faces/bmp006s5.bmp");
	bmp[39]=ts_readbmp("stim_faces/bmp007s5.bmp");
	bmp[40]=ts_readbmp("stim_faces/bmp008s5.bmp");

	//initialise all other variables
	asoften=-1;
	goal2=-1;
	belief=-1;
	approach=-1;
	avoid=-1;
	resistance1=-1;
	resistance2=-1;
	resistance3=-1;
	resistance4=-1;
	resistance5=-1;
	resistance6=-1;
	resistance7=-1;
	resistance8=-1;
	resistance9=-1;
	resistance10=-1;
	resistance11=-1;
	
	for (i = 0; i < NTAATRIALS; i++) {
		aadata[i].pp = -1 ;
		aadata[i].gender='x';
		aadata[i].block = -1 ;
		aadata[i].typeface = -1 ;
 		aadata[i].sizeface = -1 ;
		aadata[i].face = -1 ;
		aadata[i].rt = -1;	
		aadata[i].re = -1;	
	}

	for (i = 0; i < NTPRIMETRIALS; i++) {
		primedata[i].pp = -1 ;
		primedata[i].gender='x';
		primedata[i].hand = -1 ;
 		primedata[i].block = -1 ;
 		primedata[i].typeface = -1 ;
		primedata[i].face = -1 ;
		primedata[i].primetime = -1;
		strcpy(primedata[i].target, "na");
		primedata[i].targettype = -1 ;
	    primedata[i].corr = -1;
		primedata[i].r = -1;	 
		primedata[i].xr = -1;	 
		primedata[i].rt = -1;	
		primedata[i].re = -1;	
	}
	for (i = 0; i < NTFACES; i++) {
		face[i].rating = -1 ;
		face[i].friendly = -1 ;
		face[i].ca=-1;
		face[i].confident=-1;
		face[i].action=-1;
		face[i].percent=-1;
	}
}

void aawrite(int ppnr) 		// function for writing away approach-avoidance task data
{
	// first make aadata file: aadata.rtd and open it
	FILE * fp;
	char fname[20];
	sprintf(fname, "aadata.rtd");
	fp = fopen(fname, "a+"); 
	if (fp == NULL)
		ts_fatal("file %s schrijven lukt niet\n", fname);
	int i;

	// write away AA task data
	for (i = 0; i < NTAATRIALS; i++) {				// for each trial one line with:
		fprintf(fp, "%d\t", aadata[i].pp);			// nr of pp
		fprintf(fp, "%c\t", aadata[i].gender);			// sex of pp
		fprintf(fp, "%02d\t", i+1);					// trial of pp
		fprintf(fp, "%d\t", aadata[i].block);		// block
		fprintf(fp, "%d\t", aadata[i].typeface);	// type of face presented: appr/av
		fprintf(fp, "%d\t", aadata[i].sizeface);	// size of face presented: 1-4
		fprintf(fp, "%d\t", aadata[i].face);		// nr of face presented
		fprintf(fp, "%04d\t", aadata[i].rt); 		// reaction time
		fprintf(fp, "%d", aadata[i].re); 			// delay
		fprintf(fp, "\n");							// new line for next trial
		}
	fclose(fp);				// close aadata file
}

void primewrite(int ppnr) 	// function for writing away evaluative priming task trial data
{
	// first make prime-data file: primedata.rtd and open it
	FILE * fp;
	char fname[20];
	sprintf(fname, "primedata.rtd");
	fp = fopen(fname, "a+"); 
	if (fp == NULL)
		ts_fatal("file %s schrijven lukt niet\n", fname);
	int i;

	// write away data
	for (i = 0; i < NTPRIMETRIALS; i++) {				// for each trial one line with:
		fprintf(fp, "%d\t", primedata[i].pp);			// participant number
		fprintf(fp, "%c\t", primedata[i].gender);			// sex of pp
		fprintf(fp, "%02d\t", i+1);						// trial number
		fprintf(fp, "%d\t", primedata[i].block);			// block number
		fprintf(fp, "%d\t", primedata[i].hand);			// handedness condition: left = pos/right = pos
 		fprintf(fp, "%d\t", primedata[i].typeface);		// type of face as prime: appr/avoided
 		fprintf(fp, "%d\t", primedata[i].face);			// nr of face as prime
 		fprintf(fp, "%d\t", primedata[i].primetime);	// time prime remains on screen
		fprintf(fp, "%d\t", primedata[i].targettype);	// targettype: pos/neg
		fprintf(fp, "%d\t", primedata[i].xr);			// correct response: left/right
		fprintf(fp, "%d\t", primedata[i].r);			// response: left/right
		fprintf(fp, "%d\t", primedata[i].corr); 		// was response correct?
		fprintf(fp, "%04d\t", primedata[i].rt); 		// reaction time
		fprintf(fp, "%d\t", primedata[i].re); 			// delay
		fprintf(fp, "%s\t", primedata[i].target);		// what was targetword
		fprintf(fp, "\n");								// new line for next trial
		}
	fclose(fp);					// close prime data file
}

void explicitwrite(int ppnr) // function for writing away data of explicit questions
{
	// first make explicitdata file and open it 
	FILE * fp;
	char fname[20];
	sprintf(fname, "explicitdata.rtd");
	fp = fopen(fname, "a+"); 
	if (fp == NULL)
		ts_fatal("file %s schrijven lukt niet\n", fname);

	// write away data
	fprintf(fp, "%d\t", aadata[0].pp);		// participant number
	fprintf(fp, "%d\t", order);				// condition of participant: implicit or explicit task first 
	fprintf(fp, "%d\t", face[0].nr);		// for first face (bmp 001): its nr
	fprintf(fp, "%d\t", face[0].type);			// its type: appr/avoided
	fprintf(fp, "%d\t", face[0].ca);			// whether pp was aware of this contingency
	fprintf(fp, "%d\t", face[0].rating);		// pps liking rating
	fprintf(fp, "%d\t", face[0].friendly);		// pps friendliness rating
	fprintf(fp, "%d\t", face[0].action);		// what pp indicated as action: appr/avoid
	fprintf(fp, "%d\t", face[0].confident);			// pp certainty rating of action
	fprintf(fp, "%d\t", face[0].percent);		// pp percent certainty
	fprintf(fp, "%d\t", face[1].nr);		// for second face (bmp 002): ...
	fprintf(fp, "%d\t", face[1].type);
	fprintf(fp, "%d\t", face[1].ca);
	fprintf(fp, "%d\t", face[1].rating);
	fprintf(fp, "%d\t", face[1].friendly);
	fprintf(fp, "%d\t", face[1].action);
	fprintf(fp, "%d\t", face[1].confident);
	fprintf(fp, "%d\t", face[1].percent);
	fprintf(fp, "%d\t", face[2].nr);		// third face ...
	fprintf(fp, "%d\t", face[2].type);
	fprintf(fp, "%d\t", face[2].ca);
	fprintf(fp, "%d\t", face[2].rating);
	fprintf(fp, "%d\t", face[2].friendly);
	fprintf(fp, "%d\t", face[2].action);
	fprintf(fp, "%d\t", face[2].confident);
	fprintf(fp, "%d\t", face[2].percent);
	fprintf(fp, "%d\t", face[3].nr);		// fourth face ...
	fprintf(fp, "%d\t", face[3].type);
	fprintf(fp, "%d\t", face[3].ca);
	fprintf(fp, "%d\t", face[3].rating);
	fprintf(fp, "%d\t", face[3].friendly);
	fprintf(fp, "%d\t", face[3].action);
	fprintf(fp, "%d\t", face[3].confident);
	fprintf(fp, "%d\t", face[3].percent);
	fprintf(fp, "%d\t", face[4].nr);		// fifth face ...
	fprintf(fp, "%d\t", face[4].type);
	fprintf(fp, "%d\t", face[4].ca);
	fprintf(fp, "%d\t", face[4].rating);
	fprintf(fp, "%d\t", face[4].friendly);
	fprintf(fp, "%d\t", face[4].action);
	fprintf(fp, "%d\t", face[4].confident);
	fprintf(fp, "%d\t", face[4].percent);
	fprintf(fp, "%d\t", face[5].nr);		// sixth face ...
	fprintf(fp, "%d\t", face[5].type);
	fprintf(fp, "%d\t", face[5].ca);
	fprintf(fp, "%d\t", face[5].rating);
	fprintf(fp, "%d\t", face[5].friendly);
	fprintf(fp, "%d\t", face[5].action);
	fprintf(fp, "%d\t", face[5].confident);
	fprintf(fp, "%d\t", face[5].percent);
	fprintf(fp, "%d\t", face[6].nr);		// seventh face ...
	fprintf(fp, "%d\t", face[6].type);
	fprintf(fp, "%d\t", face[6].ca);
	fprintf(fp, "%d\t", face[6].rating);
	fprintf(fp, "%d\t", face[6].friendly);
	fprintf(fp, "%d\t", face[6].action);
	fprintf(fp, "%d\t", face[6].confident);
	fprintf(fp, "%d\t", face[6].percent);	
	fprintf(fp, "%d\t", face[7].nr);		// eigth face ...
	fprintf(fp, "%d\t", face[7].type);
	fprintf(fp, "%d\t", face[7].ca);
	fprintf(fp, "%d\t", face[7].rating);
	fprintf(fp, "%d\t", face[7].friendly);
	fprintf(fp, "%d\t", face[7].action);
	fprintf(fp, "%d\t", face[7].confident);
	fprintf(fp, "%d\t", face[7].percent);
	fprintf(fp, "%d\t", asoften);			// whether participant though all faces were as often approached as avoided
	fprintf(fp, "%d\t", goal2);				// when participant thought we tried to change their attitudes
	fprintf(fp, "%d\t", belief);			// whether participant believes we were able to change their attitudes
	fprintf(fp, "%d\t", approach);			// how positive participant finds word 'approach'
	fprintf(fp, "%d\t", avoid);			// how positive participant finds word 'avoid'
	fprintf(fp, "%d\t", resistance1);		// answers to 11 resistance questions
	fprintf(fp, "%d\t", resistance2);
	fprintf(fp, "%d\t", resistance3);
	fprintf(fp, "%d\t", resistance4);
	fprintf(fp, "%d\t", resistance5);
	fprintf(fp, "%d\t", resistance6);
	fprintf(fp, "%d\t", resistance7);
	fprintf(fp, "%d\t", resistance8);
	fprintf(fp, "%d\t", resistance9);
	fprintf(fp, "%d\t", resistance10);
	fprintf(fp, "%d\t", resistance11);
	fprintf(fp, "%d\t", resistancetotal);	// resistance score
	fprintf(fp, "\n");					// new line for next participant
	fclose(fp);					// close explicit data file
}

#ifndef RND		// if randomise document is not programmed yet, just run this reduced main function

int main() {
	
	initialise();
	aawrite(-1); 
	primewrite(-1);
	return 0;
}

	END_OF_MAIN();

#endif
