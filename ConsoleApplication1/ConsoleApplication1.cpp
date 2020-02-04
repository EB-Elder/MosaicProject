// ConsoleApplication1.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#include <iostream>
#include <string>
#include "../lib/CImg-2.8.3/CImg.h"
#include "Traitement.h"
#include "Image.h"
#include <iostream> 
#include <vector>  


using namespace cimg_library;

//Fonction ayant permis de créer  un dataset d'image de teinte différente
void datasetCreation(int heigth, int length) {
	
	CImg<unsigned char> img(heigth, length, 1, 3, 0);

	int i = 0;
	for (int r = 0; r <= 255; r += 75)
	{
		for (int g = 0; g <= 255; g += 75)
		{
			for (int b = 0; b <= 255; b += 75)
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
				std::string tmp = "./images/" + std::to_string(r) + "_" + std::to_string(g)+ "_" + std::to_string(b) + ".bmp";
				img.save(tmp.c_str());
				i++;
			}
		}
	}
}



int main() {


	
	
	Image InitialImage("resized_barbara_croped.bmp");
	Image tigreImage("resized_barbara_croped.bmp");
	Image resised(500, 500);
	Traitement::resize(resised, InitialImage);



	//Image tst2(InitialImage.getXsize(), InitialImage.getYsize());
	

	//std::cout << "Affiche width : " << resize.getXsize() << " affichage height : " << resize.getYsize() << std::endl;

	//resised.saveFile("resized_barbara_croped.bmp");
	//resised2.saveFile("resized_barbara_croped2.bmp");

	std::cout << "Affiche diff histo : " << Traitement::diffHisto(resised, tigreImage) << std::endl;
	
	return 0;
}