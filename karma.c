/*#include "huc.h"*/
#include "sound/sndDefs.h"
#include "sprite.h"
#include "win.c"
#include "lose.c"

#include "sound/psglib.c"
#include "snginit.c"

#define DIR_LEFT 1
#define DIR_RIGHT 2
#define DIR_UP 3
#define DIR_DOWN 4
#define DIR_LEFT_UP 5
#define DIR_RIGHT_UP 6
#define DIR_LEFT_DOWN 7
#define DIR_RIGHT_DOWN 8

#define DECAL 8
#define SLOW 4

#define SCR_W 17
#define SCR_H 16



#incspr(sprite,"guy.pcx",0,0,2,18);
#incpal(spritepal,"guy.pcx");

#incbin(levelmap,"apartment.FMP");
#inctile_ex(leveltiles,"Tilesetzuu.pcx",0,0,22,6,0);
#incpal(levelpal,"Tilesetzuu.pcx");

/*++SOUND*/
/*++SOUND*/

int VSyncCnt;
int TimerCnt;
int MainCnt;
int SubCnt;
/*++SOUND*/



int tics_sprite, frame_sprite, state_sprite, counter, decal_frame;
int j1, sprite_x, sprite_y, sprite_v, sprite_vx, sprite_vy, sprite_nx,sprite_ny;
int mapx, lastmapx, mapy, lastmapy, vmapx, vmapy;
/* int point_alice, point_lapin, play_state, max; */
char dir_sprite;



karma()
{
	
	/*++SOUND*/
	int  song;
	int  jsv;

	int  psgMainStatus;
	int  psgSubStatus;
	
	psgInit(5);
	psgOn(0); 			/* use timer for now : vsync works okay, but limits speed */
	psgPlay(0);
	
	sngInit();
	psgDelay( 0 );
	/*++SOUND*/
	
	counter = 0;
	tics_sprite = 0;
	frame_sprite = 0;
	state_sprite = 0;

	sprite_x = 256;
	sprite_y = 240;
	sprite_v = 0;
	dir_sprite = DIR_RIGHT;
	
	sprite_nx = sprite_x;
	sprite_ny = sprite_y;
	sprite_vx = sprite_x;
	sprite_vy = sprite_y;
	
	/* init maps */
	mapx = 0;
	lastmapx = 0;
	mapy = 0;
	lastmapy = 0;
	vmapx = 0;
	vmapy = 0;
	
	set_font_color(2, 1);
	load_default_font();
	

	
	set_map_data(levelmap,48,45);
	set_tile_data(leveltiles);
	load_tile(0x1000);
	load_map(0,0,0,0,17,16);
	load_palette(0,levelpal,1);
	
	spr_make(0,180,121,0x5000,FLIP_X_MASK|SIZE_MAS,FLIP_X|SZ_32x32,0,1);
	set_sprpal(0,spritepal,1);
	load_vram(0x5000,sprite,0x0900);
	
	/*++TOM++*/
	last_obj_index = 0;
	right_place_nb = 0;
	wrong_place_nb = 0;

	 /* last minute */
	 if (prev_right >= 0)right_place_nb = prev_right;
	 else prev_right = -1;
	 
	 if (prev_wrong >= 0)wrong_place_nb = prev_wrong;
	 else prev_wrong = -1;
	  /* last minute */
	  
	if (day <= 0)day = 1;

	objects[1] = "Initiate bowel movement."; 
	objects[2] = "Peruse adult magazines."; 
	objects[3] = "Add +1 to coffee addiction"; 
	objects[4] = "Melt your brain with TV."; 
	objects[5] = "Respawn ... to worse";
	objects[6] = "Chew down some butter sticks.";
	objects[7] = "Take a shower to hide your tears.";
	objects[8] = "Drugs, you just can't get enough.";


	tiles_w_obj[START_OBJ_TILES_NB+1] = 1;
	
	tiles_w_obj[START_OBJ_TILES_NB+2] = 2;
	
	tiles_w_obj[START_OBJ_TILES_NB+3] = 3;
	
	tiles_w_obj[START_OBJ_TILES_NB+4] = 4;
	tiles_w_obj[START_OBJ_TILES_NB+5] = 4;
	tiles_w_obj[START_OBJ_TILES_NB+6] = 4;
	tiles_w_obj[START_OBJ_TILES_NB+7] = 4;
	
	tiles_w_obj[START_OBJ_TILES_NB+8] = 5;
	tiles_w_obj[START_OBJ_TILES_NB+9] = 5;
	tiles_w_obj[START_OBJ_TILES_NB+10] = 5;
	tiles_w_obj[START_OBJ_TILES_NB+11] = 5;
	tiles_w_obj[START_OBJ_TILES_NB+12] = 5;
	tiles_w_obj[START_OBJ_TILES_NB+13] = 5;
	tiles_w_obj[START_OBJ_TILES_NB+14] = 5;
	tiles_w_obj[START_OBJ_TILES_NB+15] = 5;
	
	tiles_w_obj[START_OBJ_TILES_NB+16] = 6;
	tiles_w_obj[START_OBJ_TILES_NB+17] = 6;
	
	tiles_w_obj[START_OBJ_TILES_NB+18] = 7;
	tiles_w_obj[START_OBJ_TILES_NB+19] = 7;
	tiles_w_obj[START_OBJ_TILES_NB+20] = 7;
	tiles_w_obj[START_OBJ_TILES_NB+21] = 7;
	
	tiles_w_obj[START_OBJ_TILES_NB+22] = 8;
	
	tiles_w_obj[START_OBJ_TILES_NB+23] = 3;

	/* init action_stack with 0s */
	for(j = 0;j<MAX_OBJ_LS;j++){
		action_stack[j] = 0;
	}

	/* set 5 random objects in reference_stack */


	/* for(j = 0;j<MAX_OBJ_LS;j++){
		r = rdm_objects(OBJECTS_NB);
		reference_stack[j] = r;
	} */
	/*++TOM++*/
	

	place_map();
				put_string(":.: DAY ",0,13);
	put_number(day, 2,9, 13);
	put_string(" :.:", 11, 13);
	
	/* put_string(" right_place_nb", 11, 13);
	put_string(" :.:", 11, 13);
	right_place_nb
	right_place_nb */
	vsync(240);
	
	for(;;)
	{
		
		vsync();

			/*++SOUND*/
		psgMainStatus = psgMStat();
		psgSubStatus  = psgSStat();
			/*++SOUND*/
			
		j1 = joy(0);
		
		player_machine();
		physique();
		
		/* put_number(state_sprite, 5, 5, 1); */
		counter++;
		
		satb_update();
	}
}

player_machine()
{
	/*
	0 - Repos
	1 - Marche
	2 - Interaction
		5 - activer obj
*/

	spr_set(0);
	if ( state_sprite == 0) player_sprite_0();
	if ( state_sprite == 1) player_sprite_1();
	if ( state_sprite == 2) player_sprite_2();
	/*++TOM++*/
	if ( state_sprite == 5) player_sprite_5();
	
}

/* joueur */
player_sprite_0()
{
	if ( tics_sprite == 0 ) spr_pattern(0x5000);
	tics_sprite = 1;
	if (j1 & JOY_LEFT)
	{
		tics_sprite = 0;
		frame_sprite = 0;
		state_sprite = 1;
		spr_pattern(0x5200);
		dir_sprite = DIR_LEFT;
	}
	if (j1 & JOY_RGHT)
	{
		tics_sprite = 0;
		frame_sprite = 0;
		state_sprite = 1;
		spr_pattern(0x5200);
		dir_sprite = DIR_RIGHT;
	}
	if (j1 & JOY_UP)
	{
		tics_sprite = 0;
		frame_sprite = 0;
		state_sprite = 1;
		spr_pattern(0x5100);
		dir_sprite = DIR_UP;
	}
	if (j1 & JOY_DOWN)
	{
		tics_sprite = 0;
		frame_sprite = 0;
		state_sprite = 1;
		spr_pattern(0x5000);
		dir_sprite = DIR_DOWN;
	}
	
	if (j1 & JOY_LEFT && j1 & JOY_UP)
	{
		tics_sprite = 0;
		frame_sprite = 0;
		state_sprite = 1;
		spr_pattern(0x5100);
		dir_sprite = DIR_LEFT_UP;
	}
	if (j1 & JOY_RGHT && j1 & JOY_UP)
	{
		tics_sprite = 0;
		frame_sprite = 0;
		state_sprite = 1;
		spr_pattern(0x5100);
		dir_sprite = DIR_RIGHT_UP;
	}
	if (j1 & JOY_LEFT && j1 & JOY_DOWN)
	{
		tics_sprite = 0;
		frame_sprite = 0;
		state_sprite = 1;
		spr_pattern(0x5000);
		dir_sprite = DIR_LEFT_DOWN;
	}
	if (j1 & JOY_RGHT && j1 & JOY_DOWN)
	{
		tics_sprite = 0;
		frame_sprite = 0;
		state_sprite = 1;
		spr_pattern(0x5000);
		dir_sprite = DIR_RIGHT_DOWN;
	}
	
	/*++TOM++*/
	if (j1 & JOY_B)
	{
		state_sprite = 5;
	}
	/*++TOM++*/
	
	
	/*++TOM++*/
	if (j1 & JOY_A)
	{
		psgPlay( 1);
	}
	/*++TOM++*/
	
	
	
	
}

player_sprite_1()
{
	int walk_sprite, tmp_addr;
	walk_sprite = 0;
	tics_sprite++;
	if (tics_sprite > 10)
	{
		tics_sprite = 0;
		frame_sprite++;
		if (frame_sprite > 3) frame_sprite = 0;
		if (frame_sprite == 0) decal_frame = 0x0000;
		if (frame_sprite == 1) decal_frame = 0x0100;
		if (frame_sprite == 2) decal_frame = 0x0000;
		if (frame_sprite == 3) decal_frame = 0x0200;
	}
	/* put_hex(decal_frame, 5, 5, 3);
	put_number(tics_sprite, 5, 5, 4);
	put_number(frame_sprite, 5, 5, 5); */
	
	/*
	if ( tics_sprite == 0 ) spr_pattern(0x5000);
	tics_sprite = 1;
	*/
	if (j1 & JOY_LEFT)
	{
		tmp_addr = 0x5600 + decal_frame;
		spr_pattern(tmp_addr);
		dir_sprite = DIR_LEFT;
		walk_sprite = 1;
	}
	if (j1 & JOY_RGHT)
	{
		tmp_addr = 0x5600 + decal_frame;
		spr_pattern(tmp_addr);
		dir_sprite = DIR_RIGHT;
		walk_sprite = 1;
	}
	if (j1 & JOY_UP)
	{
		tmp_addr = 0x5300 + decal_frame;
		spr_pattern(tmp_addr);
		dir_sprite = DIR_UP;
		walk_sprite = 1;
	}
	if (j1 & JOY_DOWN)
	{
		tmp_addr = 0x5000 + decal_frame;
		spr_pattern(tmp_addr);
		dir_sprite = DIR_DOWN;
		walk_sprite = 1;
	}
	
	if (j1 & JOY_LEFT && j1 & JOY_UP)
	{
		tmp_addr = 0x5300 + decal_frame;
		spr_pattern(tmp_addr);
		dir_sprite = DIR_LEFT_UP;
		walk_sprite = 1;
	}
	if (j1 & JOY_RGHT && j1 & JOY_UP)
	{
		tmp_addr = 0x5300 + decal_frame;
		spr_pattern(tmp_addr);
		dir_sprite = DIR_RIGHT_UP;
		walk_sprite = 1;
	}
	if (j1 & JOY_LEFT && j1 & JOY_DOWN)
	{
		tmp_addr = 0x5000 + decal_frame;
		spr_pattern(tmp_addr);
		dir_sprite = DIR_LEFT_DOWN;
		walk_sprite = 1;
	}
	if (j1 & JOY_RGHT && j1 & JOY_DOWN)
	{
		tmp_addr = 0x5000 + decal_frame;
		spr_pattern(tmp_addr);
		dir_sprite = DIR_RIGHT_DOWN;
		walk_sprite = 1;
	}
	
	if (walk_sprite == 0)
	{
		tics_sprite = 0;
		frame_sprite = 0;
		state_sprite = 0;
	}
	
	else
	{
		if(dir_sprite == DIR_LEFT) sprite_nx-=2;
		if(dir_sprite == DIR_RIGHT) sprite_nx+=2;
		if(dir_sprite == DIR_UP) sprite_ny-=2;
		if(dir_sprite == DIR_DOWN) sprite_ny+=2;
		
		if(dir_sprite == DIR_LEFT_UP) 
		{ 
			sprite_nx-=2;
			sprite_ny-=2;
		}
		if(dir_sprite == DIR_RIGHT_UP)
		{ 
			sprite_nx+=2;
			sprite_ny-=2;
		}
		if(dir_sprite == DIR_LEFT_DOWN)
		{ 
			sprite_nx-=2;
			sprite_ny+=2;
		}
		if(dir_sprite == DIR_RIGHT_DOWN)
		{ 
			sprite_nx+=2;
			sprite_ny+=2;
		}
		
	}
}

player_sprite_2()
{
	state_sprite = 0;
}

/*++TOM++*/
player_sprite_5()
{

	if (j1 & JOY_B)
	{
		state_sprite = 5;
	}
	
}
/*++TOM++*/

physique()
{
	int tile_val, tile_val2; /*++TOM++*/
	/*++TOM++*/
	int already_added_flag;
	/*++TOM++*/
	get_coll_tile(sprite_vx+8, sprite_vy+4, 16, 24, &tile_val); 
	/*++TOM++*/
	get_coll_obj(sprite_vx+8, sprite_vy+4, 16, 24, &tile_val2); 
	/*++TOM++*/
	
	/* si contact par le bas */
	if ((tile_val & 0x0008) == 0x0008)
	{	
		if(sprite_ny < sprite_vy) sprite_ny = sprite_vy;
	} 
	
	/* si contact par la haut */
	if ((tile_val & 0x0004) == 0x0004)
	{	
		if(sprite_ny > sprite_vy) sprite_ny = sprite_vy;
	} 
	/* si contact par la gauche */
	if ((tile_val & 0x0002) == 0x0002)
	{	
		if(sprite_nx < sprite_vx) sprite_nx = sprite_vx;
	} 
	
	/* si contact par la droite */
	if ((tile_val & 0x0001) == 0x0001)
	{	
		if(sprite_nx > sprite_vx) sprite_nx = sprite_vx;
	} 
	/*++TOM++*/
	
	/*put_number(tile_val2,5,0,1);*/
	if (state_sprite == 5){
		for(i = 0;i < MAX_OBJ_LS;i++){
			put_number(reference_stack[i],2,5,i*2);
		}
		/*put_number(last_obj_index,5,10,1);*/
		if (tile_val2 > START_OBJ_TILES_NB){
			if (last_obj_index < MAX_OBJ_LS){
				
				already_added_flag = 0;
				for(i=0;i<MAX_OBJ_LS;i++){
					
					/* put_number(already_added_flag,2,0,10);
				put_number(action_stack[i],2,0,11);
				put_number(tiles_w_obj[tile_val2],2,0,12);
				put_number(tile_val2,2,10,13); */
					if (already_added_flag == 0 && action_stack[i] == tiles_w_obj[tile_val2])
					already_added_flag = 1;
				}
				if (already_added_flag == 0){
					action_stack[last_obj_index] = tiles_w_obj[tile_val2];
					last_obj_index++;
					psgPlay( 1 );
					vsync(60);
				}
				else {
					psgPlay( 2);
				}
				/* else put_string("Already in stack",sprite_nx,sprite_ny); */
			}
			else {
				/*put_string("Max d'actions atteint",10,10);
			put_number(right_place_nb,2,18,15);
			if (right_place_nb < MAX_OBJ_LS){
			//check objects 
				for(i=0;i<MAX_OBJ_LS;i++){		
			if (reference_stack[i] == action_stack[i]) right_place_nb++;
			}
			
			for(i=0;i<MAX_OBJ_LS;i++){	
				for(j=0;j<MAX_OBJ_LS;j++){	
					if (reference_stack[i] == action_stack[j] && i != j) wrong_place_nb++;
							}
			}
			vsync(100);
		day++;
		if (day < MAX_DAYS)
			tirage();
		else lose();
			}
			else {
				win();
			} */
			}
		}
		for(i = 0;i < MAX_OBJ_LS;i++){
			put_number(action_stack[i],2,10,i*2);
		}
		
		
		state_sprite = 0;
	}
	
	if (last_obj_index == MAX_OBJ_LS){
		
		/* check objects */
		for(i=0;i<MAX_OBJ_LS;i++){		
			if (reference_stack[i] == action_stack[i]) right_place_nb++;
		}
		
		for(i=0;i<MAX_OBJ_LS;i++){	
			for(j=0;j<MAX_OBJ_LS;j++){	
				if (reference_stack[i] == action_stack[j] && i != j) wrong_place_nb++;
			}
		}
		
		if (right_place_nb == MAX_OBJ_LS) win();
		else if (day < MAX_DAYS) {
			day++;
			
		
			cls();
			set_color(0,0); /* Je veux le noir */
	set_color(1,511); /* Je veux le blanc */
			karma();
		}
		else {
	
			lose();
		}
		
		
	}
	/*++TOM++*/
	
	sprite_vx = sprite_nx;
	sprite_vy = sprite_ny;
	vmapx = sprite_vx - 112;
	vmapy = sprite_vy - 96;
		
	
	sprite_x = 112;
	sprite_y = 96;
	
load_map(mapx,mapy+11,mapx,mapy+11,17,3);
    spr_put(0,sprite_x,sprite_y, dir_sprite);
    place_map();
	
	/* put_number(tile_val2,2, mapx*2+2, mapy*2+26); */
     put_string(objects[tiles_w_obj[tile_val2]],mapx*2+2, mapy*2+26);

}

/* get_tile en pixels*/
get_pxl_tile(in_x,in_y,res)
int in_x, in_y, *res;
{
	*res = map_get_tile(in_x >> 4, in_y >> 4);
}

/* retourne la valeur la + basse de la tuile en dessous */
get_val_tile(in_x, in_y, w, h, res)
int in_x, in_y, w, h, *res;
{
	int i, tile_nb, dir_tmp;
	/* test du bas */
	dir_tmp = 128;
	for(i = in_x;i<(in_x+w);i+=16)
	{
		get_pxl_tile(i,(in_y+h),&tile_nb);
		if (tile_nb < MUR) dir_tmp = tile_nb;
	}
	*res = dir_tmp;
}

get_coll_tile(in_x, in_y, w, h, res)
int in_x, in_y, w, h, *res;
{
	int i, tile_nb, dir_tmp;
	/* test du haut */
	dir_tmp = 0x0000;


	for(i = in_x;i<(in_x+w);i+=16)
	{
		get_pxl_tile(i,(in_y-1),&tile_nb);
		if (tile_nb < MUR || tile_nb > START_OBJ_TILES_NB) dir_tmp = (dir_tmp | 0x0008); /* mets le bit 4 à 1*/
	}
	get_pxl_tile((in_x+w-1),(in_y-1),&tile_nb); /* le dernier pxl... */
	if (tile_nb < MUR || tile_nb > START_OBJ_TILES_NB) dir_tmp = (dir_tmp | 0x0008);
	
	/* test du bas */
	for(i = in_x;i<(in_x+w);i+=16)
	{
		get_pxl_tile(i,(in_y+h),&tile_nb);
		if (tile_nb < MUR || tile_nb > START_OBJ_TILES_NB) dir_tmp = (dir_tmp | 0x0004); /* mets le bit 3 à 1*/
	}
	get_pxl_tile((in_x+w-1),(in_y+h),&tile_nb);
	if (tile_nb < MUR || tile_nb > START_OBJ_TILES_NB) dir_tmp = (dir_tmp | 0x0004);
	
	/* test a gauche */
	for(i = in_y;i<(in_y+h);i+=16)
	{
		get_pxl_tile((in_x-1), i, &tile_nb);
		if (tile_nb < MUR || tile_nb > START_OBJ_TILES_NB) dir_tmp = (dir_tmp | 0x0002); /* mets le bit 2 à 1*/
	}
	get_pxl_tile((in_x-1), (in_y+h-1), &tile_nb);
	if (tile_nb < MUR || tile_nb > START_OBJ_TILES_NB) dir_tmp = (dir_tmp | 0x0002);
	
	/* test a droite */
	for(i = in_y;i<(in_y+h);i+=16)
	{
		get_pxl_tile((in_x+w), i, &tile_nb);
		if (tile_nb < MUR || tile_nb > START_OBJ_TILES_NB) dir_tmp = (dir_tmp | 0x0001); /* mets le bit 1 à 1*/
	}
	get_pxl_tile((in_x+w), (in_y+h-1), &tile_nb);
	if (tile_nb < MUR || tile_nb > START_OBJ_TILES_NB) dir_tmp = (dir_tmp | 0x0001);
	
	*res = dir_tmp;
}

/*++TOM++*/
get_coll_obj(in_x, in_y, w, h, res)
int in_x, in_y, w, h, *res;
{
	int i, tile_nb, dir_tmp, highest_tile_nb;
	/* test du haut */
	dir_tmp = 0x0000;
	highest_tile_nb = 0;
	for(i = in_x;i<(in_x+w);i+=16)
	{
		get_pxl_tile(i,(in_y-1),&tile_nb);
		if (tile_nb > START_OBJ_TILES_NB) dir_tmp = (dir_tmp | 0x0008); /* mets le bit 4 à 1*/
		if (tile_nb > highest_tile_nb) highest_tile_nb = tile_nb;
	}
	get_pxl_tile((in_x+w-1),(in_y-1),&tile_nb); /* le dernier pxl... */
	if (tile_nb > START_OBJ_TILES_NB) dir_tmp = (dir_tmp | 0x0008);
	if (tile_nb > highest_tile_nb) highest_tile_nb = tile_nb;
	
	
	
	*res = highest_tile_nb;
	/*put_number(highest_tile_nb,3,0,0);*/
}
/*++TOM++*/

place_map()
{
	int gap, t3;
	mapx = vmapx >> 4;
	mapy = vmapy >> 4;

	if (mapx > lastmapx)
	{	
		gap = mapx - lastmapx;
		t3 = (mapx+SCR_W-gap) & 0xFF;
		load_map(t3,mapy,t3,mapy,gap,SCR_H);
	}
	if (mapx < lastmapx)
	{
		gap = lastmapx - mapx;
		load_map(mapx,mapy,mapx,mapy,gap,SCR_H);
	}
	if (mapy > lastmapy)
	{
		gap = mapy - lastmapy;
		t3 = (mapy+SCR_H-gap) & 0xFF;
		load_map(mapx,t3,mapx,t3,SCR_W,gap);
	}
	if (mapy < lastmapy)
	{
		gap = lastmapy - mapy;
		load_map(mapx,mapy,mapx,mapy,SCR_W,gap);
	}
	scroll(0,vmapx,vmapy,0,223,0xC0);


		
	lastmapx = mapx;
	lastmapy = mapy;
}
