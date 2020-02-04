#include "Traitement.h"

Traitement::Traitement(){
	
}

void Traitement::croping(Image& To, Image& From, int startX, int startY, int length, int height) {

	int i = 0;
	int j = 0;
	for (int x = startX; x < startX + length; x++)
	{
		for (int y = startY; y < startY + length; y++)
		{
			To.setPixel(i, j, 0, From.getPixel(x, y, 0));
			To.setPixel(i, j, 1, From.getPixel(x, y, 1));
			To.setPixel(i, j, 2, From.getPixel(x, y, 2));
			
			j++;
			
		}
		j = 0;
		i++;
	}

	To.refreshHisto();
	
	

}

int Traitement::diffVal(Image& image1, Image& image2) {

	int compteur = 0;

	for (int i = 0; i < image1.getXsize(); i = i + 1) {

		for (int y = 0; y < image1.getYsize(); y = y + 1) {

			if (image1.getPixel(i, y, 0) != image2.getPixel(i, y, 0) ||
				image1.getPixel(i, y, 1) != image2.getPixel(i, y, 1) ||
				image1.getPixel(i, y, 2) != image2.getPixel(i, y, 2)) 
			{

				compteur = compteur + 1;

			}

		}
	}

	return compteur;
}

int Traitement::diffHisto(Image& image1, Image& image2) {

	int compteur = 0;

	vector<vector<int>> histo1 = image1.getHisto();
	vector<vector<int>> histo2 = image2.getHisto();



		for (int y = 0; y < 16; y = y + 1) {

			compteur = compteur + abs(histo1[0][y] - histo2[0][y])
								+ abs(histo1[1][y] - histo2[1][y])
								+ abs(histo1[2][y] - histo2[2][y]);

		}

	return compteur;
}

void Traitement::resize(Image& to, Image& from) {


	float newSizeScaleX = float(to.getXsize()) / float(from.getXsize());
	float newSizeScaleY = float(to.getYsize()) / float(from.getYsize());

	for (int i = 0; i < to.getXsize(); i = i+1) {
		for (int y = 0; y < to.getYsize(); y = y+1) {

			int getpix0 = from.getPixel(i / newSizeScaleX, y / newSizeScaleY, 0);
			int getpix1 = from.getPixel(i / newSizeScaleX, y / newSizeScaleY, 1);
			int getpix2 = from.getPixel(i / newSizeScaleX, y / newSizeScaleY, 2);

			to.setPixel(i, y, 0, getpix0);
			to.setPixel(i, y, 1, getpix1);
			to.setPixel(i, y, 2, getpix2);

		}
	}

	to.refreshHisto();

}