#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "SDL/SDL_gfxPrimitives_font.h"

long calculateFontSize(const char* inString, long availSpace);
void renderString(const char* inString, long left, long kern);
void renderSpace(long numSpaces, long* screenCol);
void renderCharacterRow(char inChar, long* screenCol, long fontRow,
		long fontSize);

long calculateFontSize(const char* inString, long availSpace)
{
	long inStrLen = strlen(inString);
	if (inStrLen * 8 > availSpace) return 1;
	else return availSpace / (inStrLen * 8);
}

void renderString(const char* inString, long left, long kern)
{
	long fontRow = 0, fontCol = 0;
	long chIdx = 0, screenRow = 0, screenCol = 0;
	long inStrLen = strlen(inString);
	long fontSize = calculateFontSize(inString, 80);

	for (screenRow = 0; screenRow < 8 * fontSize; ++screenRow)
	{
		chIdx = 0;
		renderSpace(left, &screenCol);
		fontRow = screenRow / fontSize;
		while (chIdx < inStrLen)
		{
			renderCharacterRow(inString[chIdx], &screenCol, fontRow, fontSize);
			renderSpace(kern, &screenCol);
			++chIdx;
		}
		++screenCol;
		printf("\n");
	}
}

void renderSpace(long numSpaces, long* screenCol)
{
	for (; numSpaces > 0; --numSpaces)
	{
		printf(" ");
		++(*screenCol);
	}
}

void renderCharacterRow(char inChar, long* screenCol, long fontRow,
		long fontSize)
{
	long startCol, insertedChars = 0, fontCol = 0;
	unsigned char fontRowData = gfxPrimitivesFontdata[inChar * 8l + fontRow];


	for (startCol = fontCol; fontCol < startCol + 8; ++(fontCol))
	{
		char targetChar = ((fontRowData << fontCol) & 0x80) == 0 ? ' ' : inChar;
		if (targetChar == '\n' || targetChar == '\t' || targetChar == '\r')
				targetChar = ' ';
		for (insertedChars = 0; insertedChars < fontSize; ++insertedChars)
		{
			printf("%c", targetChar);
			++(*screenCol);
		}
	}
}

int main(int argc, char** argv)
{
	int arg = 1;
	char* filename = NULL;
	char* text = calloc(sizeof(char), 100);
	long kern = 1;
	long left = 0;
	FILE* f = NULL;

	for (arg = 1; arg < argc; ++arg)
	{
		if (argv[arg][0] == '-')
		{
			switch (argv[arg][1])
			{
				case 'f':
					filename = argv[++arg];
					break;
				case 'k':
					kern = atol(argv[++arg]);
					break;
				case 'l':
					left = atol(argv[++arg]);
					break;
				case 't':
					strcpy(text, argv[++arg]);
					break;
				default:
					fprintf(stderr, "Unknown option: %c\n", argv[arg][1]);
			}
		}
	}

	if (filename)
	{
		f = fopen(filename, "r");
	}

	if (f)
	{
		fread((void*)text, sizeof(char), 100, f);
		fclose(f);
	}
	
	renderString(text, left, kern);

	return 0;
}
