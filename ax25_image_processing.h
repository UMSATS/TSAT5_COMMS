#ifndef AX25_IMAGE_PROCESSING_H
#define AX25_IMAGE_PROCESSING_H



//Returns location in memory that currently holds the image.
unsigned char* get_image_binary(char *location);


//Returns the size of the specified image
unsigned int get_image_size(char *location);


//Given the binary of the image, saves the output of the image to a specified location and file name.
int save_to_image(char *location, unsigned int image_size, unsigned char *input);

#endif // AX25_IMAGE_PROCESSING_H
