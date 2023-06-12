/* Ruler 1         2         3         4         5         6         7        */

/* snados.c *********************************************************************/
/*                                                                            */
/*   ┌────┐ ┌────┐                            SNADOS                          */
/*   └┐  ┌┘ └┐╔══╧═╗                                                          */
/*    │  │   │╚╗  ╔╝      This code was designed in order to teach skills     */
/*    │  │   │ ║  ║       to conceive, design and implement algorithms by     */
/*    │  │   │ ║  ║       using Finite State Machines (FSM), pointers,        */
/*    │╔═╧══╗│ ║  ║       structures and encapsulation.                       */
/*    │╚╗  ╔╝┘ ║  ║                                                           */
/*    └┐║  ╚╗ ╔╝  ║       DEVELOPED BY:  M & P & K & V                        */
/*     └╚╗  ╚═╝  ╔╝                                                           */
/*      └╚╗     ╔╝                                                            */
/*        ╚═════╝         Bogota, D.C., April  26th, 2020.                    */
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
#include <time.h>
/* ------------------------ Inclusion of Own Headers ------------------------ */
#include "snados.h"
#include "food.h"
#include "snake.h"

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


/* Declaration of SNADOS FSM */
typedef enum {BEGIN, WAIT_A_CHAR, INITIAL_CHAR} STATE_T;

/*Declaration of variable to save score*/
int score_snake[2]={0,0};

/*Declaration of snake size variable*/
int LENGTH[2]={2,2};

/*Declaration of level game variable*/
int Level_game= 1;

/*Declaration of time food initialization variable*/
double Ti_food;

/* Delay between movements */
double delay = 0.1;

/* Buffer to display the map of stage in stdout through ASCII chars */
static char console_buf[CON_ROWS][CON_COLS];

/* Functions */			
int Refresh_Stage_in_Text_Mode(SNAKE_T *snake_1_ptr, SNAKE_T *snake_2_ptr,
                             FOOD_T *food_ptr,double *ti_food_ptr,
							 int *score_ptr1,int *score_ptr2,
							 char console_buf[][CON_COLS],int *length_ptr1,
                             int *length_ptr2,int *level_game_ptr);
						   
void Game( SNAKE_T *snake_1_ptr, SNAKE_T *snake_2_ptr,char pos_x,
           char pos_y,char pos_x1,char pos_y1,DIRECTION_T head_symbol_1,
		   DIRECTION_T head_symbol_2,int *length_ptr1,int *score_ptr1,
		   int *length_ptr2,int *score_ptr2,FOOD_T *food_ptr, 
		   double  *ti_food_ptr, char console_buf[][CON_COLS],  
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
char console_buf[][CON_COLS],  /* Out: Buffer of console      */
char stage[][STAGE_COLS] )     /* In:  Map of current stage   */
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
				if(stage[i][j]==1){       //Identifier "1" for LATERAL WALLS
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
*   int Refresh_Stage_in_Text_Mode(SNAKE_T *snake_1_ptr,SNAKE_T *snake_2_ptr,
*                                 FOOD_T *food_ptr,double *ti_food_ptr, 
*                                 int *score_ptr1, int *score_ptr2,
*                                 char console_buf[][CON_COLS],  
*                                  int *length_ptr1,int *length_ptr2,               
*                                  int *level_game_ptr);
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
*           Part 6: Determine alphabetic char for food, when any head takes 
*					the same position as the food score is pre-incremented
*					snake length is incremented
*           Part 7: Update food position in the stage
*           Part 8: Clear, print and pause console every 0.1 seconds
*  
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
Refresh_Stage_in_Text_Mode(
SNAKE_T *snake_1_ptr,          /* In:     Structure of snake 1 status    */
SNAKE_T *snake_2_ptr,          /* In:     Structure of snake 2 status    */
FOOD_T *food_ptr,              /* Out:    Structure of food status       */
double *ti_food_ptr,           /* In:     Pointer to initial time food   */
int *score_ptr1,               /* In/Out: Pointer to snake 1 score       */
int *score_ptr2,               /* In/Out: Pointer to snake 2 score       */
char console_buf[][CON_COLS],  /* In/Out: Buffer of console              */
int *length_ptr1,              /* In/Out: Snake 1 size                   */
int *length_ptr2,              /* In/Out: Snake 2 size                   */
int *level_game_ptr)           /* In/Out: Pointer to the stage level     */
{
char console_buf_tmp[CON_ROWS][CON_COLS];
char i, j;
char pos_x0, pos_y0;
char pos_x1, pos_y1;
char pos_x2, pos_y2;
char head_symbol_1;
char head_symbol_2;
char food_symbol;

/* Part 1: Copy the stage in a temporal buffer */
for( i=0; i<CON_ROWS; i++ )
    for( j=0; j<CON_COLS; j++ )
        console_buf_tmp[i][j] = console_buf[i][j];
	
/* Part 2: Take current position of snake head */
pos_x0 = SNAKE_Get_x(snake_1_ptr);
pos_y0 = SNAKE_Get_y(snake_1_ptr);


pos_x1 = SNAKE_Get_x(snake_2_ptr);
pos_y1 = SNAKE_Get_y(snake_2_ptr);

/* Part 3: Update snake body position in the stage */
SNAKE_Update(snake_1_ptr, length_ptr1, head_symbol_1,
              console_buf_tmp,1);
SNAKE_Update(snake_2_ptr, length_ptr2, head_symbol_2,
              console_buf_tmp,2);

/* Part 5: Take current position of food */
pos_x2 = food_ptr->ubication[0];
pos_y2 = food_ptr->ubication[1];

/* Part 6: Determine alphabetic char for food, when any head takes 
			the same position as the food score is pre-incremented
			snake length is incremented*/
if( (pos_x0== pos_x2 && pos_y0==pos_y2) ||
    (pos_x1== pos_x2 && pos_y1==pos_y2) ){
		
	if((pos_x0== pos_x2 && pos_y0==pos_y2)){
		food_symbol = head_symbol_1;
		++*score_ptr1;
	    ++*length_ptr1;
	}
	else{
		food_symbol = head_symbol_2;
		++*score_ptr2;
	    ++*length_ptr2;
	}
	
	if((*score_ptr1 < 3) && (*score_ptr2 < 3))
		*level_game_ptr=1;
	else if((*score_ptr1 < 5) && (*score_ptr2 < 5))
		*level_game_ptr=2;
	
	*FOOD_Set(food_ptr, ti_food_ptr, snake_1_ptr,
	           snake_2_ptr,stage_A, stage_B);
}
else
	food_symbol=184;

/* Part 7: Update food position in the stage */
console_buf_tmp[pos_x2][pos_y2*2] = food_symbol;

/* Part 8: Clear, print and pause console every 2 seconds */

system( "cls");

for( i=0; i<CON_ROWS; i++ )
    for( j=0; j<CON_COLS; j++ )
        printf("%c", console_buf_tmp[i][j] );
	
printf("   SCORE SNAKE 1:%d   ", *score_ptr1);
printf(" SCORE SNAKE 2:%d \n\n", *score_ptr2);

printf("       LEVEL:%d \n\n", *level_game_ptr);	

double previous = clock() * 1.0 / CLOCKS_PER_SEC;
while( clock() * 1.0 / CLOCKS_PER_SEC - previous < delay );

printf("\n");

return 1;

} /* Refresh_Stage_in_Text_Mode */
        

		
/*FN****************************************************************************
*
*   void Game( SNAKE_T *snake_1_ptr, SNAKE_T *snake_2_ptr,char pos_x,
*           char pos_y,char pos_x1,char pos_y1,DIRECTION_T head_symbol_1,
*		   DIRECTION_T head_symbol_2,int *length_ptr1,int *score_ptr1,
*		   int *length_ptr2,int *score_ptr2,FOOD_T *food_ptr, 
*		   double  *ti_food_ptr, char console_buf[][CON_COLS],  
*          char stage[][STAGE_COLS],char stage_1[][STAGE_COLS],
*		   int *level_game_ptr);
*
*   Return:  Nothing
*
*   Purpose: Finite State Machine for the game of two snakes
*
*   Plan:
*			Part 1: Initiate and update in console stage, snake 1,
*				    snake 2 and food
*           Part 2: Identify the initial direction of the snake 1
*           Part 3: Identify the initial direction of the snake 2
*           Part 4: The snakes move forward and the time food is checked
*                   while there is not an input key
*           Part 5: According to key pressed,the direction of the snakes
*                   changes updating the console and it is not allowed 
*                   for the snakes to change the direction over it's 
*                   own trajectory
*
*   Register of Revisions (Debugging Process):
*
*   DATE       RESPONSIBLE              COMMENT
*   -----------------------------------------------------------------------
* 	Apr 26/20  M.Bravo,V.Hildago,
*			   K.Vargas & P.Chaparro    Initial implementation
* 	May 24/20  M.Bravo,V.Hildago,
*			   K.Vargas & P.Chaparro    Second implementation
*
*******************************************************************************/

void 
Game( 
SNAKE_T *snake_1_ptr,          /* In: Structure of snake 1 status    */
SNAKE_T *snake_2_ptr,          /* In: Structure of snake 2 status    */
char pos_x,char pos_y,         /* In: Position of snake 1 in stage   */
char pos_x1,char pos_y1,       /* In: Position of snake 2 in stage   */
DIRECTION_T head_symbol_1,     /* In: Snake 1 unitary direction      */
DIRECTION_T head_symbol_2,     /* In: Snake 2 unitary direction      */
int *length_ptr1,              /* In: Snake 1 size                   */
int *score_ptr1,               /* In: Pointer to snake 1 score       */
int *length_ptr2,              /* In: Snake 2 size                   */
int *score_ptr2,               /* In: Pointer to snake 2 score       */
FOOD_T *food_ptr,              /* In: Structure of food status       */
double  *ti_food_ptr,          /* In: Pointer to initial time food   */
char console_buf[][CON_COLS],  /* In: Buffer of console              */
char stage[][STAGE_COLS],      /* In: Map of stage level 0           */ 
char stage_1[][STAGE_COLS],    /* In: Map of stage level 1           */ 
int *level_game_ptr)           /* In: Pointer to the stage level     */
{
	STATE_T state=BEGIN;
	char direction_tmp;
	int no_back=0, no_back1=0, Loop=1, temp_1, temp_2;
	
	while(Loop){
		switch(state){
			case BEGIN:
				/* Part 1: Initiate and update in console stage, snake 1,
				           snake 2 and food  */
				Initiate_Stage_in_Text_Mode( console_buf, stage );
				*SNAKE_Set(snake_1_ptr, pos_x, pos_y, head_symbol_1, 
						   length_ptr1);
				*SNAKE_Set(snake_2_ptr, pos_x1, pos_y1, head_symbol_2, 
						   length_ptr2);
				*FOOD_Set(food_ptr, ti_food_ptr, snake_1_ptr,
				          snake_2_ptr,stage, stage_1);
				Refresh_Stage_in_Text_Mode(snake_1_ptr,snake_2_ptr, food_ptr, 
				                           ti_food_ptr, score_ptr1,score_ptr2,
										   console_buf, length_ptr1,length_ptr2,
										   level_game_ptr);
				
                state=INITIAL_CHAR;
			break;
			
			case INITIAL_CHAR:
			
				/* Part 2: Identify the initial direction of the snake 1*/
				if(snake_1_ptr->direction[0]==-1 && 
					snake_1_ptr->direction[1]==0){
					no_back=72;
				}
				else if(snake_1_ptr->direction[0]==1 && 
				        snake_1_ptr->direction[1]==0){
					no_back=80;
				}
				else if(snake_1_ptr->direction[0]==0 &&
           				snake_1_ptr->direction[1]==-1){
					no_back=75;
				}
				else{
					no_back=77;
				}
				
				/* Part 3: Identify the initial direction of the snake 2*/
				if(snake_2_ptr->direction[0]==-1 && 
					snake_2_ptr->direction[1]==0){
					no_back1=119;  //UP "w" 
				}
				else if(snake_2_ptr->direction[0]==1 && 
				        snake_2_ptr->direction[1]==0){
					no_back1=115;  // DOWN "s"
				}
				else if(snake_2_ptr->direction[0]==0 &&
           				snake_2_ptr->direction[1]==-1){
					no_back1=97;   //LEFT "a"
				}
				else{
					no_back1=100;   //RIGHT "d"
				}
				state= WAIT_A_CHAR;
			break;
			
			case WAIT_A_CHAR:
				/* Part 4: The snakes move forward and the time food is
            			   checked while there is not an input key */
				do{
					fflush(stdin);
					temp_1=SNAKE_Forward(snake_1_ptr,snake_2_ptr, score_ptr1,score_ptr2,
					              console_buf,stage,stage_1,level_game_ptr ,
								  length_ptr1,length_ptr2,food_ptr,1);
					Refresh_Stage_in_Text_Mode(snake_1_ptr,snake_2_ptr, food_ptr, 
				                           ti_food_ptr, score_ptr1,score_ptr2,
										   console_buf, length_ptr1,length_ptr2,
										   level_game_ptr);
					temp_2=SNAKE_Forward(snake_2_ptr,snake_1_ptr, score_ptr2,score_ptr1,
					              console_buf,stage,stage_1,level_game_ptr ,
								  length_ptr2,length_ptr1,food_ptr,2);			   
					Refresh_Stage_in_Text_Mode(snake_1_ptr,snake_2_ptr, food_ptr, 
				                           ti_food_ptr, score_ptr1,score_ptr2,
										   console_buf, length_ptr1,length_ptr2,
										   level_game_ptr);
					FOOD_Get_Time(food_ptr, ti_food_ptr, snake_1_ptr,
					              snake_2_ptr,stage, stage_1);
					if((temp_1==2) || (temp_2==2)){
						no_back=0;
						no_back1=0;
						state=INITIAL_CHAR;
					}
				}while(!kbhit());
				
				/* Part 5: According to key pressed,the direction of the
            			   snakes changes updating the console and it is not 
						   allowed for the snakes to change the direction over 
						   it's own trajectory*/
				direction_tmp = getch();

				if((direction_tmp == 72) && (no_back!=80)){ //UP
					snake_1_ptr->direction[0]=-1, snake_1_ptr->direction[1]=0;
					no_back=72;
				}
				else if((direction_tmp == 80) && (no_back!=72)){//DOWN
					snake_1_ptr->direction[0]=1, snake_1_ptr->direction[1]=0;
					no_back=80;
				}
				else if((direction_tmp == 75) && (no_back!=77)){//LEFT
					snake_1_ptr->direction[0]=0, snake_1_ptr->direction[1]=-1;
					no_back=75;
				}
				else if((direction_tmp == 77) && (no_back!=75)){//RIGHT
					snake_1_ptr->direction[0]=0, snake_1_ptr->direction[1]=1;
					no_back=77;
				}
				
				else if((direction_tmp == 119) && (no_back1!=115)){ //UP
					snake_2_ptr->direction[0]=-1, snake_2_ptr->direction[1]=0;
					no_back1=119;
				}
				else if((direction_tmp == 115) && (no_back1!=119)){//DOWN
					snake_2_ptr->direction[0]=1, snake_2_ptr->direction[1]=0;
					no_back1=115;
				}
				else if((direction_tmp == 97) && (no_back1!=100)){//LEFT
					snake_2_ptr->direction[0]=0, snake_2_ptr->direction[1]=-1;
					no_back1=97;
				}
				else if((direction_tmp == 100) && (no_back1!=97)){//RIGHT
					snake_2_ptr->direction[0]=0, snake_2_ptr->direction[1]=1;
					no_back1=100;
				}
				
				else if(direction_tmp == 27){//Tecla ESC
					FOOD_Free(food_ptr);
					SNAKE_Free(snake_1_ptr);
					SNAKE_Free(snake_2_ptr);
					exit(1); 
				}
				
				Refresh_Stage_in_Text_Mode(snake_1_ptr,snake_2_ptr, food_ptr, 
				                           ti_food_ptr, score_ptr1,score_ptr2,
										   console_buf, length_ptr1,length_ptr2,
										   level_game_ptr);
			break;
			
		}
	}
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
* 	May 24/20  M.Bravo,V.Hildago,
*			   K.Vargas & P.Chaparro    Second implementation
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
		printf(" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
		printf(" +                            BIENVENIDO AL JUEGO SNADOS-MULTIJUDADOR                            +\n");
		printf(" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

		printf(" +  REGLAS:                                                                                      +\n");
		printf(" +     (1) La serpiente 1, se mueve con las flechas del teclado.                                 +\n");
		printf(" +     (2) La serpiente 2, se mueve con las teclas A,W,S y D en minusculas.                      +\n");
		printf(" +     (2) Si alguna de las serpientes se estrella contra una pared o su cuerpo o el cuerpo de   +\n");
		printf(" +         la otra serpiente: GAME OVER.                                                         +\n");
		printf(" +     (3) El juego tiene dos niveles.                                                           +\n");
		printf(" +     (4) No esta permitido que las serpientes se devuelvan sobre la trayectoria en la          +\n");
		printf(" +         que venian.                                                                           +\n");
		printf(" +     (5) Si desean salir del juego presionar la tecla 'ESC'.                                   +\n");
		printf(" +     (6) CUERPO serpiente UNO esta conformado por circulos mientras que el CUERPO de la        +\n");
        printf(" +         DOS esta conformado por equis.                                                        +\n");
		printf(" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");

		printf("    Presione 'ENTER' para empezar el JUEGO... \n");
		
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
			printf(" +            !!!!! TECLA INVALIDA !!!!!            +\n");
			printf(" +                                                  +\n");
			printf(" +                                                  +\n");
			printf(" ++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
			double previous= clock() * 1.0 / CLOCKS_PER_SEC;
			while( clock() * 1.0 / CLOCKS_PER_SEC - previous < 1 );
		}
	}

	return 1;
}

int main ( int argc, char *argv[] ){
	Intro_Game();
	Game( SNAKE_New(), SNAKE_New(), 4, 4 , 16, 16,DOWN,UP,  
		 &LENGTH[0],&score_snake[0],&LENGTH[1],&score_snake[1],   
          FOOD_New(),&Ti_food,console_buf,stage_A,stage_B,  
          &Level_game);
	return 0;
}
