#include "Image.h"

Image::~Image()
{
	//TODO
}

Image::Image() {
	img = CImg<unsigned char>(100, 100, 1, 3, 0);

	

	refreshHisto(100);

}

Image::Image(CImg<unsigned char> uneImg) {

	img = uneImg;

	

	refreshHisto(100);

}

Image::Image(const Image & copy)
{

	img = copy.img;


	refreshHisto(100);
}

Image::Image(int X, int Y) {
	
	img = CImg<unsigned char>(X, Y, 1, 3, 0);

	

	refreshHisto(100);
}

Image::Image(const char* const filename) {
	
	img = CImg<unsigned char>(filename);

	

	refreshHisto(100);
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

int Image::getXsize() const {

	return img.width();

}

int Image::getYsize() const {

	return img.height();

}

vector<vector<int>> Image::getHisto() const {

	return histo;

}

void Image::refreshHisto(int sensibilite) {

	histo.resize(3, std::vector<int>(sensibilite, 0));

	for (int i = 0; i < 25; i = i + 1) {

		histo[0][i] = 0;
		histo[1][i] = 0;
		histo[2][i] = 0;

	}

	for (int i = 0; i < getXsize(); i = i + 1) {

		for (int y = 0; y < getYsize(); y = y + 1) {

			histo[0][getPixel(i, y, 0) / sensibilite] = histo[0][getPixel(i, y, 0) / sensibilite] + 1;
			histo[1][getPixel(i, y, 1) / sensibilite] = histo[0][getPixel(i, y, 1) / sensibilite] + 1;
			histo[2][getPixel(i, y, 2) / sensibilite] = histo[0][getPixel(i, y, 2) / sensibilite] + 1;


		}

	}

}