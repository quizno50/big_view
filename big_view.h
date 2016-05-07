#ifndef _BIG_VIEW_H_
#define _BIG_VIEW_H_

/*******************************************************************************
 * renderString
 *******************************************************************************
 * @desc Render a string to the console. This will autodetect the size of the
 * font needed to fit to a standard 80 column display.
 * @param left Specify how many characters to indent the text to render.
 * @param kern Specify how many characters to put in between each letter.
 * @return void
 ******************************************************************************/
void renderString(const char* inString, long left, long kern);

#endif
