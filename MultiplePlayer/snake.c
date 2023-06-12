/* Ruler 1         2         3         4         5         6         7        */
/*         DEVELOPED BY: Bravo Manuela, Chaparro Ma. del Pilar,               */
/*                   Hidalgo Valentina & Vargas Karen                         */
//*****************************************************************************/

/********************************** Headers ***********************************/

/* -------------------- Inclusion of Standard Headers ----------------------- */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

/* ------------------------ Inclusion of Own Headers ------------------------ */
#include "snake.h"
#include "food.h"

/************************ Definition of Public Methods ************************/


/*FN****************************************************************************
*
*   SNAKE_T *SNAKE_New()
*
*   Purpose: This constructor returns a pointer to a new object of the class
*            SNAKE_T or it returns NULL if it fails
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

SNAKE_T   
*SNAKE_New()
{
SNAKE_T *snake_n_ptr = (SNAKE_T *)calloc( 1, sizeof( SNAKE_T ) );
if( snake_n_ptr == (SNAKE_T *)NULL ) {
	fprintf( stderr, "No HEAP space for data\n" );
	exit( 1 );
}	

return snake_n_ptr;

} /* SNAKE_New */



/*FN****************************************************************************
*
*   SNAKE_T *SNAKE_Set( SNAKE_T *snake_ptr, char pos_x, char pos_y,
*                       DIRECTION_T head_symbol,int *length_ptr);
*
*   Return:  Nothing
*
*   Purpose: Set initial values for a snake
*
*   Plan:
*           Part 1: Set initial position of snake in the stage
*           Part 2: Calculate body position in the stage
*           Part 3: Set initial direction of snake head 
*
*   Register of Revisions (Debugging Process):
*
*   DATE       RESPONSIBLE              COMMENT
*   -----------------------------------------------------------------------
* 	Apr 26/20  M.Bravo,V.Hildago,
*			   K.Vargas & P.Chaparro    Initial implementation
*
*******************************************************************************/

SNAKE_T 
*SNAKE_Set(
SNAKE_T *snake_ptr,       /* In/Out: Structure of snake status          */
char pos_x, char pos_y,   /* In:     Position of current snake in stage */
DIRECTION_T head_symbol,  /* In:     Current snake unitary direction    */
int *length_ptr)          /* In:     Current snake size                 */       
{
/* Part 1: Set initial position of snake in the stage */
snake_ptr->body_snake[0].ubication[0] = pos_x;
snake_ptr->body_snake[0].ubication[1] = pos_y;

/* Part 2: Calculate body position in the stage */
for(int i=1; i<(*length_ptr);i++){
	snake_ptr->body_snake[i].ubication[0]=snake_ptr->body_snake[i-1].ubication[0]-1;
	snake_ptr->body_snake[i].ubication[1]=snake_ptr->body_snake[i-1].ubication[1];
}

/* Part 3: Set initial direction of snake head */
if( head_symbol == UP )
    snake_ptr->direction[0] = -1, snake_ptr->direction[1] =  0;
else if( head_symbol == DOWN )
    snake_ptr->direction[0] =  1, snake_ptr->direction[1] =  0;
else if( head_symbol == RIGHT )
    snake_ptr->direction[0] =  0, snake_ptr->direction[1] =  1;
else if( head_symbol == LEFT )
    snake_ptr->direction[0] =  0, snake_ptr->direction[1] = -1;

return snake_ptr;

} /* SNAKE Set */



/*FN****************************************************************************
*
*   char SNAKE_Get_x(SNAKE_T *snake_ptr); 
*
*   Return:  Snake coordinate x in stage
*
*   Purpose: Get the coordinate x value for the snake structure 
*
*   Plan: Nothing
*
*   Register of Revisions (Debugging Process):
*
*   DATE       RESPONSIBLE              COMMENT
*   -----------------------------------------------------------------------
* 	May 24/20  M.Bravo,V.Hildago,
*			   K.Vargas & P.Chaparro    Initial implementation
*
*******************************************************************************/
char  
SNAKE_Get_x(
SNAKE_T *snake_ptr)       /* In:  Structure of current snake status  */
{
 return snake_ptr->body_snake[0].ubication[0]; 
}


/*FN****************************************************************************
*
*   char SNAKE_Get_y(SNAKE_T *snake_ptr); 
*
*   Return:  Snake coordinate y in stage
*
*   Purpose: Get the coordinate y value for the snake structure 
*
*   Plan: Nothing
*
*   Register of Revisions (Debugging Process):
*
*   DATE       RESPONSIBLE              COMMENT
*   -----------------------------------------------------------------------
* 	May 24/20  M.Bravo,V.Hildago,
*			   K.Vargas & P.Chaparro    Initial implementation
*
*******************************************************************************/
char 
SNAKE_Get_y(
SNAKE_T *snake_ptr)      /* In:  Structure of current snake status  */
{
 return snake_ptr->body_snake[0].ubication[1]; 
}



/*FN****************************************************************************
*
*   SNAKE_Update(SNAKE_T *snake_ptr,int *length_ptr,DIRECTION_T head_symbol,  
*                char console_buf[][CON_COLS],int id_snake);
*
*   Return: Nothing
*
*   Purpose: Update the snake structure in the stage
*
*   Plan: 
*        Part 1: Determine alphabetic char according to snake head direction
*        Part 2: Update snake body position in the stage
*
*   Register of Revisions (Debugging Process):
*
*   DATE       RESPONSIBLE              COMMENT
*   -----------------------------------------------------------------------
*   Sep 01/15  J.C.Giraldo  			Initial implementation
* 	May 24/20  M.Bravo,V.Hildago,
*			   K.Vargas & P.Chaparro    Second implementation
*
*******************************************************************************/
int 
SNAKE_Update(
SNAKE_T *snake_ptr,            /* In/Out: Structure of snake status       */
int *length_ptr,               /* In:     Current snake size              */
DIRECTION_T head_symbol,       /* In:     Current snake unitary direction */
char console_buf[][CON_COLS],  /* In/Out: Buffer of console               */
int id_snake)                  /* In:     Current snake identifier        */
{
	
/* Part 1: Determine alphabetic char according to snake head direction */
if( snake_ptr->direction[0]== 0 && snake_ptr->direction[1]==-1 )
    head_symbol = '<';
else if( snake_ptr->direction[0]== 0 && snake_ptr->direction[1]== 1 )
    head_symbol = '>';
else if( snake_ptr->direction[0]== 1 && snake_ptr->direction[1]== 0 )
    head_symbol = 'V';
else
    head_symbol = 'A';

/* Part 2: Update snake body position in the stage */
console_buf[snake_ptr->body_snake[0].ubication[0]][snake_ptr->body_snake[0].ubication[1]*2] = head_symbol;
for(int i=1; i<(*length_ptr); i++){
	if(id_snake==1)
		console_buf[snake_ptr->body_snake[i].ubication[0]][snake_ptr->body_snake[i].ubication[1]*2]=111;
	else
		console_buf[snake_ptr->body_snake[i].ubication[0]][snake_ptr->body_snake[i].ubication[1]*2]=158;	
}
return 1;
}




/*FN****************************************************************************
*
*   int SNAKE_Forward(SNAKE_T *c_snake_ptr,SNAKE_T *other_snake_ptr, 
*                     int *c_score_ptr,int *other_score_ptr,    
*                     char console_buf[][CON_COLS],char stage[][STAGE_COLS], 
*                     char stage_1[][STAGE_COLS],int *level_game_ptr,            
*                     int *c_length_ptr,int *other_length_ptr,
*                     FOOD_T *food_ptr,int id_snake);
*
*   Return:  Nothing
*
*   Purpose: Command in order to advance one step forward in stage
*
*   Plan:
*			Part 1: Snake body moves following the snake head
*           Part 2: Determine position in front of snake head
*           Part 3: Choose the matrix that describes the current stage level and
*                   refresh stage with new view
*           Part 4: Check if next position of current snake is the same as
*        		    snake body or other snake body   
*           Part 5: Check if next position of snake is the same as stage
*                   walls
*           Part 6: Restart o finished the game since a collision occurred 
*           Part 7: Update new snake head position if there is not wall in front
*
*   Register of Revisions (Debugging Process):
*
*   DATE       RESPONSIBLE              COMMENT
*   -----------------------------------------------------------------------
*   Sep 01/15  J.C.Giraldo  			Initial implementation
* 	Apr 26/20  M.Bravo,V.Hildago,
*			   K.Vargas & P.Chaparro    Second implementation
*   May 24/20  M.Bravo,V.Hildago,
*			   K.Vargas & P.Chaparro    Third implementation
*
*******************************************************************************/

int
SNAKE_Forward(
SNAKE_T *c_snake_ptr,          /* In/Out: Structure of current snake status */
SNAKE_T *other_snake_ptr,      /* In:     Structure of other snake status   */     
int *c_score_ptr,              /* In:     Current snake score               */
int *other_score_ptr,          /* In:     Other snake score                 */
char console_buf[][CON_COLS],  /* In/Out: Buffer of console                 */
char stage[][STAGE_COLS],      /* In:     Map of stage level 0              */
char stage_1[][STAGE_COLS],    /* In:     Map of stage level 1              */
int *level_game_ptr,           /* In:     Identifier of level               */
int *c_length_ptr,             /* In:     Current snake size                */
int *other_length_ptr,         /* In:     Other snake size                  */
FOOD_T *food_ptr,              /* In:     Structure of food status          */
int id_snake)                  /* In:     Current snake identifier          */
{
char next_x, next_y;
char current_stage[STAGE_ROWS][STAGE_COLS];
int enter;
char tecla_temp;
double previous;
int no_back=1;
int crash_snake=0; 

/* Part 1: Snake body moves following the snake head */
for(int i=(*c_length_ptr); i>0; i--){
	c_snake_ptr->body_snake[i].ubication[0]=c_snake_ptr->body_snake[i-1].ubication[0];
	c_snake_ptr->body_snake[i].ubication[1]=c_snake_ptr->body_snake[i-1].ubication[1];
}

/* Part 2: Determine position in front of snake head */
next_x = c_snake_ptr->body_snake[0].ubication[0] + c_snake_ptr->direction[0];
next_y = c_snake_ptr->body_snake[0].ubication[1] + c_snake_ptr->direction[1];

/* Part 3: Choose the matrix that describes the current stage level and
           refresh stage with new view  */
if(*level_game_ptr==1){
	for(int i=0; i<STAGE_ROWS; i++){
		for(int j=0; j<STAGE_COLS; j++){
			current_stage[i][j]=stage[i][j];
		}
	}
}
else if(*level_game_ptr==2){
	for(int i=0; i<STAGE_ROWS; i++){
		for(int j=0; j<STAGE_COLS; j++){
			current_stage[i][j]=stage_1[i][j];
		}
	}
}
Initiate_Stage_in_Text_Mode( console_buf, current_stage );

/* Part 4: Check if next position of current snake is the same as
		   snake body or other snake body  */ 
for(int i=1; i<(*c_length_ptr); i++)
{
	if((next_x==c_snake_ptr->body_snake[i].ubication[0]) &&
	(next_y==c_snake_ptr->body_snake[i].ubication[1]))
		crash_snake=1;
	
	else if((next_x==other_snake_ptr->body_snake[i].ubication[0]) && 
		   (next_y==other_snake_ptr->body_snake[i].ubication[1]))
			crash_snake=1;
	else
		crash_snake=0;
}

/* Part 5: Check if next position of snake is the same as stage
           walls  */ 
if((current_stage[next_x][next_y] == 1) ||(current_stage[next_x][next_y] == 2) 
				||(current_stage[next_x][next_y] == 3))
				crash_snake=1;

/* Part 6: Restart o finished the game since a collision occurred      */			
if(crash_snake==1){
	printf(" ++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf(" + |||||||||||||||||||||||||||||||||||||||||| +\n");
	printf(" +          X-X    GAME OVER   X-X            +\n");
	printf(" + |||||||||||||||||||||||||||||||||||||||||| +\n");
	printf(" ++++++++++++++++++++++++++++++++++++++++++++++\n");

	previous= clock() * 1.0 / CLOCKS_PER_SEC;
	while( clock() * 1.0 / CLOCKS_PER_SEC - previous < 1 );

	enter=1;
	while(enter){
		system("cls");
		printf(" ++++++++++++++++++++++++++++++++++++++++++++++\n");
		printf(" +          Quieren volver a jugar?            +\n");
		printf(" +                                             +\n");
		printf(" +      Presione 'ENTER' para REINICIAR        +\n");
		printf(" +      Presione 'ESC'   para SALIR            +\n");
		printf(" +                                             +\n");
		printf(" +++++++++++++++++++++++++++++++++++++++++++++++\n");
		
		tecla_temp=getch();
			
		if(tecla_temp==13){
			*c_score_ptr=0;
			*other_score_ptr=0;
			*c_length_ptr=2;
			*other_length_ptr=2;
			*level_game_ptr=1;
			if(id_snake==1){
				*SNAKE_Set(c_snake_ptr,4, 4, DOWN, c_length_ptr);
				*SNAKE_Set(other_snake_ptr,16, 16, UP, 
						   other_length_ptr);
			}
			else{
				*SNAKE_Set(c_snake_ptr, 16, 16, UP, c_length_ptr);
				*SNAKE_Set(other_snake_ptr, 4 , 4, DOWN, 
						   other_length_ptr);
			}
			no_back=2;
			enter=0;
		}
		else if(tecla_temp==27){
			system("cls");
			printf(" ++++++++++++++++++++++++++++++++++++++++++++++\n");
			printf(" +                                            +\n");
			printf(" +                                            +\n");
			printf(" +              SALIO DEL JUEGO               +\n");
			printf(" +         |^-^| Vuelva pronto |^-^|          +\n");
			printf(" +                                            +\n");
			printf(" +                                            +\n");
			printf(" ++++++++++++++++++++++++++++++++++++++++++++++\n");
			FOOD_Free(food_ptr);
			SNAKE_Free(c_snake_ptr);
			SNAKE_Free(other_snake_ptr);
			exit(1);
		}
		
	}
}


/* Part 7: Update new snake head position if there is not wall in front  */
else{
    c_snake_ptr->body_snake[0].ubication[0] +=  c_snake_ptr->direction[0];
    c_snake_ptr->body_snake[0].ubication[1] +=  c_snake_ptr->direction[1];
}

return no_back;
}



/*FN****************************************************************************
*
*   int SNAKE_Free( SNAKE_T *snake_n_ptr );
*
*   Return:  Nothing
*
*   Purpose: Free dynamic memory used for a snake
*
*   Plan:    Simple function that does not need a plan description
*
*   Register of Revisions (Debugging Process):
*
*   DATE         RESPONSIBLE             COMMENT
*   -----------------------------------------------------------------------
*   May 24/20  M.Bravo,V.Hildago,
*			   K.Vargas & P.Chaparro     Initial implementation
*
*******************************************************************************/

int 
SNAKE_Free( 
SNAKE_T *snake_n_ptr )          /* In: Structure of food status      */ 
{
free( snake_n_ptr );
return 1;

} /*SNAKE_Free */

