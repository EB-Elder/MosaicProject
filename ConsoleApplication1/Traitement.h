#pragma once
#include "Image.h"

class Traitement
{
	public:
		Traitement();

		//fonction de crop
		static void croping(Image& To, Image& From, int startX, int startY, int length, int height);

		//fonction de comparaison de 2 images, compare chaque pixel les uns avec les autres et renvoie un int
		//plus le int est grand, plus les images sont différentes
		static int diffVal(Image& image1, Image& image2);

		//fonction de comparaison de 2 images, compare chaque bin des histogrammes des deux images pour les 3 canaux de couleur
		//plus le int est grand, plus les images sont différentes
		static int diffHisto(Image& image1, Image& image2);

		//fonction de resize
		static void resize(Image& to, Image& from);

		//remplie la liste d'Image passée en parametre avec l'image initiale découpée à la bonne taille en fonction du nombre de lignes et colonnes
		static void initPuzzleList(vector<Image>& puzzle, Image imageInitiale);

		//compare une Image à un dataset et retourne l'index de l'image du dataset qui correspond le plus à l'image passée en parametre
		static int bestMatch(vector<Image> dataSet, Image imageToTest);

		//prend en parametre le dataset et la liste d'image remplie par l'image initiale cropée.
		//compare chaque Image de la liste avec le dataset pour renvoyer une liste qui contient uniquement des images du dataset qui vont servire pour le patchwork
		static void initPatchworkList(vector<Image>& dataSet, vector<Image>& puzzleList, vector<Image>& patchWorkList);

		//dessine le patchwork par rapport aux images de la liste passée en parametre
		static void drawPatchwork(vector<Image>& patchworkList, Image patchwork);

		

};

