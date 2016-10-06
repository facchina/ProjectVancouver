#include <stdio.h>
#include <allegro5/allegro.h>                     /* bibilioteca Allegro 5 */
#include <allegro5/allegro_image.h>              /* add-on para uso de imagens */
#include "fileLoader.h"
#include "render.h"
//Declaracao de variaveis constantes
#define WIDTH 800
#define HEIGHT 600

int main (void){

	//Declaracao de variaveis 
	ALLEGRO_DISPLAY *window = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	bool close_application = 0;
	/********************
	 *       START      *
	 ********************/

	//Inicializando a biblioteca Allegro
	al_init();

	if (!al_init())
	{
	    fprintf(stderr, "Falha ao inicializar a Allegro.\n");
	    return -1;
	}
	//Criando e setando as dimensoes da janela
	window = al_create_display(WIDTH, HEIGHT);

	if (!window)
	{
	    fprintf(stderr, "Falha ao criar janela.\n");
	    return -1;
	}
	//Estrutura do tipo fila que armazena os eventos que o programa dispara
	event_queue = al_create_event_queue();
	    if (!event_queue)
	    {
	        fprintf(stderr, "Falha ao criar fila de eventos.\n");
	        al_destroy_display(window);
	        return -1;
	    }
	//Todos os eventos que ocorrerem em window serão enfileirados na event_queue
	al_register_event_source(event_queue, al_get_display_event_source(window)); 
	//Limpando a tela 
	al_clear_to_color(al_map_rgb(255, 255, 255));
	//Carregando imagens
	loadingImages();

	/********************
	 *      UPDATE      *
	 ********************/
	
	while (!close_application){
		//Armazena os eventos retirados da fila de eventos
		ALLEGRO_EVENT event;
		//Tempo de espera por eventos
	    ALLEGRO_TIMEOUT timeout;

		//Verifica a fila de eventos durante o tempo estipulado por timeout
		//Se um evento for encontrado retorna 1 e atribui o evento para a variavel event
		int have_events = al_wait_for_event_until(event_queue, &event, &timeout);
		
		//Se existir eventos e o tipo de evento for fechar a janela
		//saímos do loop
		if (have_events && event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			switch (event.type){
				//Fechar a janela
				case ALLEGRO_EVENT_DISPLAY_CLOSE:
				close_application = true; 
				break; 
			}

		}		 

		/********************
		 *     RENDERING    *
		 ********************/

		//Redesenhando as imagens na tela
		drawImages(); 
		//Atualizando a tela
		al_flip_display();
	}

	/********************
	 *       ENDS       *
	 ********************/

	//Libera o espaço de memoria utilizado pelos ponteiros

	//Destroi a janela
	al_destroy_display(window);
	//Destroi fila de eventos
	al_destroy_event_queue(event_queue);
	return 0;
}