#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*  TODO:   1. Put functions in separate header and C file
 *          2. Create documentation for them.
 *
 *          (No particular order for these.)
 */

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
        return (char *)1;
    }

    //Get file size (length in bytes).
    fseek(inFile, 0, SEEK_END);
    fileSize = ftell(inFile);
    fseek(inFile, 0, SEEK_SET);

    //Create an input (/output) buffer the size of the file.
    buffer = (char *)malloc(fileSize);

    unsigned char static_buffer[fileSize];

    //Read input file and store in buffer.
    //After this we are done with the file and can close it.
    fread(buffer, fileSize, sizeof(unsigned char), inFile);
    fclose(inFile);



    return buffer;
}

size_t get_image_size(char *location) {

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



int save_to_image(char *location, size_t size, unsigned char *input){
    FILE *outFile;

    outFile = fopen(location, "wb");

    if(outFile==NULL){
        printf("\n\n ERROR CREATING OUTPUT FILE.");
        return 1;
    }


    //printf((int)size);

    //Write contents of buffer to file and close the file.
    fwrite(input, size, sizeof(unsigned char), outFile);
    fclose(outFile);

    return 0;

}


int main(){

    int size = get_image_size("testImage.jpg");
    char* buf = get_image_binary("testImage.jpg");

    save_to_image("testOutput1.jpg", size, buf);

    /*
    //Input and output files
    FILE *inFile, *outFile,
    *outBinary;

    //Total file size
    unsigned long int fileSize;


    //Pointer to buffer
    unsigned char *buff;
    int i = 0;



    //strcat("dogSample800600.jpg", extension);

    inFile = fopen("dogSample800600.jpg", "rb");

    //Check to see file was opened successfully, otherwise terminate.
    if(inFile == NULL){
        printf("ERROR! Could not open file!");
        return 1;
    }

    //Get file size (length in bytes).
    fseek(inFile, 0, SEEK_END);
    fileSize = ftell(inFile);
    fseek(inFile, 0, SEEK_SET);

    //Create an input (/output) buffer the size of the file.
    buff = (char *)malloc(fileSize);

    //Read input file and store in buffer.
    //After this we are done with the file and can close it.
    fread(buff, fileSize, sizeof(unsigned char), inFile);
    fclose(inFile);

    printf("buff size is %d \n", sizeof(buff));
    //printf("%d", fileSize);



    printf("FILE SIZE IS %d", fileSize);
    //while(i<fileSize){
    //    printf("%02x ",buff[i]);
    //    i++;
    //    if(!(i % 16)) {
    //        printf( "\n" );
    //    }
    //}



    save_to_image("outputImageFile.jpg", fileSize, buff);


    //s
    outBinary = fopen("readwrite/textOutput.txt", "wb");
    if(outBinary == NULL){
        printf("\nERROR CREATING OUTPUT BINARY\nTERMINATING PROGRAM...");
        return 1;
    }

    char *out = (char *)malloc(3 * sizeof(char));
    for(int n=0; n<fileSize; n++){
        sprintf(out, "%02x ", buff[n]);
        fputs(out, outBinary);
    }

    //fwrite(buff, fileSize, sizeof(unsigned char), outBinary);
    fclose(outBinary);


    */

    return 0;
}
