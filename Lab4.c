#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#pragma pack(1)
typedef struct
{
    char tag[3];
    char ver[2];
    char flag;
    char tag_size[4];
} id3v2Header;

typedef struct
{
    char frame[4];
    char size[4];
    char flag[2];
    char unicode;
}id3v2Frame;

uint32_t convert1(id3v2Header test){
    return (test.tag_size[0] << 21 | test.tag_size[1] << 14 | test.tag_size[2] << 7 | test.tag_size[3]);
}
uint32_t convert2(id3v2Frame test){
    return (test.size[0] << 21 | test.size[1] << 14 | test.size[2] << 7 | test.size[3]);
}

void print(id3v2Frame frame, char* frame1, char* value){
    printf("Frame ID: %s\n", frame1);
    printf("Frame TAGSIZE: %d\n", convert2(frame));
    printf("Frame FLAG: %x %x\n", frame.flag[0], frame.flag[1]);
    printf( "Frame VALUE: %s", value);
}
int main(int argc, char* argv[]) {
    id3v2Header testHeader;
    id3v2Frame testFrame;
    id3v2Frame testFrame1;
    id3v2Frame testFrame2;
    char *filename = argv[1];
//    FILE *file = fopen("C:\\Users\\real0\\CLionProjects\\untitled13\\C418-Sweden(MinecraftOST).mp3","rb");
    FILE *file = fopen(filename, "rb");
    printf("\n\n");
//    FILE *file = fopen("C:\\Users\\real0\\CLionProjects\\untitled13\\tagtest.ID3v2.4.mp3", "rb");`
    if (!file) {
        perror("error!!!!!!!!!!!");
        exit(1);
    }
/*    while(EOF){
        fscanf(file, "%s", str);
        printf("%s", str);
    }*/
    char values[20][40];
    id3v2Frame frames[20];
    fread(&testHeader, sizeof(id3v2Header), 1, file);
    if(!strcmp(argv[2], "--show")){
//        printf("%d\n", sizeof(id3v2Frame));
        printf("*********HEADER**********\n");
        printf("Header TAG: %s\n", testHeader.tag);
        printf("Header VER: %x.%x\n", testHeader.ver[0], testHeader.ver[1]);
        printf("Header FLAG: %x\n", testHeader.flag);
        printf("Header SIZE: %d\n", convert1(testHeader));
        printf("**********FRAMES**********\n");
        for (int i = 0; i < 20; i++) {
            testFrame = frames[i];
            fread(&testFrame, sizeof(id3v2Frame), 1, file);
            int malSize = convert2(testFrame) - 1;
            char *str = (char *) malloc(malSize + 1);
            str[malSize] = '\0';
            if (!testFrame.frame[0]) {
                break;
            }
            frames[i] = testFrame;
            printf("Frame ID: %s\n", testFrame.frame);
            printf("Frame TAGSIZE: %d\n", convert2(testFrame));
            printf("Frame FLAG: %x %x\n", testFrame.flag[0], testFrame.flag[1]);
            fread(str, 1, malSize, file);
            printf("Frame VALUE: %s\n", str);
            for(int j = 0; j < malSize; j++){
                values[i][j] = str[j];
            }
            values[i][malSize] = '\0';
            free(str);
            printf("**************************\n");
        }
    }
    if(strstr(argv[2], "--set=")){
        for (int i = 0; i < 20; i++) {
            testFrame = frames[i];
            fread(&testFrame, sizeof(id3v2Frame), 1, file);
            int malSize = convert2(testFrame) - 1;
            char *str = (char *) malloc(malSize + 1);
            str[malSize] = '\0';
            if (!testFrame.frame[0]) {
                break;
            }
            frames[i] = testFrame;
            fread(str, 1, malSize, file);
            for(int j = 0; j < malSize; j++){
                values[i][j] = str[j];
            }
            values[i][malSize] = '\0';
            free(str);
        }
        char request[5];
        request[0] = argv[2][6];
        request[1] = argv[2][7];
        request[2] = argv[2][8];
        request[3] = argv[2][9];
        request[4] = '\0';
        char value[5];
        value[0] = argv[3][8];
        value[1] = argv[3][9];
        value[2] = argv[3][10];
        value[3] = argv[3][11];
        value[4] = '\0';
//        printf("%s\n", request);
//        printf("%s\n", value);
        for (int i = 0; i < 20; i++) {
//            printf("%s\n", frames[i].frame);
            if (strcmp(frames[i].frame, request) == 0) {
                //printf("!!!!!!!!!!!!!!!!");
                frames[i].frame[0] = value[0];
                frames[i].frame[1] = value[1];
                frames[i].frame[2] = value[2];
                frames[i].frame[3] = value[3];
                print(frames[i], frames[i].frame, values[i]);
                break;
            }
        }
        printf("\n\n");
    }
//    printf("%s\n", argv[2]);
//    printf("%s\n", strstr(argv[2], "--get="));
    if(strstr(argv[2], "--get=")){
        char value1[5];
        value1[0] = argv[2][6];
        value1[1] = argv[2][7];
        value1[2] = argv[2][8];
        value1[3] = argv[2][9];
        value1[4] = '\0';
//        printf("!!!!!!!!!!");
        for (int i = 0; i < 20; i++) {
            testFrame = frames[i];
            fread(&testFrame, sizeof(id3v2Frame), 1, file);
            int malSize = convert2(testFrame) - 1;
            char *str = (char *) malloc(malSize + 1);
            str[malSize] = '\0';
            if (!testFrame.frame[0]) {
                break;
            }
            frames[i] = testFrame;
            fread(str, 1, malSize, file);
            for(int j = 0; j < malSize; j++){
                values[i][j] = str[j];
            }
            values[i][malSize] = '\0';
            free(str);
        }
//        printf("!!!!!!!!!!");
        for (int i = 0; i < 20; i++) {
//            printf("%s\n", frames[i].frame);
            if (strcmp(frames[i].frame, value1) == 0) {
                //printf("!!!!!!!!!!!!!!!!");
                frames[i].frame[0] = value1[0];
                frames[i].frame[1] = value1[1];
                frames[i].frame[2] = value1[2];
                frames[i].frame[3] = value1[3];
                print(frames[i], frames[i].frame, values[i]);
                break;
            }
        }
        printf("\n\n");
    }
//
//    char request[5], value[5];
//    int bytesCount = sizeof(testHeader);
////    scanf("%s", request);
////    scanf("%s", value);
//    FILE *fileW = fopen("C:\\Users\\real0\\CLionProjects\\untitled13\\arm", "w");
//    if (!fileW) {
//        perror("arm");
//        exit(1);
//    }
//    for (int i = 0; i < 20; i++) {
//        bytesCount += sizeof(testFrame) + convert2(frames[i]);
//        if (strcmp(frames[i].frame, request) == 0) {
//            frames[i].frame[0] = value[0];
//            frames[i].frame[1] = value[1];
//            frames[i].frame[2] = value[2];
//            frames[i].frame[3] = value[3];
//            print(frames[i], fileW, frames[i].frame, values[i]);
//            break;
//        }
//    }
////    fread(&testFrame1, sizeof(id3v2Frame), 1, file);
////    char *str1 = (char*) malloc(convert2(testFrame1) - 1);
////    printf("Frame ID: %s\n", testFrame1.frame);
////    printf("Frame TAGSIZE: %d\n", convert2(testFrame1));
////    printf("Frame FLAG: %x %x\n", testFrame1.flag[0], testFrame1.flag[1]);
////    int malsize = convert2(testFrame1) - 1;
////    fread(str1,1,  malsize, file);
////    printf("Frame VALUE: %s\n", str1);
////    free(str1);
////    printf("**************************\n");
////    fread(&testFrame2, sizeof(id3v2Frame), 1, file);
////    char *str2 = NULL;
////    printf("Frame ID: %s\n", testFrame2.frame);
////    printf("Frame TAGSIZE: %d\n", convert2(testFrame2));
////    printf("Frame FLAG: %x %x\n", testFrame2.flag[0], testFrame2.flag[1]);
////    int malsize1 = convert2(testFrame2) - 1;
////    fread(str2, 1, malsize1, file);
////    printf("Frame VALUE: %s\n", str2);
////    printf("**************************\n");
    fclose(file);
//    fclose(fileW);
    return 0;
}


//C:\Users\real0\CLionProjects\untitled13\C418-Sweden(MinecraftOST).mp3
//C:\Users\real0\CLionProjects\untitled13\C418 - Living Mice.mp3