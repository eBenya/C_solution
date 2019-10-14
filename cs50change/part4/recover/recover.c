/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */

#include <stdint.h>
#include <stdio.h>


typedef uint8_t  BYTE;

int main(int argc, char* argv[])
{
    if(argc != 2){
        printf("Write once parametr.\n");
        return 1;
    }

    //remember file name
    char* file = argv[1];

    //open file card with picture
    FILE *badFile = fopen(file, "r");
    if(badFile == NULL){
        printf("Could not open file %s .\n", file);
        return 2;
    }

    uint8_t buff[4] = {0};

    int i = 0;
    char  nameJPG[8] = {0};

   //цикл прохода по памяти карты
   while(fread(&buff, 1, 4, badFile) != 0){
        //create struct in which we be read

        //fread(&buff, 1, 4, badFile);
        buff[3] = buff[3] >> 4;

        //if finde jpeg file, then create picture file and save him.
        if( (buff[0] == 0xff) &&
            (buff[1] == 0xd8) &&
            (buff[2] == 0xff) &&
            (buff[3] == 0xe) ){

            uint8_t endJPG[2] = {0};            //new buff on 2 bytes, for check end file and write bytes on file

            int count_bytes = 4;                //счетчик байт, записываемых в файл картинки.

            sprintf (nameJPG, "%03d.jpg", i++);   //create name of file for new JPEG file
            FILE *newJPG = fopen(nameJPG, "w"); //create new JPEG file
            if(newJPG == NULL){
                //printf("Could not open file %s .\n", file);
                return 3;
            }

            //printf("\n\n%d file. Name - %s\n", i, nameJPG);
            //read again 4 bytes, becouse buff[4] >> 4, offset on 4 bits
            fseek(badFile, -4, SEEK_CUR);
            fread(buff, 1, 4, badFile);
            fwrite(buff, 1, 4, newJPG);

            short createFile = 1;       //flag, show that we input file.
            //writes 1 byte until we find the end of the file
            do{
                count_bytes++;
                fread(endJPG, 1, 2, badFile);
                fseek(badFile, -1, SEEK_CUR);
                fwrite(&endJPG[0], 1, 1, newJPG);
                if(endJPG[0] == 0xff && endJPG[1] == 0xd9){
                   createFile = 0;
                   fwrite(&endJPG[1], 1, 1, newJPG);            //add the last byte
                }
            }while(createFile != 0);
            fseek(badFile, 512 - count_bytes % 512, SEEK_CUR);  //offset on the end block claster

            fclose(newJPG);
            //printf("Count = %d. Mod = %d\n", count_bytes, 512 - count_bytes % 512);
        }
        else fseek(badFile, 508, SEEK_CUR);     //skip block memory
    }
    fclose(badFile);
    return 0;
}