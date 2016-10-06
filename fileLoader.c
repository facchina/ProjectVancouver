#include <allegro5/allegro.h>                     /* bibilioteca Allegro 5 */
#include <allegro5/allegro_image.h>              /* add-on para uso de imagens */
#include <stdio.h>

//ponteiro para a imagem do player
ALLEGRO_BITMAP* spritePlayer = NULL; 

void loadingImages (){
	// Inicializa o add-on para utilização de imagens
	al_init_image_addon();

	if (!al_init_image_addon){
		fprintf(stderr, "Falha ao inicializar add-on allegro_image.\n");
	}

	// Carrega o sprite player
	spritePlayer = al_load_bitmap("red.jpg");

	if (!spritePlayer){
	    fprintf(stderr, "Falha ao carregar o arquivo de imagem.\n");	
	}
}

ALLEGRO_BITMAP* getPlayerImage (){

	return spritePlayer;
}
