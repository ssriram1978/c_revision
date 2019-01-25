//
// Created by sriramsridhar on 1/25/19.
//

#include "file_operations.h"


void revise_file_operations(int argc, char *argv[])
{
    FILE *inp;
    int  chr;
    char line[128];
    unsigned char buffer[1024]; /* 1 kilobyte */
    int i, read;

    /* check if there is one argument */
    if(argc != 2) {
        printf("usage: show file_name\n");
        return;
    }

    /* check if we are able to open the input file */
    if((inp = fopen(argv[1],"rt")) == NULL) {
        printf("Cannot open the file %s\n", argv[1]);
        return;
    }

    /* we will try to read the file char by char and print the chars to screen */
    while((chr = fgetc(inp)) != EOF)
        printf("%c",chr);

    /* it's time to close the stream */
    fclose(inp);

    if((inp = fopen(argv[1],"rt")) == NULL) {
        printf("Cannot open the file %s\n", argv[1]);
        return;
    }
    while((fgets(line,sizeof(line),inp)) != NULL)
        printf("%s",line);
    fclose(inp);


    if((inp = fopen(argv[1],"rb")) == NULL) {
        printf("Cannot open the file %s\n", argv[1]);
        return;
    }
    do {
        read = fread(buffer,1,sizeof(buffer),inp);
        for(i = 0; i < read; i++)
            printf("%02X",buffer[i]);
    } while (read > 0);
    fclose(inp);
}