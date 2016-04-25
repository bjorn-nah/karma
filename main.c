#include "huc.h"

#include "tirage.c"


main()
{
	int joie;
	int decalage_credits;
	decalage_credits = 10;
	
	
	cls();
	init_satb();
	reset_satb();

	
	set_color(0,0); /* Je veux le noir */
	set_color(1,511); /* Je veux le blanc */
	set_font_color(1, 0);
	load_default_font();
	put_string("..:: Tales of the Unemployed ::..", 0, 3);
put_string(" __-- Push RUN --__",8,6);

put_string("GFX",0,decalage_credits);
put_string("- Florian Dufour",1,decalage_credits+1);
put_string("- Bjorn",1,decalage_credits+2);

put_string("SOUND",0,decalage_credits+4);
put_string("- MrKaos",1,decalage_credits+5);
put_string("- Bjorn",1,decalage_credits+6);

put_string("CODE",0,decalage_credits+8);
put_string("- Bjorn",1,decalage_credits+9);
put_string("- Cr30s",1,decalage_credits+10);

put_string("MISC",0,decalage_credits+12);
put_string("- Phaphe's mom & dad",1,decalage_credits+13);
put_string("- Astrofra & Scorpheus",1,decalage_credits+14);
put_string("- Movida Production",1,decalage_credits+15);
put_string("- #GGJ16 @ Orleans",1,decalage_credits+16);


 prev_right = -1;
 prev_wrong = -1;
	
	for(;;)
	{	
		joie = joy(0);
		if (joie & JOY_STRT) tirage();
	}
}