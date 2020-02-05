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

void initDataSetList(vector<Image>& dataSet, int sizeX, int sizeY) {


	int i = 0;
	for (int r = 0; r <= 255; r += 75)
	{
		for (int g = 0; g <= 255; g += 75)
		{
			for (int b = 0; b <= 255; b += 75)
			{
				for (int x = 0; x < sizeX; x++)
				{
					for (int y = 0; y < sizeY; y++)
					{
						dataSet[i].setPixel(x, y, 0, r);
						dataSet[i].setPixel(x, y, 1, g);
						dataSet[i].setPixel(x, y, 2, b);

					}
				}

				std::string tmp = "./images/dataSet" + std::to_string(i) + ".bmp";
				dataSet[i].saveFile(tmp.c_str());
				dataSet[i].refreshHisto();
				
				i++;
			}
		}
	}

}



int main() {


	//Image que l'on veut traiter
	Image InitialImage("resized_barbara_croped.bmp");

	//nb de ligne et de colonnes
	int ligne = 9;
	int colonne = 6;

	//Création du dataset
	vector<Image> dataSet(64, Image(InitialImage.getXsize() / ligne, InitialImage.getYsize() / colonne));
	initDataSetList(dataSet, InitialImage.getXsize() / ligne, InitialImage.getYsize() / colonne);

	//Création de la liste qui va contenir les images cropée et redimensionnée de l'image initiale 
	vector<Image> PuzzleImageInitiale(ligne*colonne, Image(InitialImage.getXsize()/ligne, InitialImage.getYsize()/colonne));
	Traitement::initPuzzleList(PuzzleImageInitiale, InitialImage);

	/*for (int i = 0; i < dataSet.size(); i = i + 1) {
		dataSet[i].refreshHisto();
	}

	for (int i = 0; i < PuzzleImageInitiale.size(); i = i + 1) {

		PuzzleImageInitiale[i].refreshHisto();

	}*/



	
	/*Image InitialImage("resized_barbara_croped.bmp");
	Image tigreImage("resized_barbara_croped.bmp");
	Image resised(500, 500);
	Traitement::resize(resised, InitialImage);



	Image tst2(InitialImage.getXsize(), InitialImage.getYsize());
	

	std::cout << "Affiche width : " << resize.getXsize() << " affichage height : " << resize.getYsize() << std::endl;

	resised.saveFile("resized_barbara_croped.bmp");
	resised2.saveFile("resized_barbara_croped2.bmp");*/

	Traitement::bestMatch(dataSet, PuzzleImageInitiale[27]);
	
	return 0;
}