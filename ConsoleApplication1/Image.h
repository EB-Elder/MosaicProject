#pragma once
#include <string>
#include "../lib/CImg-2.8.3/CImg.h"
#include <iostream> 
#include <vector> // for 2D vector 
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
		void saveFile(const char* const filename);
		int getPixel (int posX, int posY, int canalRGB);
		void setPixel (int posX, int posY, int canalRGB, int value);

		int getXsize() const;
		int getYsize() const;
		vector<vector<int>> getHisto() const;
		void refreshHisto(int sensibilite);
		
};

