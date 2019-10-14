#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <ctype.h>

#include "bmp.h"


int main(int argc, char *argv[]){

    if(argc != 4){
        printf("You entered the wrong command. Format: ./resize n sourseFile outFile\n");
        return 1;
    }

    int n = atoi(argv[1]);
    if( (n >= 100) || (n <= 0) ){
        printf("number must be in range from 0 to 100\n");
        return 2;
    }
/////////////////////////////////////////////////////////////////////////

    // remember filenames
    char* infile = argv[2];
    char* outfile = argv[3];

    FILE *sourceFile = fopen(infile, "r");      //open file on the read
    if(sourceFile == NULL){                      //check, exsist file?
        printf("file %s not found.\n", infile);
        return 3;
    }
    FILE *newFile = fopen(outfile, "w");      //open file on the write
    if(newFile == NULL){                      //check, exsist file?
        printf("file %s is not created.\n", outfile);
        fclose(sourceFile);
        return 4;
    }

    //read 2 struct file.
    BITMAPFILEHEADER bfile;
    fread(&bfile, sizeof(BITMAPFILEHEADER), 1, sourceFile);
    BITMAPINFOHEADER binf;
    fread(&binf, sizeof(BITMAPINFOHEADER), 1, sourceFile);


    /*// ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bfile.bfType != 0x4d42 || bfile.bfOffBits != 54 || binf.biSize != 40 ||
        binf.biBitCount != 24 || binf.biCompression != 0)
    {
        fclose(newFile);
        fclose(sourceFile);
        printf("Unsupported file format.\n");
        return 5;
    }*/

    //save biWidth and biHeight image from source file
    int sWidth = binf.biWidth;
    int sHeight = abs(binf.biHeight);

    //calculate padding for source image
    int spadding =  (4 - (binf.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;   //я тупой

    //change struct for new resize file
    binf.biWidth *= n;
    binf.biHeight *= n;


    //calculate padding for new image
    int new_padding = (4 - (binf.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    binf.biSizeImage =  (binf.biWidth * sizeof(RGBTRIPLE) + new_padding) * abs(binf.biHeight);    //размер picture
    bfile.bfSize = binf.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);       //размер file

    fwrite(&bfile, sizeof(BITMAPFILEHEADER), 1, newFile);
    fwrite(&binf, sizeof(BITMAPINFOHEADER), 1, newFile);

    for(int y1 = 0; y1 < sHeight; y1++){

        for(int c = 0; c < n; c++){

            for(int x1 = 0; x1 < sWidth; x1++ ){
                RGBTRIPLE triple;
                fread(&triple, sizeof(RGBTRIPLE), 1, sourceFile);

                //write pixel n time
                for(int i = 0; i < n; i++){
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, newFile);
                }
            }
            // skip over padding, if any
            fseek(sourceFile, spadding, SEEK_CUR);
            // then add it back (to demonstrate how)
            for (int k = 0; k < new_padding; k++)
            {
                fputc(0x00, newFile);
            }

            if(c < (n - 1)){
                int offset = sWidth * sizeof(RGBTRIPLE) + spadding;
                fseek(sourceFile, -offset, SEEK_CUR);
            }
        }
    }



    fclose (sourceFile);
    fclose (newFile);
    return 0;
}