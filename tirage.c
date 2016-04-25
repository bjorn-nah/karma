#include "val_glob.h"
#include "karma.c"



tirage()
{
	/* int j; */
	cls();
	init_satb();
	reset_satb();
	srand(last_obj_index + right_place_nb + wrong_place_nb + day);
	for(j = 0;j<MAX_OBJ_LS;j++)
	{
        r = rdm_objects(OBJECTS_NB);
        reference_stack[j] = r;
    }
	karma();
}

rdm_objects(SPAN)
int SPAN;
{
	/* int i; */
    r = random(SPAN);
r++;
    for(i=0;i<MAX_OBJ_LS;i++){
        if (r == reference_stack[i]) rdm_objects(SPAN);
    }
    return r;
}