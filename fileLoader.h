#include <allegro5/allegro_image.h>              /* add-on para uso de imagens */
//Cabeçalhos das funcoes implementadas no fileLoader.c
#ifndef FILELOADER_H_INCLUDED
#define FILELOADER_H_INCLUDED

//Funcao responsavel por carregar imagens
extern void loadingImages();
extern ALLEGRO_BITMAP* getPlayerImage ();
#endif //fim da definicao de FILELOADER_H