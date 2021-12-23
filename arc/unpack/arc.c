#include <stdio.h>
#include <string.h>
#define SIZEOF 4
#define FILES 100


void Pack(char *archiveName, int filesCount, char** files)
{
    char byte[1];  // единичный буфер для считывания одного байта
    FILE *f;
    FILE *archFile = fopen(archiveName,"wb");  // файл - архив
    unsigned long long int fileSize[FILES];
    for(int i = SIZEOF; i < filesCount; i++){
        f = fopen(files[i], "rb");
        if(!f){
            continue;
        }
        fseek(f, 0, SEEK_END);
        fileSize[i - SIZEOF] = ftell(f);
        rewind(f);
        fclose(f);
    }
    for (int i = SIZEOF; i < filesCount; i++) {
        fprintf(archFile, "** %s : %llu ** ", files[i], fileSize[i - SIZEOF]);
        if(i == filesCount - 1){
            fprintf(archFile, "\n");
        }
    }
    for (int i = SIZEOF; i < filesCount; i++){
        f = fopen(files[i], "rb");
        if(!f){
            printf("Error of adding file\n");
            continue;
        } else {
            printf("File successfully added\n");
        }
        int symbol;
        while ((symbol = getc(f)) != EOF){
            putc(symbol, archFile);
        }
        fprintf(archFile, "\n");
        fclose(f);
    }
    fclose(archFile);
}

void Unpack(char *archiveName){
    FILE* archiveFile = fopen(archiveName, "rb");
    char* fileNames[FILES];
    char fileName[FILES];
    int cnt1 = 0;
    int c;
    int fileSize;
    int fileSizes[FILES];
    while(fscanf(archiveFile, "** %s : %d ** ", fileName, &fileSize)){
        fileNames[cnt1] = fileName;
        fileSizes[cnt1] = fileSize;
        cnt1 = cnt1 + 1;
    }
    printf("%d\n", cnt1);
    for(int i = 0; i < cnt1; i++){
        printf("** %s : %d ** \n", fileNames[i], fileSizes[i]);
    }
    for(int i = 0; i < cnt1; i++){
        printf("%s\n", fileNames[i]);
        FILE* file = fopen(fileNames[i], "wb");
        while(fileSizes[i]-- > 0 || c != '\n'){
            putc(c = (getc(archiveFile)), file);
        }
        fclose(file);
    }
    printf("Unpacked successfully\n");
    fclose(archiveFile);
}

void Print(char *archiveName){
    FILE *archiveFile = fopen(archiveName, "rb");
    char fileName[FILES];
    unsigned long long int fileSize;
    printf("\n**********List**********\n\n");
    while(fscanf(archiveFile, "** %s : %llu ** ", fileName, &fileSize)){
        printf("%s\n", fileName);
    }
    printf("\n************************\n");
    fclose(archiveFile);
}

int main(int argc, char** argv){
    int i;
    char* arcname;
    printf("\n");
    for (i = 0; i < argc; i++){
        if(!strcmp("--file", argv[i])){
            arcname = argv[i + 1];
        }
        if(!strcmp("--create", argv[i])){
            Pack(arcname, argc, argv);
            break;
        }
        if(!strcmp("--extract", argv[i])){
            Unpack(arcname);
            break;
        }
        if(!strcmp("--list", argv[i])){
            Print(arcname);
        }
    }
    return 0;
}
