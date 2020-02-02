#pragma once
#include <string>
#include "../lib/CImg-2.8.3/CImg.h"

using namespace cimg_library;

class Image
{
	private:
		CImg<unsigned char> img;

	public:
		~Image();
		Image();
		Image(const Image &copy);
		Image(int X, int Y);
		Image(const char* const filename);
		Image operator= (const Image &image);
		void saveFile(const char* const filename);
		int getPixel (int posX, int posY, int canalRGB);
		void setPixel (int posX, int posY, int canalRGB, int value);
		
};

