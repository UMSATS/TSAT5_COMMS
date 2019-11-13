#include "ax25_image_processing.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned char* get_image_binary(char *location) {
    /*
     * get_image_binary - Returns an area in memory which holds the entire image binary.
     * 
     * INPUT: (String)location - file path to image location.
     */ 

    //Input file
    FILE *input_file;

    //Total file size
    unsigned long int file_size;


    //Pointer to buffer which will store image binary
    unsigned char *buffer;

    //Open file. "rb" = binary read mode
    input_file = fopen(location, "rb");

    //Check to see file was opened successfully, otherwise terminate.
    if(input_file == NULL){
        printf("ERROR! Could not open file!");
        return NULL;
    }

    //Get file size (length in bytes).
    fseek(input_file, 0, SEEK_END);
    file_size = ftell(input_file);
    fseek(input_file, 0, SEEK_SET);

    //Create an input (/output) buffer the size of the file.
    buffer = (char *)malloc(file_size);


    //Read input file and store in buffer.
    //After this we are done with the file and can close it.
    fread(buffer, file_size, sizeof(unsigned char), input_file);
    fclose(input_file);



    return buffer;
}


unsigned int get_image_size(char *location) {
    /*
     * get_image_size - returns the file size of the image.
     * 
     * INPUTS: (String)location - file path to image location.
     */
    

    FILE *input_file;

    unsigned int file_size;

    input_file = fopen(location, "rb");

    //Check to see file was opened successfully, otherwise terminate.
    if(input_file == NULL){
        printf("ERROR! Could not open file!\n");
        return 1;
    }

    //Place pointer at end of file, set file_size, reset pointer.
    fseek(input_file, 0, SEEK_END);
    file_size = ftell(input_file);
    fseek(input_file, 0, SEEK_SET);

    //Close file once done.
    fclose(input_file);
    return file_size;
}


int save_to_image(char *location, unsigned int image_size, unsigned char *input){
    /*
     * save_to_image - Saves image file from binary input to specific location.
     * 
     * INPUTS:  (String)location            - file path to image location.
     *          (unsigned int)image_size    - Total size of the image
     *          (unsigned char *)input      - Binary input.
     */

    //Output file
    FILE *output_file;

    output_file = fopen(location, "wb");

    //End program if opening file failed.
    if(output_file==NULL){
        printf("ERROR CREATING OUTPUT FILE.\n");
        return 1;
    }

    //Write contents of buffer to file and close the file.
    fwrite(input, image_size, sizeof(unsigned char), output_file);
    fclose(output_file);

    return 0;

}

