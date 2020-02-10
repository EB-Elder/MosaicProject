#pragma once
#include <string>
#include "../lib/CImg-2.8.3/CImg.h"
#include <iostream> 
#include <vector> // for 2D vector
#define PRECISION 100
using namespace std;

using namespace cimg_library;

class Image
{
	private:
		CImg<unsigned char> img;
		vector<vector<int>> histo;


	public:
		~Image();
		Image();
		Image(const Image &copy);
		Image(int X, int Y);
		Image(const char* const filename);
		Image(CImg<unsigned char> uneImg);
		Image operator= (const Image &image);

		//permet de sauvegarder une image sur le pc
		void saveFile(const char* const filename);


		int getPixel (int posX, int posY, int canalRGB);
		void setPixel (int posX, int posY, int canalRGB, int value);

		//renvoi la width
		int getXsize() const;

		//renvoi la height
		int getYsize() const;

		//renvoie l'histogramme de l'image dans un tableau en 2D
		vector<vector<int>> getHisto() const;

		// refresh l'hisogramme en le comparant à l'attribut Cimg de la classe
		void refreshHisto(int sensibilite);
		
};

