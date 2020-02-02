#include "Traitement.h"

Traitement::Traitement(){
	
}

void Traitement::croping(Image& To, Image& From, int startX, int startY, int length, int height) {

	int i = 0;
	int j = 0;
	for (int x = startX; x < startX + length; x++)
	{
		for (int y = startY; y < startY + length; y++)
		{
			To.setPixel(i, j, 0, From.getPixel(x, y, 0));
			To.setPixel(i, j, 1, From.getPixel(x, y, 1));
			To.setPixel(i, j, 2, From.getPixel(x, y, 2));
			
			j++;
			
		}
		j = 0;
		i++;
	}
	
	

}