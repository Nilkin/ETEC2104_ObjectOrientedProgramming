#include "stdafx.h"
#include "Piece.h"


Piece::Piece(int r, int c, SDL_Renderer* renderer, const char* imgPATH)
{
	if ((image = IMG_Load(imgPATH)) == NULL)
		printf("could not load Piece image: %s\n", IMG_GetError());
	row = r; col = c;
	if ((imageTexture = SDL_CreateTextureFromSurface(renderer, image)) == NULL)	//set ImageTexture
		printf("didnt convert image to texture");
	SDL_FreeSurface(image);
};
SDL_Texture* Piece::Draw()
{
	return imageTexture;
};
void Piece::Move(int newRow, int newCol)
{
	row = newRow;	col = newCol;
};
int Piece::getRow()
{
	return row;
};
int Piece::getCol()
{
	return col;
};
Piece::~Piece()
{
	SDL_DestroyTexture(imageTexture);
};
