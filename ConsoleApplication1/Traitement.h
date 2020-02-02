#pragma once
#include "Image.h"

class Traitement
{
	public:
		Traitement();
		static void croping(Image& To, Image& From, int startX, int startY, int length, int height);
		

};

