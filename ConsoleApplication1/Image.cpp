#include "Image.h"

Image::~Image()
{
	//TODO
}

Image::Image() {
	img = CImg<unsigned char>(100, 100, 1, 3, 0);
}

Image::Image(const Image & copy)
{
	//TODO
	img = CImg<unsigned char>(100, 100, 1, 3, 0);
}

Image::Image(int X, int Y) {
	
	img = CImg<unsigned char>(X, Y, 1, 3, 0);
}

Image::Image(const char* const filename) {
	
	img = CImg<unsigned char>(filename);
}

Image Image::operator=(const Image & image)
{
	//TODO
	return Image();
}

void Image::saveFile(const char* filename)
{
	img.save(filename);
}

int Image::getPixel (int posX, int posY, int canalRGB){

	return img(posX, posY, canalRGB);
}

void Image::setPixel (int posX, int posY, int canalRGB, int value){

	img(posX, posY, canalRGB) = value;
}