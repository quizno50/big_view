#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "big_view.h"

/*******************************************************************************
 * main
 *******************************************************************************
 * @desc This function kicks off the program. Starts by parsing arguments that
 * are passed in. The arguments that we understand are:
 *  -t - This is an argument that specifies the litteral text to render. If you
 *       specify a filename, the contents of the file will overwrite what you
 *       specify here.
 *  -f - This specifies a file that you want to read the contents from and
 *       render to the screen.
 *  -k - This allows you to specify the kern value. This is the number of
 *       characters in between each letter.
 *  -l - This allows you to specify the left value. This is how many characters
 *       to indent the rendered string.
 * @param argc Standard main argument count.
 * @param argv Standard main argument vector.
 ******************************************************************************/
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

