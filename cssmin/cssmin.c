/**
 * cssmin - Cascading Style Sheets Minifier
 * @using: cssmin < file.css > file_2.css
 * @author Sokolov Innokenty
 * @copyright (c) 2010, qbbr
 */

#include <stdlib.h>
#include <stdio.h>

static void
cssmin()
{
	int ch1 = '\n', ch2;
	int skip = 0;
	do {
		ch2 = getc(stdin);
		
		if (ch2 == '\r') ch2 == '\n';

		if ( ch1 == '\n'
			|| ch1 == '\t'
			|| (ch1 == ' ' && ch2 == '{')
			|| (ch1 == ' ' && ch2 == ' ')
			|| (ch1 == ';' && ch2 == '}') ) {
			ch1 = ch2;
			continue;
		} else if ( (ch1 == ':' && ch2 == ' ')
			|| (ch1 == '{' && ch2 == ' ')
			|| (ch1 == '{' && ch2 == '\n')
			|| (ch1 == ';' && ch2 == '\n')
			|| (ch1 == ';' && ch2 == ' ')
			|| (ch1 == ',' && ch2 == ' ') ) {
			continue;
		}

		if (ch1 == '/' && ch2 == '*') {
			skip = -1;
		} else if (ch1 == '*' && ch2 == '/') {
			skip = 2;
		}

		if (skip == 0) putc(ch1, stdout);
		else skip--;
		ch1 = ch2;
	} while (ch1 != EOF);
}

extern int
main(int argc, char* argv[])
{
	cssmin();
	return 0;
}
