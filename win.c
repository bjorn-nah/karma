

win()
{
int joie;
	cls();
	init_satb();
	reset_satb();
	
	set_color(0,0); /* Je veux le noir */
	set_color(1,511); /* Je veux le blanc */
	set_font_color(1, 0);
	load_default_font();
	put_string("A winner is you !!", 0, 0);
	put_string("Press Run to restart.", 0, 0);
	vsync(120);
	main();
	/* for(;;)
	{	
		joie = joy(0);
		if (joie & JOY_STRT) main();
	} */
}