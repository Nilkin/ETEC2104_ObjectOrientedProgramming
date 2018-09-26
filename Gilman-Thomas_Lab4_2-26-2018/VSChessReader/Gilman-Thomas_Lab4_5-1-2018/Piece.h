#include <SDL.h>
#include <SDL_image.h>
#pragma once
class Piece
{
public:
	Piece(int r, int c, SDL_Renderer* renderer, const char* imgPATH);
	SDL_Texture* Draw();
	void Move(int newRow, int newCol);
	int getRow();
	int getCol();
	~Piece();
private:
	int row, col;
	SDL_Surface *image;
	SDL_Texture *imageTexture;
};

