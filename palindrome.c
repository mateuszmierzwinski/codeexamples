/*
Copyright 2022 Mateusz Mierzwinski

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

// BOOLs support
#define TRUE 0
#define FALSE 1

// Magic numbers
#define MIN_ARGS_ACCEPTED 2
#define APPNAME_POSITION_IN_ARGV 0

// Formatting strings
#define HELPTEXT "Usage: %s <string> <string> ... <string>\n"
#define FMT_OUTPUT_TEXT "Given \"%s\": %s\n"

// Imports
#include <stdio.h>
#include <string.h>

// is_palindrome checks if given string is palindrome (returns TRUE) or not (returns FALSE)
int is_palindrome(char *string) {
    int strLen = strlen(string)-1;

    for (int i=0; i<strLen/2; i++) {
        if (string[i] != string[strLen-i]) {
            return FALSE;
        }
    }

    return TRUE;
}

// help is a function that shows help message in the console
void help(char *appName) {
    printf(HELPTEXT, appName);
}

// main function of the app
int main(int argc, char *argv[]) {

    if (argc < MIN_ARGS_ACCEPTED) {
        help(argv[APPNAME_POSITION_IN_ARGV]);
        return FALSE;
    }

    for (int i=1; i<argc; i++) {
        printf(FMT_OUTPUT_TEXT,
            argv[i],
            is_palindrome(argv[i]) == TRUE ? "palindrome" : "not a palindrome"
        );
    }

    return TRUE;
}
