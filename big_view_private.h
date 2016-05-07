#ifndef _BIG_VIEW_PRIVATE_H_
#define _BIG_VIEW_PRIVATE_H_

long calculateFontSize(const char* inString, long availSpace);
void renderSpace(long numSpaces, long* screenCol);
void renderCharacterRow(char inChar, long* screenCol, long fontRow,
		long fontSize);

#endif
