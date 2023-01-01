//Recovers deleted images
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include 
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    /*TODO
    1.Open memory card
    2.look for beginning of a JPEG
    3.Open a new JPEG file
    4.Write 512 bytes until a new JPEG is found
    Stop at the end of the file.
    */
//check for correct input 
    if (argc > 2) 
    {
        printf("Usage: ./recover IMAGE\n");
    }
    FILE *input = fopen(argv[1], "r");
    if (input == NULL) 
    {
        printf("could not open the file\n");
        return 1;
    }

    //read block of bytes
    BYTE buffer[512];  
    int counter = 0;
    int jpg_found = 0;
    char filename [8];
    FILE *output = NULL;
    while (fread(&buffer, sizeof(BYTE), 512, input))
    {
        //Check if block contains a JPEG, as JPEG files start with : 0xe0, 0xe1, 0xe2 
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0) 
        {  
            jpg_found = 1;
            if (output != NULL) 
            {
                fclose(output);
            }
            sprintf(filename, "%03i.jpg", counter);
            output = fopen(filename, "w");
            counter++;
        }
        if (jpg_found) 
        {
            fwrite(&buffer, sizeof(BYTE), 512, output);
        }
    }
    fclose(input);
    fclose(output);
    return 0;
}
 