#define OBJECTS_NB 8
#define TILES_WITH_OBJECTS 23
#define MAX_OBJ_LS 4
#define START_OBJ_TILES_NB 87
#define MUR 53
#define MAX_DAYS 7



int r, i, j, last_obj_index, right_place_nb, wrong_place_nb, day;

int  reference_stack[MAX_OBJ_LS], action_stack[MAX_OBJ_LS];
int objects[OBJECTS_NB], tiles_w_obj[TILES_WITH_OBJECTS];

int prev_right, prev_wrong; /* last minute */
