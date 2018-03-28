/* 
	MAIN script file: 
  	Name: exp_aaExperiment.c
	Author: PVD
	Info:
		To interpret script: first read data_AAexperiment.c, then 
		rnd_AAexperiment.c, then trial_AAexperiment.c, then this 
		exp_AAexperiment.c file
*/

#define EXP						// programming of this exp document is finished
#include "trial_AAexperiment.c"	// first run trial_AAexperiment.c-file that makes trials (and runs rnd_AAexperiment and data_AAexperiment that initializes and randomizes all vars)


/* 
	Function for presenting the first instructions (experiment instrs general) 
	telling pps that they will perform different tasks in the experiment 
*/
void expinstructions()			// all instructions presented in Dutch
{
	ts_font(REG,20,ARIAL);
    ts_printf(ax(-.70), ay(.50), "Dank u om deel te nemen aan dit experiment.");
	ts_printf(ax(-.70), ay(.20), "In dit experiment zal u verschillende taken moeten uitvoeren.");
	ts_printf(ax(-.70), ay(.05), "Voor elke taak krijgt u op het scherm uitleg over wat u moet doen. ");
	ts_printf(ax(-.70), ay(-.10), "Als u een vraag hebt kan u die steeds stellen aan de experimentleider.");
	ts_printf(ax(-.70), ay(-.65), "Als je klaar bent om te beginnen klik je op het pijltje...");
    ts_button(0, -ay(.8));
	ts_clrscr();
}

/* 
	Function for presenting first approach-avoidance task instructions 
	telling pps what to do in this task
*/
void aainstructions1(ppnr)
{
	ts_font(REG,20,ARIAL);
   	ts_printf(ax(-.70), ay(.50), "Zo dadelijk zie je op het scherm foto's van personen.");
	ts_printf(ax(-.70), ay(.30), "Rond deze foto's zal een kader staan. ");
	if ((ppnr<33 &&((ppnr%8==1)||(ppnr%8==2)||(ppnr%8==3)||(ppnr%8==4)))||(ppnr>32&&((ppnr%8==5)||(ppnr%8==6)||(ppnr%8==7)||(ppnr%8==0)))){
		// half pps approach blue frame-photos and avoid green frame photos (hand AA bs-variable)
		ts_printf(ax(-.70), ay(.10), "Een foto met een blauw kader moet u benaderen door deze naar u toe te trekken met de joystick.");
		ts_printf(ax(-.70), ay(-.05), "Een foto met een groen kader moet u vermijden door deze van u weg te duwen met de joystick.");
		}
	else {
		// half pps approach green frame-photos and avoid blue frame photos (hand AA bs-variable)
		ts_printf(ax(-.70), ay(.10), "Een foto met een groen kader moet u benaderen door deze naar u toe te trekken met de joystick.");
		ts_printf(ax(-.70), -ay(.05), "Een foto met een blauw kader moet u vermijden door deze van u weg te duwen met de joystick.");
		}
	ts_printf(ax(-.70), -ay(.30), "Onthoud deze instructies goed !");
	ts_printf(ax(-.70), -ay(.60), "Klik op het pijltje om verder te gaan.");
    ts_button(0, -ay(.7));
	ts_clrscr();
}

/* 
	Function for presenting part two of approach-avoidance task instructions
	telling pps which faces they will see
*/
void aainstructions2(ppnr)
{
	struct{
	__int64 junk5;
	} tmp5;
    int k;

	// all pps only learn which faces they will see and not which they will approach and which they avoid (in contrast to EXP 1)	
	ts_printf_centre(0, ay(.95), "Dit zijn de gezichten die u zal zien tijdens deze taak:");
	if (ppnr%2==0){
		for (k=0;k<NTFACES;k++){
			if (face[k].nr==4)
				ts_blit(bmp[k+33], ax(-.75), ay(.50));
		}
		for (k=0;k<NTFACES;k++){
			if (face[k].nr==1)
				ts_blit(bmp[k+33], ax(-.25), ay(.50));
		}
		for (k=0;k<NTFACES;k++){
			if (face[k].nr==2)
				ts_blit(bmp[k+33], ax(.25), ay(.50));
		}
		for (k=0;k<NTFACES;k++){
			if (face[k].nr==7)
				ts_blit(bmp[k+33], ax(.75), ay(.50));
		}
		for (k=0;k<NTFACES;k++){
			if (face[k].nr==0)
				ts_blit(bmp[k+33], ax(-.75), ay(-.25));
		}
		for (k=0;k<NTFACES;k++){
			if (face[k].nr==5)
				ts_blit(bmp[k+33], ax(-.25), ay(-.25));
		}
		for (k=0;k<NTFACES;k++){
			if (face[k].nr==6)
				ts_blit(bmp[k+33], ax(.25), ay(-.25));
		}
		for (k=0;k<NTFACES;k++){
			if (face[k].nr==3)
				ts_blit(bmp[k+33], ax(.75), ay(-.25));
		}
	}
	else { 
		for (k=0;k<NTFACES;k++){
			if (face[k].nr==0)
				ts_blit(bmp[k+33], ax(-.75), ay(.50));
		}
		for (k=0;k<NTFACES;k++){
			if (face[k].nr==5)
				ts_blit(bmp[k+33], ax(-.25), ay(.50));
		}
		for (k=0;k<NTFACES;k++){
			if (face[k].nr==6)
				ts_blit(bmp[k+33], ax(.25), ay(.50));
		}
		for (k=0;k<NTFACES;k++){
			if (face[k].nr==3)
				ts_blit(bmp[k+33], ax(.75), ay(.50));
		}
		for (k=0;k<NTFACES;k++){
			if (face[k].nr==4)
				ts_blit(bmp[k+33], ax(-.75), ay(-.25));
		}
		for (k=0;k<NTFACES;k++){
			if (face[k].nr==1)
				ts_blit(bmp[k+33], ax(-.25), ay(-.25));
		}
		for (k=0;k<NTFACES;k++){
			if (face[k].nr==2)
				ts_blit(bmp[k+33], ax(.25), ay(-.25));
		}
		for (k=0;k<NTFACES;k++){
			if (face[k].nr==7)
				ts_blit(bmp[k+33], ax(.75), ay(-.25));
		}
	}
	
	ts_printf_centre(0,-ay(.90), "Klik op knop 2 op de joystick om te starten met de taak.");
    ts_resp(&tmp5.junk5,&tmp5.junk5,0);
	ts_clrscr();
	ts_font(REG,26,ARIAL);
}

/* 
	Function for presenting instructions in between approach-avoidance tasks blocks
*/
void blockaa()
{
	struct{
	__int64 junk1;
	} tmp1;
	ts_font(REG,20,ARIAL);
    ts_printf_centre(0, 100, "PAUZE");
	ts_printf_centre(0, 30, "Je hebt al de helft van de taak afgewerkt !");
	ts_printf_centre(0, 0, "Blijf gefocust ! Werk snel en accuraat !");
    ts_printf_centre(0, -75, "Als je klaar bent om aan de volgende reeks te beginnen"); 
	ts_printf_centre(0, -100, "klik je op knop 2 op de joystick...");
    ts_resp(&tmp1.junk1,&tmp1.junk1,0);
    ts_clrscr();
	ts_font(REG,26,ARIAL);
}

/* 
	Function for presenting evaluative priming task instructions telling pps
	to judge targetwords as pos/neg
*/
void primeinstructions(ppnr)
{
	struct{
	__int64 junk7;
	} tmp7;

	ts_font(REG,20,ARIAL);
	ts_printf(ax(-.80), ay(.80), "Je hebt de eerste helft van dit experiment afgerond !");
	ts_printf(ax(-.80), ay(.70), "Zet nu de joystick even aan de kant.");
    ts_printf(ax(-.80), ay(.55), "In de volgende taak moet je beoordelen of een woord positief of negatief is.");
	ts_printf(ax(-.80), ay(.45), "Probeer dit zo snel mogelijk te doen, terwijl je zo weinig mogelijk fouten maakt."); 
	ts_printf(ax(-.80), ay(.25), "Voor elk woord zal je ook een foto zien."); 
	ts_printf(ax(-.80), ay(.15),"Je kan deze bekijken, maar je taak is enkel om op de woorden te reageren.");
	ts_printf(ax(-.80), ay(-.05), "Je beoordeelt het woord door op de toets 'e' of 'i' te drukken.");


 	if ((ppnr<17 &&((ppnr%8==1)||(ppnr%8==4)||(ppnr%8==5)||(ppnr%8==0)))||(ppnr>16&&ppnr<49&&((ppnr%8==2)||(ppnr%8==3)||(ppnr%8==6)||(ppnr%8==7)))||(ppnr>48&&((ppnr%8==1)||(ppnr%8==4)||(ppnr%8==5)||(ppnr%8==0)))){
  		// Half of the pps use left key 'e' for pos words  and 'i' for neg words(hand ept bs-variable=1)
		ts_printf(ax(-.80), ay(-.20), "Druk op 'e' als je een positief woord ziet.");
		ts_printf(ax(-.80), ay(-.35), "Druk op 'i' als je een negatief woord ziet.");
	}

	else {
		// Half of the pps use left key 'e' for neg words  and 'i' for pos words (hand ept bs-variable=1)
		ts_printf(ax(-.80), ay(-.20), "Druk op 'e' als je een negatief woord ziet.");
		ts_printf(ax(-.80), ay(-.35), "Druk op 'i' als je een positief woord ziet.");
	}

	ts_printf(ax(-.80), ay(-.65), "Als je klaar bent om te beginnen druk je op de spatiebalk...");
    ts_resp(&tmp7.junk7,&tmp7.junk7,0);
    ts_clrscr();
	ts_font(REG,26,ARIAL);
}

/* 
	Function for presenting instructions after first block of evaluative
	priming task
*/
void blocka()
{
	struct{
	__int64 junk2;
	} tmp2;
	ts_font(REG,20,ARIAL);
    ts_printf_centre(0, 100, "PAUZE");
    ts_printf_centre(0, -50, "Als je klaar bent om aan de volgende reeks te beginnen"); 
	ts_printf_centre(0, -80, "druk je op de spatiebalk...");
    ts_resp(&tmp2.junk2,&tmp2.junk2,0);
    ts_clrscr();
	ts_font(REG,26,ARIAL);
	ts_wait(mtt(1000));
}

/* 
	Function for presenting instructions after second block of evaluative
	priming task
*/
void blockb()
{
	struct{
	__int64 junk3;
	} tmp3;
	ts_font(REG,20,ARIAL);
    ts_printf_centre(0, 100, "PAUZE");
	ts_printf_centre(0, 30, "Je hebt al de helft van de taak afgewerkt !");
	ts_printf_centre(0, 0, "Blijf gefocust ! Werk snel en accuraat !");
    ts_printf_centre(0, -75, "Als je klaar bent om aan de volgende reeks te beginnen"); 
	ts_printf_centre(0, -100, "druk je op de spatiebalk...");
    ts_resp(&tmp3.junk3,&tmp3.junk3,0);
    ts_clrscr();
	ts_font(REG,26,ARIAL);
	ts_wait(mtt(1000));
}

/* 
	Function for presenting instructions after third block of evaluative
	priming task
*/
void blockc()
{
	struct{
	__int64 junk4;
	} tmp4;
	ts_font(REG,20,ARIAL);
    ts_printf_centre(0, 100, "PAUZE");
	ts_printf_centre(0, 30, "Nog eventjes ! Blijf ook voor de laatste woorden gefocust ! ");
    ts_printf_centre(0, -75, "Als je klaar bent om aan de volgende reeks te beginnen"); 
	ts_printf_centre(0, -100, "druk je op de spatiebalk.");
    ts_resp(&tmp4.junk4,&tmp4.junk4,0);
    ts_clrscr();
	ts_font(REG,26,ARIAL);
	ts_wait(mtt(1000));
}

/* 
	Function for asking explicit ratings for each of the faces
*/
void explicitinstructions(ppnr)
{
	ts_font(REG,20,ARIAL);
	int k[NTFACES];
	int l;
	ts_rlist(NTFACES,1,k);

	if (ppnr%4==0||ppnr%4==3){
		// half of the pps first give liking ratings and then friendliness
		// liking ratings
		for(l = 0; l<NTFACES; l++){
			ts_printf_centre(0, ay(.95), "In welke mate vind je dit gezicht aangenaam?");
			ts_blit(bmp[k[l]+1], 0, ay(.30));
    		ts_printf_centre(0, ay(-.4), "0           1          2          3          4          5           6          7");
			ts_line (ax(-.7),ay(-.44),ax(.7),ay(-.44));
			ts_printf(ax(-.87),ay(-.50),"helemaal niet aangenaam      niet aangenaam                     aangenaam             heel aangenaam");
			ts_printf_centre(0, ay(-.65), "Toets een cijfer in tussen 0 en 7:");
			do {
				ts_scanf(ax(.3), ay(-.65), "%d", &face[k[l]].rating);
			}
			while (face[k[l]].rating<0||face[k[l]].rating>7);
    		ts_clrscr();
		}
		// friendliness ratings
		ts_printf(ax(-.80), ay(.30), "Nu beoordeel je de vriendelijkheid van de persoon.");
		ts_printf(ax(-.80), ay(-.10), "Klik op het pijltje om verder te gaan...");
		ts_button(0,ay(-.30));
		ts_clrscr();
		for(l = 0; l<NTFACES; l++){
			ts_printf_centre(0, ay(.95), "In welke mate vind je deze persoon vriendelijk?");
			ts_blit(bmp[k[l]+1], 0, ay(.30));
    		ts_printf_centre(0, ay(-.4), "0           1          2          3          4          5           6          7");
			ts_line (ax(-.7),ay(-.44),ax(.7),ay(-.44));
			ts_printf(ax(-.85),ay(-.50),"helemaal niet vriendelijk       niet vriendelijk                      vriendelijk             heel vriendelijk");
			ts_printf_centre(0, ay(-.65), "Toets een cijfer in tussen 0 en 7:");
			do {
				ts_scanf(ax(.3), ay(-.65), "%d", &face[k[l]].friendly);
			}
			while (face[k[l]].friendly<0||face[k[l]].friendly>7);
    		ts_clrscr();
		}
	}
	else {
		// half of the pps first give friendliness ratings and then liking
		// friendliness ratings
		for(l = 0; l<NTFACES; l++){
			ts_printf_centre(0, ay(.95), "In welke mate vind je deze persoon vriendelijk?");
			ts_blit(bmp[k[l]+1], 0, ay(.30));
   		 	ts_printf_centre(0, ay(-.4), "0           1          2          3          4          5           6          7");
			ts_line (ax(-.7),ay(-.44),ax(.7),ay(-.44));
			ts_printf(ax(-.85),ay(-.50),"helemaal niet vriendelijk       niet vriendelijk                      vriendelijk             heel vriendelijk");
			ts_printf_centre(0, ay(-.65), "Toets een cijfer in tussen 0 en 7:");
			do {
				ts_scanf(ax(.3), ay(-.65), "%d", &face[k[l]].friendly);
			}
			while (face[k[l]].friendly<0||face[k[l]].friendly>7);
    		ts_clrscr();
		}
		// liking ratings
		ts_printf(ax(-.80), ay(.30), "Nu beoordeel je hoe aangenaam je het gezicht vindt.");
		ts_printf(ax(-.80), ay(-.10), "Klik op het pijltje om verder te gaan...");
		ts_button(0,ay(-.30));
		ts_clrscr();
		for(l = 0; l<NTFACES; l++){
			ts_printf_centre(0, ay(.95), "In welke mate vind je dit gezicht aangenaam?");
			ts_blit(bmp[k[l]+1], 0, ay(.30));
    		ts_printf_centre(0, ay(-.4), "0           1          2          3          4          5           6          7");
			ts_line (ax(-.7),ay(-.44),ax(.7),ay(-.44));
			ts_printf(ax(-.87),ay(-.50),"helemaal niet aangenaam      niet aangenaam                     aangenaam             heel aangenaam");
			ts_printf_centre(0, ay(-.65), "Toets een cijfer in tussen 0 en 7:");
			do {
				ts_scanf(ax(.3), ay(-.65), "%d", &face[k[l]].rating);
			}
			while (face[k[l]].rating<0||face[k[l]].rating>7);
    		ts_clrscr();
		}
	}
	
	ts_font(REG,20,ARIAL);
}

/* 
	Function for asking final debriefing questions
*/
void debriefinginstructions()
{
	ts_font(REG,20,ARIAL);
	int l;

	// q1: asoften question: do you think each face was as often approached as avoided
	ts_printf_centre(0, ay(.95), "Denk je dat je elk gezicht ongeveer even vaak hebt moeten benaderen als vermijden?");
	ts_printf_centre(0, ay(.65), "Toets een cijfer in tussen 1 en 2 (1 = ja; 2 = nee):"  );
	do {
		ts_scanf(ax(.5), ay(.65), "%d", &asoften);}
	while (asoften<1||asoften>2);

	ts_clrscr();

	// q2: for each face: what action did you do most often
	for(l = 0; l<NTFACES; l++){
		ts_printf_centre(0, ay(.95), "Welke actie heb je het vaakst moeten uitvoeren bij het zien van dit gezicht?");
		ts_blit(bmp[l+1], 0, ay(.30));
    	ts_printf_centre(0, ay(-.3), " 1 = benaderen  2 = vermijden  3 = beide acties even vaak  4 = ik heb echt geen enkel idee");
		ts_printf_centre(0, ay(-.36), "  Toets cijfer 1, 2, 3 of 4 in : ");
		do {
			ts_scanf(ax(.35), ay(-.36), "%d", &face[l].action);
		}
		while (face[l].action<1||face[l].action>4);
		if (face[l].nr<4)
			face[l].type=1;
		else face[l].type=2;
		if (face[l].action==face[l].type)
			face[l].ca=1;		// computes ca-variable: for this face was pp contingency aware or not?
		else
			face[l].ca=0;

		ts_printf_centre(0, ay(-.5), "Hoe zeker ben je van dit antwoord?"); // confidence variable for each face: how confident that that was the contingency?
		ts_printf_centre(0, ay(-.6), "Toets een cijfer in tussen 1 en 3 (1 = niet zeker, 2 = eerder zeker, 3 = heel zeker):");
		do {
			ts_scanf(ax(.77), ay(-.6), "%d", &face[l].confident);}
		while (face[l].confident<1||face[l].confident>3);
		if (face[l].action==3||face[l].action==4) {
		ts_printf_centre(0, ay(-.74), "In hoeveel procent van de keren dat je dit gezicht zag moest je dit gezicht benaderen?");
		ts_printf_centre(0, ay(-.84), "Toets een cijfer in tussen 0 en 100 (allebei even veel = 50) :");
		do {
			ts_scanf(ax(.60), ay(-.84), "%d", &face[l].percent);}
		while (face[l].percent<0||face[l].percent>100);
		}

		else {
		ts_printf_centre(0, ay(-.74), "In hoeveel procent van de keren dat je dit gezicht zag moest je die actie uitvoeren?");
		ts_printf_centre(0, ay(-.84), "Toets een cijfer in tussen 0 en 100 (allebei even veel = 50) :");
		do {
			ts_scanf(ax(.60), ay(-.84), "%d", &face[l].percent);}
		while (face[l].percent<50||face[l].percent>100);
		}
    	ts_clrscr();
	}

	// Pauze for administering debriefing questionnaire in paper
	ts_printf_centre(0, ay(.70), "Roep nu even de proefleider.");
	ts_scanf(ax(-.90), ay(.6), "%[^\n]", &goal);
	ts_clrscr();

	// q3: goal2 variable: when did you think we tried to change attitudes?
	ts_printf_centre(0, ay(.20), "Hebt u tijdens het experiment ooit gedacht dat we uw attitude ten opzichte van de personen op de foto's wilden veranderen? ");
	ts_printf_centre(0, ay(.10), "Indien ja, wanneer dacht u dit voor het eerst? ");
	ts_printf_centre(0, ay(-.05), " 1 = ja, van bij de eerste instructies      2 = ja, tijdens de joystick taak      3 = ja, tijdens de categorisatietaak");
	ts_printf_centre(0, ay(-.15)," 4 = ja, tijdens de vragen over de foto's     5 = ja, op dit moment     6 = nee, nooit");
	ts_printf_centre(0, ay(-.30), "  Toets cijfer 1, 2, 3, 4, 5 of 6 in : ");
	do {
		ts_scanf(ax(.35), ay(-.30), "%d", &goal2);}
	while (goal2<1||goal2>6);

	// q4: belief variable: do you believe attitudes were changed?
	ts_printf_centre(0, ay(-.50), "In welke mate denk je dat uw attitude ten opzichte van de gezichten is veranderd?");
	ts_printf_centre(0, ay(-.60), "0       1        2       3       4       5        6       7");
	ts_line (ax(-.6),ay(-.64),ax(.6),ay(-.64));
	ts_printf_centre(0,ay(-.67),"helemaal niet         niet                     wel             heel veel");
	ts_printf_centre(0, ay(-.85), "Toets een cijfer in tussen 0 en 7:");
	do {
		ts_scanf(ax(.40), ay(-.85), "%d", &belief);}
	while (belief<0||belief>7);
	ts_font(REG,20,ARIAL);
	ts_clrscr();

	// q5: approach variable: do you like word 'approach'?
	ts_printf_centre(0, ay(.70), "Hoe positief zijn je gevoelens voor het woord 'benader'?");
	ts_printf_centre(0, ay(.60), "0       1        2       3       4       5        6       7");
	ts_line (ax(-.6),ay(.56),ax(.6),ay(.56));
	ts_printf_centre(0,ay(.53),"helemaal niet         niet                     wel             heel positief");
	ts_printf_centre(0, ay(.35), "Toets een cijfer in tussen 0 en 7:");
	do {
		ts_scanf(ax(.40), ay(.35), "%d", &approach);}
	while (approach<0||approach>7);

	// q6: avoid variable: do you like word 'avoid'?
	ts_printf_centre(0, ay(.10), "Hoe positief zijn je gevoelens voor het woord 'vermijd'?");
	ts_printf_centre(0, ay(.0), "0       1        2       3       4       5        6       7");
	ts_line (ax(-.6),ay(-.04),ax(.6),ay(-.04));
	ts_printf_centre(0,ay(-.07),"helemaal niet         niet                     wel             heel positief");
	ts_printf_centre(0, ay(-.25), "Toets een cijfer in tussen 0 en 7:");
	do{
		ts_scanf(ax(.40), ay(-.25), "%d", &avoid);}
	while (avoid<0||avoid>7);
	ts_clrscr();

	// q7: reactivity questionnaire (hong's psychological reactance scale)
	ts_printf_centre(0, ay(.90), "Beoordeel deze uitspraken op een schaal van 1 tot 5:");
	ts_printf_centre(0, ay(.80), "       1             2           3           4            5        ");
	ts_line (ax(-.6),ay(.76),ax(.6),ay(.76));
	ts_printf_centre(0,ay(.73),"helemaal niet juist                                        helemaal juist");
	ts_printf_centre(0, ay(.55), "Ik beschouw advies van anderen als een inbreuk op mijn vrijheid:");
	do {
	ts_scanf(ax(.80), ay(.55), "%d", &resistance1);}
	while (resistance1<1||resistance1>5);
	ts_printf_centre(0, ay(.45), "Regelgevingen en afspraken lokken bij mij een gevoel van weerstand uit:");
	do {
		ts_scanf(ax(.80), ay(.45), "%d", &resistance2);}
	while (resistance2<1||resistance2>5);
	ts_printf_centre(0, ay(.35), "Ik geraak gefrustreerd wanneer ik niet in staat ben vrije en onafhankelijke beslissingen te nemen:");
	do {
		ts_scanf(ax(.80), ay(.35), "%d", &resistance3);}
	while (resistance3<1||resistance3>5);
	ts_printf_centre(0, ay(.25), "Advies en aanbevelingen zetten me aan om het omgekeerde te doen:");
	do {
		ts_scanf(ax(.80), ay(.25), "%d", &resistance4);}
	while (resistance4<1||resistance4>5);
	ts_printf_centre(0, ay(.15), "Het irriteert me wanneer iemand iets dat ik al duidelijk vind nog eens extra wil verduidelijken:");
	do {
		ts_scanf(ax(.80), ay(.15), "%d", &resistance5);}
	while (resistance5<1||resistance5>5);
	ts_printf_centre(0, ay(.05), "Ik vind het leuk om anderen tegen te spreken:");
	do {
		ts_scanf(ax(.80), ay(.05), "%d", &resistance6);}
	while (resistance6<1||resistance6>5);
	ts_printf_centre(0, ay(-.05), "Ik word kwaad wanneer mijn keuzevrijheid beperkt wordt:");
	do {
		ts_scanf(ax(.80), ay(-.05), "%d", &resistance7);}
	while (resistance7<1||resistance7>5);
	ts_printf_centre(0, ay(-.15), "Wanneer iets wordt verboden, denk ik vaak: 'En toch is dat exact wat ik ga doen': ");
	do {
		ts_scanf(ax(.80), ay(-.15), "%d", &resistance8);}
	while (resistance8<1||resistance8>5);
	ts_printf_centre(0, ay(-.25), "Ik weersta goed aan de pogingen van anderen om me te beïnvloeden:");
	do {
		ts_scanf(ax(.80), ay(-.25), "%d", &resistance9);}
	while (resistance9<1||resistance9>5);
	ts_printf_centre(0, ay(-.35), "Het maakt me kwaad wanneer men iemand anders voorhoudt als een voorbeeld dat ik moet volgen:");
	do {
		ts_scanf(ax(.80), ay(-.35), "%d", &resistance10);}
	while (resistance10<1||resistance10>5);
	ts_printf_centre(0, ay(-.45), "Wanneer iemand me verplicht om iets te doen, wil ik liever het tegenovergestelde doen:");
	do {
		ts_scanf(ax(.80), ay(-.45), "%d", &resistance11);}
	while (resistance11<1||resistance11>5);
	ts_clrscr();
	resistancetotal=resistance1+resistance2+resistance3+resistance4+resistance5+resistance6+resistance7+resistance8+resistance9+resistance10+resistance11;// compute total reactance score
}

/* 
	Function for running the whole experiment: the main experiment function
*/
int main()
{    
	//ts_priority(HIGH);  		// set priority to high: do slashes away when collecting data ! 
	ts_scrsize(SIZE2);
	//ts_scrsize(SIZE7);		// set screen size: on experiment cpu: 1600x1200
	//ts_scrmode(FULLSCREEN);	// set to full screen mode
	ts_font(REG,16,ARIAL);
	ts_coordinates(STANDARD);
		
	int i;
    int ok;
    int nr;
	char mv;
    int x = 30, y = 30, w;
    
 	// register participant number (enter manually)
	w=ts_printf(x, y, " proefpersoon nummer: ");
	ts_scanf(x + w, y, "%d", &nr);

	// register participant gender
    do {
        w = ts_printf(x, y+50, " m/v: ");
        ok = ts_scanf(x + w, y+50, "%c", &mv);
    } while (ok != 1 || (mv !='m' && mv !='v'));

    ts_clrscr();
    ts_coordinates(CARTESIAN);

	// procedure of the experiment
	    
    initialise();			// initialise vars
    randomise(nr,mv);		// randomise vars
	ts_setserialport(4);
	ts_defkey(J2);			// define keys: 1=Joystick button 2, 2= joystick button 3, 3= escape, 4= joystick button 4, 5=E key, 6=I key, 7 = space bar
	ts_defkey(J3);
   	ts_defkey(KEY_ESC);
	ts_defkey(J4);
	ts_defkey(KEY_E);
    ts_defkey(KEY_I);
	ts_defkey(KEY_SPACE);

	expinstructions();			// 1. experiment instructions general
    aainstructions1(nr);		// 2. instructions for approach-avoid task (page 1+ 2)
	aainstructions2();

	// 3. run 192 approach-avoidance task trials 
	// and pauze screen after half of trials
    for (i = 0; i < NTAATRIALS; i++) {          
        aatrial(i);
		if (i==96)
			blockaa();	
    }
    aawrite(nr);				// write away data of approach-avoid task

	if (order==1) {
		// for half the pps: first EPT and then ratings
		primeinstructions(nr);	// 4. instructions for evaluative priming task

		// 5. run 124 evaluative priming task trials 
		// and pauze screen after 1/4th, 2/4th, 3/4th of trials
		 for (i = 0; i < NTPRIMETRIALS; i++) {          
     	   primetrial(i);  
			if (i==32)
				blocka();
			if (i==64)
				blockb();
			if (i==96)
				blockc();  
		}
		primewrite(nr);				// write away data of evaluative priming task

		explicitinstructions(nr);	// 6. explicit ratings
	}

	else {
		// for other half of the pps: first ratings and then EPT
		explicitinstructions(nr);	// 4. explicit ratings
		primeinstructions(nr);		// 5. instructions for evaluative priming task

		// 6. run 124 evaluative priming task trials 
		// and pauze screen after 1/4th, 2/4th, 3/4th of trials
	 	for (i = 0; i < NTPRIMETRIALS; i++) {          
      	  primetrial(i);  
			if (i==32)
				blocka();
			if (i==64)
				blockb();
			if (i==96)
				blockc();  
		}
		primewrite(nr);			// write away data of evaluative priming task
	}

	debriefinginstructions();		// 7. answer debriefing questions
	explicitwrite(nr);			// write away data of rating and debriefing questions
	
	// 8. thank pps for participation	
	ts_printf_centre(0, 0, "Einde van dit experiment");
    ts_printf_centre(0, ay(-.40), "Bedankt voor je deelname ! "); 
	ts_button(0, -ay(.5));

    return 0;
}

END_OF_MAIN();
