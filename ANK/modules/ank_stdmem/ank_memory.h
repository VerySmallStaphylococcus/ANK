#pragma once

//size type
typedef long long ANK_size64;    //size type for 64bit
typedef int ANK_size32;          //size type for 32bit

//pointer type
typedef long long ptr64;    //memory pointer for 64bit
typedef int ptr32;          //memory pointer for 32bit


typedef struct
{
    void *data; //save data here!
    int state;  //1 is use 0 is empty
}ANK_memory;

void ank_save(ANK_memory data)  {}