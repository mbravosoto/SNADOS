/* Ruler 1         2         3         4         5         6         7        */
/*         DEVELOPED BY: Bravo Manuela, Chaparro Ma. del Pilar,               */
/*                   Hidalgo Valentina & Vargas Karen                         */
//*****************************************************************************/

#include "snados.h"

#ifndef	 SNAKE_H
#define  SNAKE_H

/******************* Declaration of Classes with Attributes *******************/

/************************ Prototypes of Public Methods ************************/
SNAKE_T *SNAKE_New();

SNAKE_T *SNAKE_Set(SNAKE_T *snake_ptr,char pos_x, char pos_y, 
                   DIRECTION_T head_symbol,int *length_ptr);

char  SNAKE_Get_x(SNAKE_T *snake_ptr);

char  SNAKE_Get_y(SNAKE_T *snake_ptr);

int SNAKE_Update(SNAKE_T *snake_ptr,int *length_ptr,DIRECTION_T head_symbol,
                 char console_buf[][CON_COLS], int id_snake);

int SNAKE_Forward( SNAKE_T *c_snake_ptr,SNAKE_T *other_snake_ptr,
                   int *c_score_ptr,int *other_score_ptr, 
				   char console_buf[][CON_COLS],char stage[][STAGE_COLS],
				   char stage_1[][STAGE_COLS],int *level_game_ptr, 
                  int *c_length_ptr,int *other_length_ptr,
				  FOOD_T *food_ptr,int id_snake);
				  
int SNAKE_Free( SNAKE_T *snake_n_ptr );

#endif /*  SNAKE_H */	