#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "bmp.h"
#include <string.h>
#include <math.h>
#include <stdint.h>
#pragma pack(1)
#define MAX_BSZ  512



unsigned const int FIELDSIZE = 10;
unsigned const int ITERS = 1;

//int ReturnNeighbors(int** Field, int Y, int X){
//    int N = Field[X-1][Y+1] + Field[X][Y+1] + Field[X+1][Y+1] + Field[X+1][Y] + Field[X+1][Y-1] + Field[X][Y-1] + Field[X-1][Y-1] + Field[X-1][Y];
//    return N;
//}

int file_copy(const char* existing_filename, const char* new_filename){
    int    err;
    size_t num, len;
    char   buf[MAX_BSZ];
    FILE*  fout, *fin;

    if((fin = fopen(existing_filename, "rb")) == NULL)
        return errno;

    if((fout = fopen(new_filename, "wb")) == NULL){
        err = errno;
        fclose(fin);
        return err;
    }

    err = 0;
    while(((num = fread(buf, sizeof(char), MAX_BSZ, fin)) > 0) && ((err = ferror(fin)) == 0)){
        len = fwrite(buf, sizeof(char), num, fout);
        if((len != num) || (ferror(fout) != 0)){
            err = ferror(fout);
            break;
        }
    }

    if(fclose(fin) == EOF){
        if(err == 0)
            err = errno;
    }

    if(fclose(fout) == EOF){
        if(err == 0)
            err = errno;
    }
    return err;
}

int main(int argc, char **argv){
    FILE *fp = fopen("C:\\Users\\real0\\CLionProjects\\GameOfLife\\glider_gun.bmp", "rb");
    struct BMPHeader BmpHeader;
    struct DIBHeader DibHeader;
    fread(&BmpHeader, sizeof(struct BMPHeader), 1, fp);
    if(!strcmp(BmpHeader.name,"BM")){
        return -1;
    }
//    printf("NAME: %c%c\n", BmpHeader.name[0], BmpHeader.name[1]);
//    printf("SIZE: %llu\n", sizeof(DibHeader));
//    printf("SIZE: %d\n", BmpHeader.size);
//    printf("OFFSET: %d\n", BmpHeader.imageOffset);
    fread(&DibHeader, sizeof(struct DIBHeader), 1, fp);
//    printf("DibSIZE: %d\nWIDTH: %d\nHEIGHT: %d\nCOLORPLANES: %d\nBITSPERPIXEL: %d\nCOMPRESSION: %d\nIMAGESIZE: %d\n", DibHeader.size, DibHeader.width, DibHeader.height, DibHeader.colorPlanes, DibHeader.bitsPerPixel, DibHeader.compression, DibHeader.imageSize);
//    fseek(fp, BmpHeader.imageOffset,SEEK_SET);
    unsigned char image[BmpHeader.size - 62];
    fseek(fp, 62, SEEK_SET);
    fread(image, 1, BmpHeader.size - 62, fp);
    float FWidth = DibHeader.width;
    int width = ceil( FWidth / 8);
    int widthOst = -(width % 4);
    width = width + abs(widthOst);
    int Field[DibHeader.height][DibHeader.width];
    int FieldSave[DibHeader.height][DibHeader.width];
    for(int i = 0; i < DibHeader.height; i++){
        for(int j = 0; j < DibHeader.width; j++){
            Field[i][j] = 0;
            FieldSave[i][j] = 0;
        }
    }
    for(int it = 0; it < ITERS; it++) {
        FILE* fpw = fopen("C:\\Users\\real0\\CLionProjects\\GameOfLife\\ARMMM.bmp", "wb");
        file_copy("C:\\Users\\real0\\CLionProjects\\GameOfLife\\glider_gun.bmp", "C:\\Users\\real0\\CLionProjects\\GameOfLife\\ARMMM.bmp");
        int n = 0;
        for (int i = DibHeader.height - 1; i >= 0; --i) {
            for (int j = 0; j < width; j++) {
                int b = image[n];
                for (int k = 0; k < 8; k++) {
                    if (8 * j + k < DibHeader.width)
                        Field[i][8 * j + k] = !((b >> (7 - k)) & 1);
                }
                n++;
            }
        }
        printf("Generation : %d\n", it);
        for (int x = 0; x < DibHeader.height ; x++) {
            for (int y = 0; y < DibHeader.width; y++) {
                printf("%d", Field[x][y]);
            }
            printf("\n");
        }
        printf("\n");

        for (int x = DibHeader.height - 2; x >= 1 ; x--) {
            for (int y = 1; y < DibHeader.width - 1; y++) {
                int N = Field[x-1][y+1] + Field[x][y+1] + Field[x+1][y+1] + Field[x+1][y] + Field[x+1][y-1] + Field[x][y-1] + Field[x-1][y-1] + Field[x-1][y];
                if (Field[x][y] == 1) {
                    if (N == 2) FieldSave[x][y] = Field[x][y];
                    if (N == 3) FieldSave[x][y] = Field[x][y];
                    if (N < 2) FieldSave[x][y] = 0;
                    if (N > 3) FieldSave[x][y] = 0;
                } else {
                    if (N == 3) FieldSave[x][y] = 1;
                }
//                printf("%d.", ReturnNeighbors(x, y));
            }
            printf("\n");
        }
        for (int x = 0; x < DibHeader.height ; x++) {
            for (int y = 0; y < DibHeader.width; y++) {
                printf("%d", FieldSave[x][y]);
            }
            printf("\n");
        }

//        printf("!!!!!!!%d\n",sizeof(DibHeader));
        for (int x = DibHeader.height - 1; x >= 0 ; x--) {
            for (int y = 0; y < DibHeader.width; y++) {
                Field[x][y] = FieldSave[x][y];
            }
        }

        fseek(fpw, BmpHeader.imageOffset, SEEK_SET);
        int n1 = 0;
        for (int i = DibHeader.height - 1; i >= 0; i--) {
            for (int j = 0; j < width; j++) {
                int byte = 0;
                for (int k = 0; k < 8; ++k) {
                    if (8 * j + k < DibHeader.width) {
                        byte += ((!Field[i][8 * j + k]) << (7 - k));
                    }
                }
                image[n1++] = byte;
            }
        }
        fwrite(&image, sizeof(image), 1, fpw);
        Sleep(500);
        fclose(fpw);
//        system("cls");
    }
    fclose(fp);
//    fclose(fpw);
//    system("pause");
    return 0;
}