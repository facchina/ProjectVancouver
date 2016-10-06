#include <allegro5/allegro.h>                     /* bibilioteca Allegro 5 */
#include <allegro5/allegro_image.h>              /* add-on para uso de imagens */
#include <stdio.h>
#include "fileLoader.h"

void drawImages (){
	ALLEGRO_BITMAP *player; 
	player = getPlayerImage();
	// Desenha a imagem do player na tela

	al_draw_bitmap(player, 0, 0, 0);
}