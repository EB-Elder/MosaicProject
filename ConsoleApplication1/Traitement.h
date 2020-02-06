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
		static void initPuzzleList(vector<Image>& puzzle, Image imageInitiale);
		static int bestMatch(vector<Image> dataSet, Image imageToTest);
		static void initPatchworkList(vector<Image>& dataSet, vector<Image>& puzzleList, vector<Image>& patchWorkList);
		static void drawPatchwork(vector<Image>& patchworkList, Image patchwork);

		

};

