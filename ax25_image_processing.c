#include "ax25_image_processing.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned char* get_image_binary(char *location) {

    //Input file
    FILE *inFile;

    //Total file size
    unsigned long int fileSize;


    //Pointer to buffer
    unsigned char *buffer;


    inFile = fopen(location, "rb");

    //Check to see file was opened successfully, otherwise terminate.
    if(inFile == NULL){
        printf("ERROR! Could not open file!");
        return (unsigned char *)1;
    }

    //Get file size (length in bytes).
    fseek(inFile, 0, SEEK_END);
    fileSize = ftell(inFile);
    fseek(inFile, 0, SEEK_SET);

    //Create an input (/output) buffer the size of the file.
    buffer = (unsigned char *)malloc(fileSize);


    //Read input file and store in buffer.
    //After this we are done with the file and can close it.
    fread(buffer, fileSize, sizeof(unsigned char), inFile);
    fclose(inFile);



    return buffer;
}


unsigned int get_image_size(char *location) {

    FILE *inFile;

    size_t fileSize;

    inFile = fopen(location, "rb");

    //Check to see file was opened successfully, otherwise terminate.
    if(inFile == NULL){
        printf("ERROR! Could not open file!");
        return 1;
    }

    fseek(inFile, 0, SEEK_END);
    fileSize = ftell(inFile);
    fseek(inFile, 0, SEEK_SET);
    fclose(inFile);
    return fileSize;
}


int save_to_image(char *location, unsigned int image_size, unsigned char *input){

    if (image_size <= 4) return 1;

    FILE *outFile;

    outFile = fopen(location, "wb");

    if (outFile==NULL){
        printf("\n\n ERROR CREATING OUTPUT FILE.");
        return 1;
    }


    //printf((int)size);

    //Write contents of buffer to file and close the file.
    fwrite(input, image_size, sizeof(unsigned char), outFile);
    fclose(outFile);

    return 0;

}

