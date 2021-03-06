// VSChessReader.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Piece.h"
#include "PGN.h"

#include <iostream>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>


#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800

//SDL Variables
SDL_Window *window;
SDL_Renderer *renderer;
SDL_Event sysEvent;

//WHITE CHESS PIECE IMAGES
const char* wPawnImgPATH = "..\\Resources\\wPawn.png";
const char* wRookImgPATH = "..\\Resources\\wRook.png";
const char* wKnightImgPATH = "..\\Resources\\wKnight.png";
const char* wBishopImgPATH = "..\\Resources\\wBishop.png";
const char* wQueenImgPATH = "..\\Resources\\wQueen.png";
const char* wKingImgPATH = "..\\Resources\\wKing.png";
//BLACK CHESS PIECE IMAGES
const char* bPawnImgPATH = "..\\Resources\\bPawn.png";
const char* bRookImgPATH = "..\\Resources\\bRook.png";
const char* bKnightImgPATH = "..\\Resources\\bKnight.png";
const char* bBishopImgPATH = "..\\Resources\\bBishop.png";
const char* bQueenImgPATH = "..\\Resources\\bQueen.png";
const char* bKingImgPATH = "..\\Resources\\bKing.png";
//PGN txt FILE
const char* gameTextFilePATH = "..\\Resources\\AmedeeGibaudvsFredericLazard.txt";

//Piece array
std::vector<Piece> boardPieces;

int main(int argc, char * argv[])
{
	//initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
			"SDL not initialized. SDL_ERROR : %s\n", SDL_GetError());
		SDL_Delay(5000);
		exit(-1);
	}
	if ((window = SDL_CreateWindow("ChessReader", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, NULL)) == NULL)
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
			"Window not created: %s\n", SDL_GetError());
		SDL_Delay(5000);
		exit(-1);
	}
	if ((renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED)) == NULL)
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
			"Renderer not created: %s\n", SDL_GetError());
		SDL_Delay(5000);
		exit(-1);
	}
	int flags = IMG_INIT_JPG | IMG_INIT_PNG;
	int initted = IMG_Init(flags);
	if ((initted&flags) != flags)
	{
		printf("IMG_Init failed :%s\n", IMG_GetError());
		exit(-1);
	}
		
	//initialize array of Pieces
	for (int rowSwap = 0; rowSwap < 2; rowSwap++)
	{
		if (rowSwap == 0)	// whitePieces
		{
			for (int col = 1; col < 9; col++)
				boardPieces.push_back(Piece(2, col, renderer, wPawnImgPATH));
			boardPieces.push_back(Piece(1, 1, renderer, wRookImgPATH));
			boardPieces.push_back(Piece(1, 8, renderer, wRookImgPATH));
			boardPieces.push_back(Piece(1, 2, renderer, wKnightImgPATH));
			boardPieces.push_back(Piece(1, 7, renderer, wKnightImgPATH));
			boardPieces.push_back(Piece(1, 3, renderer, wBishopImgPATH));
			boardPieces.push_back(Piece(1, 6, renderer, wBishopImgPATH));
			boardPieces.push_back(Piece(1, 4, renderer, wKingImgPATH));
			boardPieces.push_back(Piece(1, 5, renderer, wQueenImgPATH));
		}
		else				// blackPieces
		{
			for (int col = 1; col < 9; col++)
				boardPieces.push_back(Piece(7, col, renderer, bPawnImgPATH));
			boardPieces.push_back(Piece(8, 1, renderer, bRookImgPATH));
			boardPieces.push_back(Piece(8, 8, renderer, bRookImgPATH));
			boardPieces.push_back(Piece(8, 2, renderer, bKnightImgPATH));
			boardPieces.push_back(Piece(8, 7, renderer, bKnightImgPATH));
			boardPieces.push_back(Piece(8, 3, renderer, bBishopImgPATH));
			boardPieces.push_back(Piece(8, 4, renderer, bBishopImgPATH));
			boardPieces.push_back(Piece(8, 4, renderer, bKingImgPATH));
			boardPieces.push_back(Piece(8, 5, renderer, bQueenImgPATH));
		}
	}
	//PGN file to load
	PGN gameFile = PGN(gameTextFilePATH);
	
	int drawingGameState = 1;
	while (drawingGameState)
	{
		//Update Screen with Board state
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderClear(renderer);

		for (int row = 0; row < 8; row++)
		{
			for (int col = 0; col < 8; col++)
			{
				SDL_Rect Tile;
				Tile.x = col*100;	Tile.y = row*100;	
				Tile.w = (col + 1)*100;		Tile.h = (row + 1)*100;
				
				if ((col % 2 == 1 && row % 2 == 1) || (col % 2 == 0 && row % 2 == 0))	//white tiles
					SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
				else																	//black tiles
					SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

				SDL_RenderFillRect(renderer, &Tile);
				SDL_RenderDrawRect(renderer, &Tile);
				for (int pieceIndex = 0; pieceIndex < boardPieces.size()-1; pieceIndex++)
				{
					if ((col + 1 == boardPieces[pieceIndex].getCol()) && (row + 1 == boardPieces[pieceIndex].getRow()))
					{
						SDL_RenderCopy(renderer, boardPieces[pieceIndex].Draw(), NULL, &Tile);								//draw the piece
					}
				}
			}
		}
		SDL_RenderPresent(renderer);

		if (SDL_PollEvent(&sysEvent))
		{
			switch (sysEvent.type)
			{
			case SDL_QUIT:							//EXIT
				drawingGameState = 0;
				break;

			case SDL_KEYDOWN:
				switch (sysEvent.key.keysym.sym)
				{
				case SDLK_ESCAPE:					//EXIT
					drawingGameState = 0;
					break;

				case SDLK_SPACE:					//NEXT MOVE
					if (gameFile.getIndex() < gameFile.getVectorSize())
					{
						std::string move = gameFile.getMove();
						int curRow = (move.at(0) - '0'), rowTo(move.at(3) - '0');
						int curCol = 9 - (move.at(1) - '0'), colTo = 9 - (move.at(4) - '0');

						for (std::vector<Piece>::iterator iter = boardPieces.begin(); iter < boardPieces.end(); iter++)
						{
							if ((iter->getRow() == rowTo) && (iter->getCol() == colTo))
							{
								boardPieces.erase(iter); break;
							}
							if ((iter->getRow() == curRow) && (iter->getCol() == curCol))
							{
								iter->Move(rowTo, colTo); break;
							}
						}
						printf("Piece at Row:%d Col:%d to Row:%d Col:%d\n", curRow, curCol, rowTo, colTo);
					}
					break;

				case SDLK_p:
					int pause = 1;
					while (pause)
					{
						SDL_PollEvent(&sysEvent);
						switch (sysEvent.type)
						{
						case SDL_KEYDOWN:
							switch (sysEvent.key.keysym.sym)
							{
							case SDLK_p:
								pause = 0;
								break;
							}
							break;
						}
					}
					break;
				}
				break;
			}
		}
	}
	//EXIT
	boardPieces.clear();			//cleanUp Vector memory allocated
	SDL_DestroyRenderer(renderer);	//free renderer
	SDL_DestroyWindow(window);		//free window memory
	IMG_Quit();
	SDL_Quit();						//clean up SDL
    return 0;
}

