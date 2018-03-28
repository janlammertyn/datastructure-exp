/* 
	Name: rnd_AAexperiment.c
	Author: PVD
	Does: Provides randomising function used in exp_AAexperiment.c
*/

#define RND							// programming of randomise document is finished
#include "data_AAexperiment.c"		// first run data_AAexperiment.c-file that initializes all variables

void randomise(int ppnr,char mv)	// function for randomizing all variables
{
    int i,j; 

	// randomisation of faces

	// 1/8 pps has the following randomisation:
	if (ppnr==1|| ppnr==2|| ppnr==17 ||ppnr==18|| ppnr==33||ppnr==34||ppnr==49||ppnr==50){		
		face[0].nr=1; // bmp001 has nr 1	--> approached and presented 2nd in instrs
		face[1].nr=0; // bmp002 has nr 0	--> approached and presented 1st in instrs
		face[2].nr=4; // bmp003 has nr 4	--> avoided and presented 5th in instrs
		face[3].nr=7; // bmp004 has nr 7	--> avoided and presented 8th in instrs
		face[4].nr=5; // bmp005 has nr 5	--> avoided and presented 6th in instrs
		face[5].nr=2; // bmp006 has nr 2	--> approached and presented 3rd in instrs
		face[6].nr=6; // bmp007 has nr 6	--> avoided and presented 7th in instrs
		face[7].nr=3; // bmp008 has nr 3	--> approached and presented 4th in instrs
	}

	// 1/8 pps has following randomisation: 
	if (ppnr==3|| ppnr==4|| ppnr==19 ||ppnr==20||ppnr==35||ppnr==36||ppnr==51||ppnr==52){		
		face[0].nr=1; // bmp001 has nr 1
		face[1].nr=4; // bmp002 has nr 4
		face[2].nr=0; // bmp003 has nr 0
		face[3].nr=7; // bmp004 has nr 7
		face[4].nr=5; // bmp005 has nr 5
		face[5].nr=6; // bmp006 has nr 6
		face[6].nr=2; // bmp007 has nr 2
		face[7].nr=3; // bmp008 has nr 3
	}

	// 1/8 pps has following randomisation: 
	if (ppnr==5|| ppnr==6|| ppnr==21 ||ppnr==22||ppnr==37||ppnr==38||ppnr==53||ppnr==54){		
		face[0].nr=1; // bmp001 has nr 1
		face[1].nr=0; // bmp002 has nr 0
		face[2].nr=4; // bmp003 has nr 4
		face[3].nr=7; // bmp004 has nr 7
		face[4].nr=5; // bmp005 has nr 5
		face[5].nr=6; // bmp006 has nr 6
		face[6].nr=2; // bmp007 has nr 2
		face[7].nr=3; // bmp008 has nr 3
	}

	// 1/8 pps has following randomisation: 
	if (ppnr==7||ppnr==8|| ppnr==23||ppnr==24||ppnr==39||ppnr==40||ppnr==55||ppnr==56){			
		face[0].nr=1; // bmp001 has nr 1
		face[1].nr=4; // bmp002 has nr 4
		face[2].nr=0; // bmp003 has nr 0
		face[3].nr=7; // bmp004 has nr 7
		face[4].nr=5; // bmp005 has nr 5
		face[5].nr=2; // bmp006 has nr 2
		face[6].nr=6; // bmp007 has nr 6
		face[7].nr=3; // bmp008 has nr 3
	}

	// 1/8 pps has following randomisation: 
	if (ppnr==9|| ppnr==10|| ppnr==25||ppnr==26||ppnr==41||ppnr==42||ppnr==57||ppnr==58){		
		face[0].nr=5; // bmp001 has nr 5
		face[1].nr=0; // bmp002 has nr 0
		face[2].nr=4; // bmp003 has nr 4
		face[3].nr=3; // bmp004 has nr 3
		face[4].nr=1; // bmp005 has nr 1
		face[5].nr=2; // bmp006 has nr 2
		face[6].nr=6; // bmp007 has nr 6
		face[7].nr=7; // bmp008 has nr 7
	}

	// 1/8 pps has following randomisation: 
	if (ppnr==11|| ppnr==12|| ppnr==27 ||ppnr==28||ppnr==43||ppnr==44||ppnr==59||ppnr==60){	
		face[0].nr=5; // bmp001 has nr 5
		face[1].nr=4; // bmp002 has nr 4
		face[2].nr=0; // bmp003 has nr 0
		face[3].nr=3; // bmp004 has nr 3
		face[4].nr=1; // bmp005 has nr 1
		face[5].nr=6; // bmp006 has nr 6
		face[6].nr=2; // bmp007 has nr 2
		face[7].nr=7; // bmp008 has nr 7
	}

	// 1/8 pps has following randomisation: 
	if (ppnr==13|| ppnr==14|| ppnr==29||ppnr==30||ppnr==45||ppnr==46||ppnr==61||ppnr==62){		
		face[0].nr=5; // bmp001 has nr 5
		face[1].nr=0; // bmp002 has nr 0
		face[2].nr=4; // bmp003 has nr 4
		face[3].nr=3; // bmp004 has nr 3
		face[4].nr=1; // bmp005 has nr 1
		face[5].nr=6; // bmp006 has nr 6
		face[6].nr=2; // bmp007 has nr 2
		face[7].nr=7; // bmp008 has nr 7
	}

	// 1/8 pps has following randomisation: 
	if (ppnr==15|| ppnr==16|| ppnr==31 ||ppnr==32||ppnr==47||ppnr==48||ppnr==63||ppnr==64){		 
		face[0].nr=5; // bmp001 has nr 5
		face[1].nr=4; // bmp002 has nr 4
		face[2].nr=0; // bmp003 has nr 0
		face[3].nr=3; // bmp004 has nr 3
		face[4].nr=1; // bmp005 has nr 1
		face[5].nr=2; // bmp006 has nr 2
		face[6].nr=6; // bmp007 has nr 6
		face[7].nr=7; // bmp008 has nr 7
	}
	
	// randomisation of between-subjects variables:

	//1. order: implicit task first or explicit evaluation task first: implicit first if ppnr is odd: 1,3,5,7,9,11,...
	if (ppnr%2==1)
		order=1;
	else
		order=2;

	//2. handedness1: whether face with blue/green frame has to be approached in approach-avoid task  
	for (i = 0; i < NTAATRIALS; i++) // initialise for AA task trials ppnr, sex and handedness 
	{	
		aadata[i].pp=ppnr;
 		aadata[i].gender=mv;
		if ((ppnr<33 &&((ppnr%8==1)||(ppnr%8==2)||(ppnr%8==3)||(ppnr%8==4)))||(ppnr>32&&((ppnr%8==5)||(ppnr%8==6)||(ppnr%8==7)||(ppnr%8==0))))
			aadata[i].hand=1;
		else
			aadata[i].hand=2;
	}
		
	//3. handedness2: whether left or right key is positive in evaluative priming task  
	for (i = 0; i < NTPRIMETRIALS; i++)  // initialise for evalutive priming task trials ppnr, sex and handedness 
	{
		primedata[i].pp=ppnr;
		primedata[i].gender=mv;
		if ((ppnr<17 &&((ppnr%8==1)||(ppnr%8==4)||(ppnr%8==5)||(ppnr%8==0)))||(ppnr>16&&ppnr<49&&((ppnr%8==2)||(ppnr%8==3)||(ppnr%8==6)||(ppnr%8==7)))||(ppnr>48&&((ppnr%8==1)||(ppnr%8==4)||(ppnr%8==5)||(ppnr%8==0))))
			primedata[i].hand=1;
		else
			primedata[i].hand=2;
	}

	// randomisation for within-subjects variables:

	// 1. approach-avoidance task: randomise size of face and nr of face (which determines type: appr/avoid)
	int rndaa[NTAATRIALS];
	ts_rlist(NTFACES*AAREPS,NTAABLOCK,rndaa);	// 4 x 8 combinations
	for (i = 0; i < NTAATRIALS; i++) 
	{
		aadata[i].sizeface=rndaa[i]/NTFACES;
		aadata[i].face=rndaa[i]%NTFACES;
			
		if (aadata[i].face==0){		// face 1: approach
			if (face[0].nr<4)
	 			aadata[i].typeface=1;
			else
				aadata[i].typeface=2;
		}
		if (aadata[i].face==1){		// face 2: approach
			if (face[1].nr<4)
	 			aadata[i].typeface=1;
			else
				aadata[i].typeface=2;
		}
		if (aadata[i].face==2){		// face 3: approach
			if (face[2].nr<4)
	 			aadata[i].typeface=1;
			else
				aadata[i].typeface=2;
		}
		if (aadata[i].face==3){		// face 4: approach
			if (face[3].nr<4)
	 			aadata[i].typeface=1;
			else
				aadata[i].typeface=2;
		}
		if (aadata[i].face==4){		// face 5: avoid
			if (face[4].nr<4)
	 			aadata[i].typeface=1;
			else
				aadata[i].typeface=2;
		}
		if (aadata[i].face==5){		// face 6: avoid
			if (face[5].nr<4)
	 			aadata[i].typeface=1;
			else
				aadata[i].typeface=2;
		}
		if (aadata[i].face==6){		// face 7: avoid
			if (face[6].nr<4)
	 			aadata[i].typeface=1;
			else
				aadata[i].typeface=2;
		}
		if (aadata[i].face==7){		// face 8: avoid
			if (face[7].nr<4)
	 			aadata[i].typeface=1;
			else
				aadata[i].typeface=2;
		}
	}

	// 2. approach-avoidance task: determine blocknumber based on trial number
	for (i = 0; i < NTAATRIALS; i++) 
	{
			aadata[i].block=1 + i/32;
	}

	// 3.evalutive priming task task: randomise nr of face used as prime and type of target 
	int rndprime[NTPRIMETRIALS];
 	ts_rlist(16,8,rndprime);	// 16 combinations: 2*8
		
	for (i = 0; i < NTPRIMETRIALS; i++) {	// for each trial:
		primedata[i].targettype=rndprime[i]/NTFACES;
		primedata[i].face=rndprime[i]%NTFACES;

		// determine target word
 		if (primedata[i].targettype==1){
 			j=ts_rint(6);
 			strcpy(primedata[i].target,posword[j].word);
		}	// for pos target: random word chosen
 		else {
 			j=ts_rint(6);
 			strcpy(primedata[i].target,negword[j].word);
		}	// for neg target: random word chosen

		// determine correct response
		if (((primedata[i].targettype==1)&&(primedata[i].hand==1))||((primedata[i].targettype==0)&&(primedata[i].hand==2)))
			primedata[i].xr=5;		// left response: 'e'
		else
			primedata[i].xr=6;		// right response: 'i'

		// determine whether prime is an approached/avoided face
		if (primedata[i].face==0){
			if (face[0].nr<4)
	 			primedata[i].typeface=1;	// type = approached
			else
				primedata[i].typeface=2;	// type = avoided
		}
		if (primedata[i].face==1){
			if (face[1].nr<4)
	 			primedata[i].typeface=1;
			else
				primedata[i].typeface=2;
		}
		if (primedata[i].face==2){
			if (face[2].nr<4)
	 			primedata[i].typeface=1;
			else
				primedata[i].typeface=2;
		}
		if (primedata[i].face==3){
			if (face[3].nr<4)
	 			primedata[i].typeface=1;
			else
				primedata[i].typeface=2;
		}
		if (primedata[i].face==4){
			if (face[4].nr<4)
	 			primedata[i].typeface=1;
			else
				primedata[i].typeface=2;
		}
		if (primedata[i].face==5){
			if (face[5].nr<4)
	 			primedata[i].typeface=1;
			else
				primedata[i].typeface=2;
		}
		if (primedata[i].face==6){
			if (face[6].nr<4)
	 			primedata[i].typeface=1;
			else
				primedata[i].typeface=2;
		}
		if (primedata[i].face==7){
			if (face[7].nr<4)
	 			primedata[i].typeface=1;
			else
				primedata[i].typeface=2;
		}
	}

	// 4. evaluative priming task: determine blocknumber based on trialnumber
	for (i = 0; i < NTPRIMETRIALS; i++) {
		primedata[i].block=1 + i/32;
	}
}

#ifndef TRIAL		// if trial document is not programmed yet, just run this reduced main function
int main()
{
    initialise();
    randomise(2,'m');
    aawrite(2);
	primewrite(2);

    return 0;
}

END_OF_MAIN();

#endif
