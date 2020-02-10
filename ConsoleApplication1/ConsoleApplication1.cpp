// ConsoleApplication1.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
#include <iostream>
#include <string>
#include "../lib/CImg-2.8.3/CImg.h"
#include "Traitement.h"
#include "Image.h"
#include <iostream> 
#include <vector>
#include <math.h>


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


//fonction permettant de créer un dataset et de l'enregistrer dans une liste d'Image
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
				dataSet[i].refreshHisto(PRECISION);
				
				i++;
			}
		}
	}

}



int main() {


	//Image de base que l'on veut traiter
	Image InitialImage("unknown.bmp");

	//nb de ligne et de colonnes
	int ligne = 150;
	int colonne = 150;

	//Création du dataset et découpage des images du dataset à la taille adéquate
	vector<Image> dataSet(64, Image(ceil(float(InitialImage.getXsize()) / colonne), ceil(float(InitialImage.getYsize()) / ligne)));
	initDataSetList(dataSet, ceil(InitialImage.getXsize() / float(colonne)), ceil(InitialImage.getYsize() / float(ligne)));


	//Création de la liste qui va contenir les images cropée et redimensionnée de l'image initiale 
	vector<Image> PuzzleImageInitiale(ligne*colonne, Image(ceil(InitialImage.getXsize()/float(colonne)), ceil(InitialImage.getYsize()/float(ligne))));
	Traitement::initPuzzleList(PuzzleImageInitiale, InitialImage);

	//Création de la liste contenant les images du patchwork. Chaque portion provient du patchwork. Les image sont de bonnes dimensions
	//à partir de là il ne reste plus qu'à assembler le tout dans une seule image pour avoir notre patchwork.
	vector<Image> patchworkList(ligne * colonne, Image(ceil(InitialImage.getXsize() / float(colonne)), ceil(InitialImage.getYsize() / float(ligne))));
	Traitement::initPatchworkList(dataSet, PuzzleImageInitiale, patchworkList);


	//Création du patchwork
	//assemblage des images de la liste 
	Traitement::drawPatchwork(patchworkList, InitialImage);

	
	
	return 0;
}