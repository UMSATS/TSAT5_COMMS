#ifndef AX25_IMAGE_PROCESSING_H
#define AX25_IMAGE_PROCESSING_H




unsigned char* get_image_binary(char *location);
//Returns location in memory that currently holds the image.

unsigned int get_image_size(char *location);

int save_to_image(char *location, unsigned int image_size, unsigned char *input);



#endif // AX25_IMAGE_PROCESSING_H
