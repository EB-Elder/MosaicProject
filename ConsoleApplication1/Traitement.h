#pragma once
#include "Image.h"

class Traitement
{
	public:
		Traitement();
		static void croping(Image& To, Image& From, int startX, int startY, int length, int height);
		static int diffVal(Image& image1, Image& image2);
		static int diffHisto(Image& image1, Image& image2);
		static void resize(Image& to, Image& from);

		

};

