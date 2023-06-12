/* Ruler 1         2         3         4         5         6         7        */

/* snados.c *******************************************************************/
/*                                                                            */
/*   ┌────┐ ┌────┐                            SNADOS                          */
/*   └┐  ┌┘ └┐╔══╧═╗                                                          */
/*    │  │   │╚╗  ╔╝      This code was designed in order to teach skills     */
/*    │  │   │ ║  ║       to conceive, design and implement algorithms by     */
/*    │  │   │ ║  ║       using Finite State Machines (FSM) and Encapsulation */
/*    │╔═╧══╗│ ║  ║                                                           */
/*    │╚╗  ╔╝┘ ║  ║                                                           */
/*    └┐║  ╚╗ ╔╝  ║       DEVELOPED BY: Bravo Manuela, Chaparro Ma. del Pilar,*/
/*     └╚╗  ╚═╝  ╔╝                     Hidalgo Valentina & Vargas Karen      */
/*      └╚╗     ╔╝                                                            */
/*        ╚═════╝         Bogota, D.C., April  22th, 2020.                    */
/*                                                                            */
/*          Copyright (C) Departament de Electronics                          */
/*                        School of Engineering                               */
/*                        Pontificia Universidad Javeriana                    */
/*                        Bogota - Colombia - South America                   */
/*                                                                            */
/******************************************************************************/


/* --------------------- Inclusion of Standard Headers ---------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/* ------------------------- Inclusion of Own Headers ------------------------ */
#include "food.h"

/*Declaration of level 1*/
static char stage_A[STAGE_ROWS][STAGE_COLS] = {
/*        00 01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16 17 18 19 20 */
/* 00 */ { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
/* 01 */ { 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0 },
/* 02 */ { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
/* 03 */ { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
/* 04 */ { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
/* 05 */ { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
/* 06 */ { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
/* 07 */ { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
/* 08 */ { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
/* 09 */ { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
/* 10 */ { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
/* 11 */ { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
/* 12 */ { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
/* 13 */ { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
/* 14 */ { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
/* 15 */ { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
/* 16 */ { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
/* 17 */ { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
/* 18 */ { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
/* 19 */ { 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0 },
/* 20 */ { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

/*Declaration of level 2*/
static char stage_B[STAGE_ROWS][STAGE_COLS] = {
/*        00 01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16 17 18 19 20 */
/* 00 */ { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
/* 01 */ { 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0 },
/* 02 */ { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
/* 03 */ { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
/* 04 */ { 0, 1, 0, 0, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
/* 05 */ { 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
/* 06 */ { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
/* 07 */ { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
/* 08 */ { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
/* 09 */ { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
/* 10 */ { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
/* 11 */ { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
/* 12 */ { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
/* 13 */ { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0 },
/* 14 */ { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 0, 0, 1, 0 },
/* 15 */ { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
/* 16 */ { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
/* 17 */ { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
/* 18 */ { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
/* 19 */ { 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0 },
/* 20 */ { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

/*Declaration of variable to save score*/
int score_snake=0;

/*Declaration of snake size variable*/
int LENGTH=3;

/*Declaration of level game variable*/
int Level_game= 1;

/*Declaration of time food initialization variable*/
double Ti_food;

/* Delay between movements */
double delay = 0.05; 

/* Buffer to display the map of stage in stdout through ASCII chars */
static char console_buf[CON_ROWS][CON_COLS];

/* Declaration of enumeration type for normalized unitary vector */
typedef enum { LEFT, RIGHT, DOWN, UP } DIRECTION_T;

/* Declaration of the snake's structure */
SNAKE_T current_snake;

/* Functions */
int Initiate_Stage_in_Text_Mode( char console_buf[][CON_COLS],
                                 char stage[][STAGE_COLS]);

int Refresh_Stage_in_Text_Mode( SNAKE_T *c_snake_ptr, FOOD_T *food_ptr,
								double  *ti_food_ptr, int *score_ptr,
								char console_buf[][CON_COLS],
								int *length_ptr,int *level_game_ptr);
								
int Initiate_Snake(SNAKE_T *c_snake_ptr,char pos_x, char pos_y,
                   DIRECTION_T head_symbol,int *length_ptr);
				
int Forward(SNAKE_T *c_snake_ptr, FOOD_T *food_ptr,double  *ti_food_ptr, 
            int *score_ptr,char console_buf[][CON_COLS],
			char stage[][STAGE_COLS],char stage_1[][STAGE_COLS],
			int *level_game_ptr,int *length_ptr);
			
int Game(SNAKE_T *c_snake_ptr,char pos_x,char pos_y,DIRECTION_T head_symbol,
         int *length_ptr,int *score_ptr,FOOD_T *food_ptr,
         double  *ti_food_ptr,char console_buf[][CON_COLS],
		 char stage[][STAGE_COLS],char stage_1[][STAGE_COLS],
		 int *level_game_ptr);
		 
int Intro_Game();

/*FN****************************************************************************
*
*   int Initiate_Stage_in_Text_Mode( char console_buf[][CON_COLS],
*                                    char stage[][STAGE_COLS] );
*
*   Return:  Nothing
*
*   Purpose: Command to initiate buffer of stage in text mode from its map
*
*   Plan
*           Part 1: Fill the console buffer with a white space
*           Part 2: Fill the console buffer with stage in text mode
*
*   Register of Revisions (Debugging Process):
*
*   DATE       RESPONSIBLE  			COMMENT
*   -----------------------------------------------------------------------
*   Sep 01/15  J.C.Giraldo  			Initial implementation
* 	Apr 10/20  M.Bravo,V.Hildago,
*			   K.Vargas & P.Chaparro     Second implementation
*
*******************************************************************************/

int
Initiate_Stage_in_Text_Mode(
char console_buf[][CON_COLS],  /* Out: Buffer of console */
char stage[][STAGE_COLS] )     /* In:  Map of stage      */
{
	char i, j;
	char *temp=&console_buf[i][j];
	
	/* Part 1: Fill console buffer with a white space */
	for( i=0; i<CON_ROWS; i++ )
		for( j=0; j<CON_COLS; j++ )
			console_buf[i][j] = ' ';

	/* Part 2: Fill console buffer with stage in text mode */
	for( i=0; i<STAGE_ROWS; i++ ) {
		for( j=0; j<STAGE_COLS; j++ ){
			if(stage[i][j] != 0){
				if(stage[i][j]==1){         //Identifier "1" for LATERAL WALLS
					console_buf[i][2*j]=185;
					console_buf[i][(2*j)+1]=185;
				}
				else if(stage[i][j]==2){    //Identifier "2" for ABOVE WALLS
					console_buf[i][2*j]=220;
					console_buf[i][(2*j)+1]=220;
				}
				else if(stage[i][j]==3){    //Identifier "3" for BOTTOM WALLS
					console_buf[i][2*j]=223;
					console_buf[i][(2*j)+1]=223;
				}
				
			}
			else 
				console_buf[i][2*j] = ' ';
			
		}
		console_buf[i][CON_COLS-1] = '\n';
	}
	
return 1;

} /* Initiate_Stage_in_Text_Mode */


/*FN****************************************************************************
*
*   int Refresh_Stage_in_Text_Mode(SNAKE_T *c_snake_ptr,FOOD_T *food_ptr,   
*                                   double *ti_food_ptr,int *score_ptr,                
*									char console_buf[][CON_COLS],int *length_ptr
*                                   int *level_game_ptr);
*
*   Return:  Nothing
*
*   Purpose: Command to send stage saved in buffer to standard out
*
*   Plan:
*           Part 1: Copy the stage in a temporal buffer
*			Part 2: Take current position of snake
*           Part 3: Determine alphabetic char according to snake direction
*           Part 4: Update snake body position in the stage
*           Part 5: Take current position of food
*           Part 6: Determine alphabetic char for food, when head takes 
*					the same position as the food score is pre-incremented
*					snake length is incremented
*           Part 7: Update food position in the stage
*           Part 8: Clear, print and pause console every 2 seconds
*  
*
*   Register of Revisions (Debugging Process):
*
*   DATE       RESPONSIBLE              COMMENT
*   -----------------------------------------------------------------------
*   Sep 01/15  J.C.Giraldo  			Initial implementation
* 	Apr 26/20  M.Bravo,V.Hildago,
*			   K.Vargas & P.Chaparro    Second implementation
*
*******************************************************************************/
int
Refresh_Stage_in_Text_Mode(
SNAKE_T *c_snake_ptr,          /* In:     Structure of snake status       */
FOOD_T *food_ptr,              /* In/Out: Structure of food status        */
double *ti_food_ptr,           /* In:     Pointer to initial time food    */
int *score_ptr,                /* Out:    Pointer to score                */
char console_buf[][CON_COLS],  /* Out:    Buffer of console               */
int *length_ptr,               /* In/Out: Snake size                      */
int *level_game_ptr)           /* Out:    Pointer to the stage level      */
{
char console_buf_tmp[CON_ROWS][CON_COLS];
char i, j;
char pos_x1, pos_y1;
char pos_x2, pos_y2;
char head_symbol;
char food_symbol;

/* Part 1: Copy the stage in a temporal buffer */
for( i=0; i<CON_ROWS; i++ )
    for( j=0; j<CON_COLS; j++ )
        console_buf_tmp[i][j] = console_buf[i][j];
	
/* Part 2: Take current position of snake head */
pos_x1 = c_snake_ptr->body_snake[0].ubication[0];
pos_y1 = c_snake_ptr->body_snake[0].ubication[1];

/* Part 3: Determine alphabetic char according to snake head direction */
if(      c_snake_ptr->direction[0]== 0 && c_snake_ptr->direction[1]==-1 )
    head_symbol = '<';
else if( c_snake_ptr->direction[0]== 0 && c_snake_ptr->direction[1]== 1 )
    head_symbol = '>';
else if( c_snake_ptr->direction[0]== 1 && c_snake_ptr->direction[1]== 0 )
    head_symbol = 'V';
else
    head_symbol = 'A';

/* Part 4: Update snake body position in the stage */
console_buf_tmp[c_snake_ptr->body_snake[0].ubication[0]][c_snake_ptr->body_snake[0].ubication[1]*2] = head_symbol;
for(int i=1; i<(*length_ptr); i++){
	console_buf_tmp[c_snake_ptr->body_snake[i].ubication[0]][c_snake_ptr->body_snake[i].ubication[1]*2]=111;
}

/* Part 5: Take current position of food */
pos_x2 = food_ptr->ubication[0];
pos_y2 = food_ptr->ubication[1];

/* Part 6: Determine alphabetic char for food, when head takes 
			the same position as the food score is pre-incremented
			snake length is incremented*/
if( pos_x1== pos_x2 && pos_y1==pos_y2 ){
    food_symbol = head_symbol;
	++*score_ptr;
	
	if(*score_ptr < 3){
		*level_game_ptr=1;
	}
	else if(*score_ptr < 5){
		*level_game_ptr=2;
	}
	
	++*length_ptr;
	*FOOD_Set(food_ptr, ti_food_ptr, c_snake_ptr,stage_A, stage_B);
}
else
	food_symbol=184;

/* Part 7: Update food position in the stage */
console_buf_tmp[pos_x2][pos_y2*2] = food_symbol;

/* Part 8: Clear, print and pause console every 2 seconds */
#ifdef LINUX
system( "clear");
#else
system( "cls");
#endif

for( i=0; i<CON_ROWS; i++ )
    for( j=0; j<CON_COLS; j++ )
        printf("%c", console_buf_tmp[i][j] );
	
printf("              SCORE:%d         LEVEL:%d  \n\n", *score_ptr, *level_game_ptr);	

double previous = clock() * 1.0 / CLOCKS_PER_SEC;
while( clock() * 1.0 / CLOCKS_PER_SEC - previous < delay );

printf("\n");

return 1;

} /* Refresh_Stage_in_Text_Mode */


/*FN****************************************************************************
*
*   int Initiate_Snake( SNAKE_T *c_snake_ptr, char pos_x, char pos_y,
*                       DIRECTION_T head_symbol,int *length_ptr);
*
*   Return:  Nothing
*
*   Purpose: Set initial values for a snake
*
*   Plan:
*           Part 1: Set initial ubication of snake in the maze
*           Part 2: Calculate body position in the stage
*           Part 3: Set initial direction of snake head 
*
*   Register of Revisions (Debugging Process):
*
*   DATE       RESPONSIBLE              COMMENT
*   -----------------------------------------------------------------------
*   Sep 01/15  J.C.Giraldo  			Initial implementation
* 	Apr 26/20  M.Bravo,V.Hildago,
*			   K.Vargas & P.Chaparro    Second implementation
*
*******************************************************************************/

int
Initiate_Snake(
SNAKE_T *c_snake_ptr,          /* In/Out: Structure of snake status      */
char pos_x, char pos_y,        /* In:     Position of snake in stage     */
DIRECTION_T head_symbol,       /* In:     Snake unitary direction        */
int *length_ptr)               /* In:     Snake size                     */       
{
/* Part 1: Set initial ubication of snake in the stage */
c_snake_ptr->body_snake[0].ubication[0] = pos_x;
c_snake_ptr->body_snake[0].ubication[1] = pos_y;

/* Part 2: Calculate body position in the stage */
for(int i=1; i<(*length_ptr);i++){
	c_snake_ptr->body_snake[i].ubication[0]=c_snake_ptr->body_snake[i-1].ubication[0]-1;
	c_snake_ptr->body_snake[i].ubication[1]=c_snake_ptr->body_snake[i-1].ubication[1];
}

/* Part 3: Set initial direction of snake head */
if( head_symbol == UP )
    c_snake_ptr->direction[0] = -1, c_snake_ptr->direction[1] =  0;
else if( head_symbol == DOWN )
    c_snake_ptr->direction[0] =  1, c_snake_ptr->direction[1] =  0;
else if( head_symbol == RIGHT )
    c_snake_ptr->direction[0] =  0, c_snake_ptr->direction[1] =  1;
else if( head_symbol == LEFT )
    c_snake_ptr->direction[0] =  0, c_snake_ptr->direction[1] = -1;
return 1;

} /* Initiate_Snake */



/*FN****************************************************************************
*
*   int Forward(SNAKE_T *c_snake_ptr,FOOD_T *food_ptr,double *ti_food_ptr,          
*				int *score_ptr,char console_buf[][CON_COLS],
*				char stage[][STAGE_COLS],char stage_1[][STAGE_COLS],
*               int *level_game_ptr, int *length_ptr);
*
*   Return:  Nothing
*
*   Purpose: Command in order to advance one step forward in stage
*
*   Plan:
*			Part 1: Snake body moves following the snake head
*           Part 2: Determine position in front of snake head
*           Part 3: Check if next position of snake is the same as
*          	        snake body
*           Part 4: Choose the matrix that describes the current stage level
*           Part 5: Check if next position of snake is the same as stage
*                   walls and update new snake head position if there is
*                   not wall in front
*           Part 6: Refresh stage with new view
*
*   Register of Revisions (Debugging Process):
*
*   DATE       RESPONSIBLE              COMMENT
*   -----------------------------------------------------------------------
*   Sep 01/15  J.C.Giraldo  			Initial implementation
* 	Apr 26/20  M.Bravo,V.Hildago,
*			   K.Vargas & P.Chaparro    Second implementation
*
*******************************************************************************/

int
Forward(
SNAKE_T *c_snake_ptr,          /* In/Out: Structure of snake status     */
FOOD_T *food_ptr,              /* In:     Structure of food status      */
double *ti_food_ptr,           /* In:     Pointer to initial time food  */
int *score_ptr,                /* In:     Pointer to score              */
char console_buf[][CON_COLS],  /* Out:    Buffer of console             */
char stage[][STAGE_COLS],      /* In:     Map of stage level 0          */
char stage_1[][STAGE_COLS],    /* In:     Map of stage level 1          */
int *level_game_ptr,           /* Out:    Pointer to the stage level    */ 
int *length_ptr)               /* In:     Snake size                    */          
{
char next_x, next_y;
char current_stage[STAGE_ROWS][STAGE_COLS];
int enter;
char tecla_temp;
double previous;

/* Part 1: Snake body moves following the snake head */
for(int i=(*length_ptr); i>0; i--){
	c_snake_ptr->body_snake[i].ubication[0]=c_snake_ptr->body_snake[i-1].ubication[0];
	c_snake_ptr->body_snake[i].ubication[1]=c_snake_ptr->body_snake[i-1].ubication[1];
}

/* Part 2: Determine position in front of snake head */
next_x = c_snake_ptr->body_snake[0].ubication[0] + c_snake_ptr->direction[0];
next_y = c_snake_ptr->body_snake[0].ubication[1] + c_snake_ptr->direction[1];

/* Part 3: Check if next position of snake is the same as
		   snake body  */
for(int i=1; i<(*length_ptr); i++)
{
	if((next_x==c_snake_ptr->body_snake[i].ubication[0]) && 
	(next_y==c_snake_ptr->body_snake[i].ubication[1]))
	{
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
			printf(" +++++++++++++++++++++++++++++++++++++++++++++++\n");
			printf(" +            Quiere volver a jugar?           +\n");
			printf(" +                                             +\n");
			printf(" +      Presione 'ENTER' para REINICIAR        +\n");
			printf(" +      Presione 'ESC'   para SALIR            +\n");
			printf(" +                                             +\n");
			printf(" +++++++++++++++++++++++++++++++++++++++++++++++\n");
			
			tecla_temp=getch();
				
			if(tecla_temp==13){
				*score_ptr=0;
				*length_ptr=3;
				*level_game_ptr=1;
				c_snake_ptr->body_snake[0].ubication[0]=10,
				c_snake_ptr->body_snake[0].ubication[1]=10;
				enter=0;
			}
			else if(tecla_temp==27){
				FOOD_Free(food_ptr);
				system("cls");
				printf(" ++++++++++++++++++++++++++++++++++++++++++++++\n");
				printf(" +                                            +\n");
				printf(" +                                            +\n");
				printf(" +              SALIO DEL JUEGO               +\n");
				printf(" +         |^-^| Vuelva pronto |^-^|          +\n");
				printf(" +                                            +\n");
				printf(" +                                            +\n");
				printf(" ++++++++++++++++++++++++++++++++++++++++++++++\n");
				exit(1);
			}
			
		}
	}
}

/* Part 4: Choose the matrix that describes the current stage level */
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

/* Part 5: Check if next position of snake is the same as
		   stage walls and update new snake head
		   position if there is not wall in front*/
if((current_stage[next_x][next_y] == 1) ||
    (current_stage[next_x][next_y] == 2) 
	||(current_stage[next_x][next_y] == 3)) {
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
		printf(" +++++++++++++++++++++++++++++++++++++++++++++++\n");
		printf(" +            Quiere volver a jugar?           +\n");
		printf(" +                                             +\n");
		printf(" +      Presione 'ENTER' para REINICIAR        +\n");
		printf(" +      Presione 'ESC'   para SALIR            +\n");
		printf(" +                                             +\n");
		printf(" +++++++++++++++++++++++++++++++++++++++++++++++\n");
		
		
		tecla_temp=getch();
			
		if(tecla_temp==13){
			*score_ptr=0;
			*length_ptr=3;
			*level_game_ptr=1;
			c_snake_ptr->body_snake[0].ubication[0]=10,
			c_snake_ptr->body_snake[0].ubication[1]=10;
			enter=0;
		}
		else if(tecla_temp==27){
			FOOD_Free(food_ptr);
			system("cls");
			printf(" ++++++++++++++++++++++++++++++++++++++++++++++\n");
			printf(" +                                            +\n");
			printf(" +                                            +\n");
			printf(" +              SALIO DEL JUEGO               +\n");
			printf(" +         |^-^| Vuelva pronto |^-^|          +\n");
			printf(" +                                            +\n");
			printf(" +                                            +\n");
			printf(" ++++++++++++++++++++++++++++++++++++++++++++++\n");
			exit(1);
		}
		
	}
} 
else {
    c_snake_ptr->body_snake[0].ubication[0] +=  c_snake_ptr->direction[0];
    c_snake_ptr->body_snake[0].ubication[1] +=  c_snake_ptr->direction[1];
}

/* Part 6: Refresh stage with new view */
Refresh_Stage_in_Text_Mode( c_snake_ptr,food_ptr,ti_food_ptr, score_ptr,
                            console_buf, length_ptr,level_game_ptr);

return 1;

} /* Forward */


/*FN****************************************************************************
*
*   int Game(SNAKE_T *c_snake_ptr,char pos_x,char pos_y,DIRECTION_T head_symbol,
*			 int *length_ptr,int *score_ptr,FOOD_T *food_ptr,
*            double  *ti_food_ptr,char console_buf[][CON_COLS],
*			 char stage[][STAGE_COLS], char stage_1[][STAGE_COLS],    
*            int *level_game_ptr);
*
*   Return:  Nothing
*
*   Purpose: Finite State Machine for the game of one snake
*
*   Plan:
*			Part 1: Initiate and update in console stage, snake and food
*           Part 2: Identify the initial direction of the snake
*           Part 3: The snake moves forward and the time food is checked
*                   while there is not an input key
*           Part 4: According to key pressed,the direction of the snake changes 
*                   updating the console and it is not allowed for the snake 
*			        to change the direction over it's own trajectory
*
*   Register of Revisions (Debugging Process):
*
*   DATE       RESPONSIBLE              COMMENT
*   -----------------------------------------------------------------------
* 	Apr 26/20  M.Bravo,V.Hildago,
*			   K.Vargas & P.Chaparro    Initial implementation
*
*******************************************************************************/

int 
Game( 
SNAKE_T *c_snake_ptr,          /* In: Structure of snake status        */
char pos_x,char pos_y,         /* In: Position of snake in stage       */
DIRECTION_T head_symbol,       /* In: Snake unitary direction          */
int *length_ptr,               /* In: Snake size                       */
int *score_ptr,                /* In: Pointer to score                 */
FOOD_T *food_ptr,              /* In: Structure of food status         */
double  *ti_food_ptr,          /* In: Pointer to initial time food     */
char console_buf[][CON_COLS],  /* In: Buffer of console                */
char stage[][STAGE_COLS],      /* In: Map of stage level 0             */ 
char stage_1[][STAGE_COLS],    /* In: Map of stage level 1             */ 
int *level_game_ptr)           /* In: Pointer to the stage level       */
{
	/* Declaration of SNADOS FSM */
	typedef enum {BEGIN, WAIT_A_CHAR} STATE_T;
	
	STATE_T state=BEGIN;
	SNAKE_T snake;
	char direction_tmp;
	int no_back=0;
	int Loop=1;
	while (Loop){
		switch(state){
			case BEGIN:
				/* Part 1: Initiate and update in console stage, snake 
				           and food  */
				Initiate_Stage_in_Text_Mode( console_buf, stage );
				Initiate_Snake(c_snake_ptr, pos_x, pos_y, head_symbol,
				               length_ptr);
				*FOOD_Set(food_ptr, ti_food_ptr, c_snake_ptr,stage, stage_1);
				Refresh_Stage_in_Text_Mode(c_snake_ptr, food_ptr, ti_food_ptr,
			                               score_ptr,console_buf, length_ptr,
										   level_game_ptr);
											
				/* Part 2: Identify the initial direction of the snake */
				if(c_snake_ptr->direction[0]==-1 && 
					c_snake_ptr->direction[1]==0){
					no_back=72;
				}
				else if(c_snake_ptr->direction[0]==1 && 
				        c_snake_ptr->direction[1]==0){
					no_back=80;
				}
				else if(c_snake_ptr->direction[0]==0 &&
           				c_snake_ptr->direction[1]==-1){
					no_back=75;
				}
				else{
					no_back=77;
				}
				state= WAIT_A_CHAR;
			break;
			
			case WAIT_A_CHAR:
				/* Part 3: The snake moves forward and the time food is
            			   checked while there is not an input key */
				do{
					fflush(stdin);
					Forward(c_snake_ptr, food_ptr, ti_food_ptr, score_ptr,
					        console_buf, stage,stage_1,level_game_ptr ,length_ptr);
					FOOD_Get_Time(food_ptr, ti_food_ptr, c_snake_ptr,
					              stage, stage_1);
					
				}while(!kbhit());
				
				/* Part 4: According to key pressed,the direction of the
            			   snake changes updating the console and it is not 
						   allowed for the snake to change the direction over 
						   it's own trajectory*/
				direction_tmp = getch();

				if((direction_tmp == 72) && (no_back!=80)){     //UP
					c_snake_ptr->direction[0]=-1, c_snake_ptr->direction[1]=0;
					no_back=72;
				}
				else if((direction_tmp == 80) && (no_back!=72)){//DOWN
					c_snake_ptr->direction[0]=1, c_snake_ptr->direction[1]=0;
					no_back=80;
				}
				else if((direction_tmp == 75) && (no_back!=77)){//LEFT
					c_snake_ptr->direction[0]=0, c_snake_ptr->direction[1]=-1;
					no_back=75;
				}
				else if((direction_tmp == 77) && (no_back!=75)){//RIGHT
					c_snake_ptr->direction[0]=0, c_snake_ptr->direction[1]=1;
					no_back=77;
				}
				else if(direction_tmp == 27){//Tecla ESC
					system( "cls");
					printf(" ++++++++++++++++++++++++++++++++++++++++++++++\n");
					printf(" +                                            +\n");
					printf(" +                                            +\n");
					printf(" +              SALIO DEL JUEGO               +\n");
					printf(" +         |^-^| Vuelva pronto |^-^|          +\n");
					printf(" +                                            +\n");
					printf(" +                                            +\n");
					printf(" ++++++++++++++++++++++++++++++++++++++++++++++\n");
					exit(1);
				}
				
				Refresh_Stage_in_Text_Mode(c_snake_ptr, food_ptr, ti_food_ptr,
				                            score_ptr,console_buf, length_ptr,
											level_game_ptr);
			break;
			
		}
	}
	return 1;
} /* Game */

/*FN****************************************************************************
*
*   int Intro_Game();
*
*   Return:  Nothing
*
*   Purpose: Prints the rules of the game
*
*   Plan:
*
*   Register of Revisions (Debugging Process):
*
*   DATE       RESPONSIBLE              COMMENT
*   -----------------------------------------------------------------------
* 	May 19/20  M.Bravo,V.Hildago,
*			   K.Vargas & P.Chaparro    Initial implementation
*
*******************************************************************************/

int 
Intro_Game()
{
	int enter=1;
	char tecla_temp;
	
	while(enter){
		system( "cls");
		printf(" ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
		printf(" +                                 BIENVENIDO AL JUEGO SNADOS                                   +\n");
		printf(" ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

		printf(" +  REGLAS:                                                                                     +\n");
		printf(" +     (1) La serpiente se mueve con las flechas del teclado.                                   +\n");
		printf(" +     (2) Si se estrella contra una pared o el cuerpo de la serpiente: GAME OVER.              +\n");
		printf(" +     (3) El juego tiene dos niveles.                                                          +\n");
		printf(" +     (4) No esta permitido que la serpiente se devuelva sobre la trayectoria en la que venia. +\n");
		printf(" +     (5) Si desea salir del juego presione la tecla 'ESC'.                                    +\n");
		printf(" ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");

		printf("    Presione 'ENTER' para empezar el JUEGO... ");
		
		tecla_temp=getch();
		
		if(tecla_temp==13){
			enter=0;
			system( "cls");
		}
		else if(tecla_temp==27){
			system( "cls");
			printf(" ++++++++++++++++++++++++++++++++++++++++++++++\n");
			printf(" +                                            +\n");
			printf(" +                                            +\n");
			printf(" +              SALIO DEL JUEGO               +\n");
			printf(" +         |^-^| Vuelva pronto |^-^|          +\n");
			printf(" +                                            +\n");
			printf(" +                                            +\n");
			printf(" ++++++++++++++++++++++++++++++++++++++++++++++\n");
			exit(1);
		}
		else{
			system( "cls");
			printf(" ++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
			printf(" +                                                  +\n");
			printf(" +                                                  +\n");
			printf(" +              !!!!! TECLA INVALIDA !!!!!          +\n");
			printf(" +                                                  +\n");
			printf(" +                                                  +\n");
			printf(" ++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
			double previous= clock() * 1.0 / CLOCKS_PER_SEC;
			while( clock() * 1.0 / CLOCKS_PER_SEC - previous < 1 );
		}
	}

	return 1;
}

/* ------------------------- Main Function    ------------------------ */
int main ( int argc, char *argv[] ){
	Intro_Game();
	Game(&current_snake,10, 10, DOWN, &LENGTH, &score_snake, FOOD_New(), 
	     &Ti_food,console_buf, stage_A, stage_B, &Level_game);
	return 0;
}
