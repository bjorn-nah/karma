

lose()
{
int joie;
	cls();
	init_satb();
	reset_satb();

	day = 0;
	set_color(0,0); /* Je veux le noir */
	set_color(1,511); /* Je veux le blanc */
	set_font_color(1, 0);
	load_default_font();
	put_string("A loser is you pathetic human.", 0, 0);
	put_string("Morbo wants you to press Run.", 0, 0);
	
		vsync(120);
	for(;;)
	{	
		joie = joy(0);
		if (joie & JOY_STRT) main();
	}
}