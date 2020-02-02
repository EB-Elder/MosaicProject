// ConsoleApplication1.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#include <iostream>
#include <string>
#include "../lib/CImg-2.8.3/CImg.h"
#include "jpeglib.h"
#include "Traitement.h"
#include "Image.h"


using namespace cimg_library;

//Fonction ayant permis de créer  un dataset d'image de teinte différente
void datasetCreation() {
	
	CImg<unsigned char> img(100, 100, 1, 3, 0);

	int i = 0;
	for (int r = 0; r <= 255; r += 25)
	{
		for (int g = 0; g <= 255; g += 25)
		{
			for (int b = 0; b <= 255; b += 25)
			{
				for (int x = 0; x < 100; x++)
				{
					for (int y = 0; y < 100; y++)
					{
						img(x, y, 0, 0) = r;
						img(x, y, 0, 1) = g;
						img(x, y, 0, 2) = b;

					}
				}
				std::cout << "file" + std::to_string(i) + ".bmp" << std::endl;
				std::string tmp = "./images/file" + std::to_string(i) + ".bmp";
				img.save(tmp.c_str());
				i++;
			}
		}
	}
}



int main() {


	Image InitialImage("barbara.bmp");
	Image tst(200, 200);
	Traitement::croping(tst, InitialImage, 200, 200, 200, 200);
	tst.saveFile("cropedBarbara.bmp");

	return 0;
}