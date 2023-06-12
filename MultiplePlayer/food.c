/* Ruler 1         2         3         4         5         6         7        */
/*         DEVELOPED BY: Bravo Manuela, Chaparro Ma. del Pilar,               */
/*                   Hidalgo Valentina & Vargas Karen                         */
//*****************************************************************************/

/********************************** Headers ***********************************/

/* -------------------- Inclusion of Standard Headers ----------------------- */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/* ------------------------ Inclusion of Own Headers ------------------------ */
#include "food.h"


/************************ Definition of Public Methods ************************/


/*FN****************************************************************************
*
*   FOOD_T *FOOD_New();
*
*   Purpose: This constructor returns a pointer to a new object of the class
*            FOOD_T or it returns NULL if it fails
*
*   Plan:    Simple function that does not need a plan description
*
*   Register of Revisions:
*
*   DATE         RESPONSIBLE              COMMENT
*   -----------------------------------------------------------------------
*   May 19/20  M.Bravo,V.Hildago,
*			   K.Vargas & P.Chaparro     Initial implementation
*
*******************************************************************************/

FOOD_T   
*FOOD_New()
{
FOOD_T *food_n_ptr = (FOOD_T *)calloc( 1, sizeof( FOOD_T ) );
if( food_n_ptr == (FOOD_T *)NULL ) {
	fprintf( stderr, "No HEAP space for data\n" );
	exit( 1 );
}

return food_n_ptr;

} /* FOOD_New */



/*FN****************************************************************************
*
*   FOOD_T  *FOOD_Set(FOOD_T *food_n_ptr,double *ti_food_n_ptr,
*                     SNAKE_T *snake_1_ptr,SNAKE_T *snake_2_ptr, 
*                    char stage[][STAGE_COLS],char stage_1[][STAGE_COLS] );
*
*   Return:  Pointer to food structure
*
*   Purpose: Set initial values for the food 
*
*   Plan:    
*    		Part 1: Random food generator in stage 
*           Part 2: Check food position inside the stage, not matching with 
*					snakes positions or with stage walls
*			Part 3: Take initial time for food appearance in stage 
*
*   Register of Revisions:
*
*   DATE         RESPONSIBLE             COMMENT
*   -----------------------------------------------------------------------
*	May 19/20  M.Bravo,V.Hildago,
*			   K.Vargas & P.Chaparro     Second implementation
*
*   Apr 26/20  M.Bravo,V.Hildago,
*			   K.Vargas & P.Chaparro     Initial implementation
*
*******************************************************************************/

FOOD_T 
*FOOD_Set(
FOOD_T *food_n_ptr,         /* In/Out: Structure of food status      */
double *ti_food_n_ptr,      /* Out:    Pointer to initial time food  */
SNAKE_T *snake_1_ptr,       /* In:     Snake 1 position              */
SNAKE_T *snake_2_ptr,       /* In:     Snake 2 position              */
char stage[][STAGE_COLS],   /* In:     Map of stage level 0          */ 
char stage_1[][STAGE_COLS]) /* In:     Map of stage level 1          */ 
{
/* Part 1: Random food generator in stage */
srand(time(0));	
food_n_ptr->ubication[0] = 1+rand()% (STAGE_ROWS-2);
food_n_ptr->ubication[1] = 2+rand()% (STAGE_COLS-3);

/* Part 2: Check food position inside the stage, not matching with 
		   snakes positions or with stage walls */
while(
	  ((snake_1_ptr->body_snake[0].ubication[0]==food_n_ptr->ubication[0]) && 
	  (snake_1_ptr->body_snake[0].ubication[1]==food_n_ptr->ubication[1])) ||
      ((snake_2_ptr->body_snake[0].ubication[0]==food_n_ptr->ubication[0]) && 
	  (snake_2_ptr->body_snake[0].ubication[1]==food_n_ptr->ubication[1])) ||	  
	  (food_n_ptr->ubication[1]==STAGE_COLS-1) || (food_n_ptr->ubication[1]==0) ||
	  (food_n_ptr->ubication[1]==STAGE_COLS-2) || (food_n_ptr->ubication[1]==1) ||  
	  (food_n_ptr->ubication[0]==STAGE_ROWS-2) || (food_n_ptr->ubication[0]==1) ||
	  (food_n_ptr->ubication[0]==STAGE_ROWS-1) || (food_n_ptr->ubication[0]==0) ||
	  (stage[food_n_ptr->ubication[0]][food_n_ptr->ubication[1]] != 0) || 
	  (stage_1[food_n_ptr->ubication[0]][food_n_ptr->ubication[1]] != 0)){
	srand(time(0));	
	food_n_ptr->ubication[0] = 1+rand()% (STAGE_ROWS-2);
	food_n_ptr->ubication[1] = 2+rand()% (STAGE_COLS-3);
}
/* Part 3: Take initial time for food appearance in stage */
*ti_food_n_ptr= (double)clock();

return food_n_ptr;

} /* FOOD_Set */



/*FN****************************************************************************
*
*   int  FOOD_Get_Time(FOOD_T *food_n_ptr, double *ti_food_n_ptr,    
*                      SNAKE_T *snake_1_ptr, SNAKE_T *snake_2_ptr,
*                       char stage[][STAGE_COLS],   
*                      char stage_1[][STAGE_COLS]);
*
*   Purpose: Check if food time in the stage is completed
*
*   Plan:    Simple function that does not need a plan description
*
*   Register of Revisions:
*
*   DATE         RESPONSIBLE             COMMENT
*   -----------------------------------------------------------------------
*  May 19/20  M.Bravo,V.Hildago,
*			   K.Vargas & P.Chaparro     Second implementation
*
*  Apr 26/20  M.Bravo,V.Hildago,
*			   K.Vargas & P.Chaparro     Initial implementation
*
*******************************************************************************/

int 
FOOD_Get_Time(
FOOD_T *food_n_ptr,           /* In: Structure of food status      */
double *ti_food_n_ptr,        /* In: Pointer to initial time food  */
SNAKE_T *snake_1_ptr,         /* In: Snake 1 position              */
SNAKE_T *snake_2_ptr,         /* In: Snake 2 position              */
char stage[][STAGE_COLS],     /* In: Map of stage level 0          */ 
char stage_1[][STAGE_COLS])   /* In: Map of stage level 1          */
{
double Tf_food=(double)clock();
double time_food=15;  
if(((Tf_food - *ti_food_n_ptr) / CLOCKS_PER_SEC) >= time_food){
	*FOOD_Set(food_n_ptr, ti_food_n_ptr,snake_1_ptr, 
	          snake_2_ptr,stage, stage_1);
} 
return 1;

} /* FOOD_Get_Time */


/*FN****************************************************************************
*
*   int FOOD_Free( FOOD_T *food_n_ptr );
*
*   Return:  Nothing
*
*   Purpose: Free dynamic memory used for food
*
*   Plan:    Simple function that does not need a plan description
*
*   Register of Revisions (Debugging Process):
*
*   DATE         RESPONSIBLE             COMMENT
*   -----------------------------------------------------------------------
*  May 19/20  M.Bravo,V.Hildago,
*			   K.Vargas & P.Chaparro     Initial implementation
*
*******************************************************************************/

int FOOD_Free( 
FOOD_T *food_n_ptr )          /* In: Structure of food status      */ 
{
free( food_n_ptr );

return 1;

} /* FOOD_Free */

