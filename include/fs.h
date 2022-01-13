#pragma once

namespace Filesystem
{

namespace Ramdisk
{

typedef struct
{
    char * name;
    char * contents;
    char * path;
    char * parent;
    int id;
    uint32_t size;
    bool null = false;

    bool operator!() { return null; }
} FILE;

typedef struct
{
    char * name;
    char * path;
    FILE files[128];
    int file_count = 0;
    int id;
    uint32_t size;
    bool null = false;

    bool operator!() { return null; }
} FOLDER;

typedef struct
{
    char filename[128];
    char foldername[128];
} path_t;

FOLDER folders[128];
int folder_count = 0;

FILE null_file();
FOLDER null_folder();
FOLDER get_folder(char * name);
FILE get_file(char * name, char * FOLDER);
FOLDER create_folder(char * name);
FILE create_file(char * name, char * FOLDER, char * contents, uint32_t size);
FILE create_file(char * name, char * FOLDER, char * contents);
FILE fopen(char * name, char * folder);

}

void ls();

}