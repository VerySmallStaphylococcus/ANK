#pragma once

#define MSIZE_MEMPOOL

//memory union for memory pool
typedef union   {
    char CHAR;
    int INT;
    float FLOAT;
    double DOUBLE;
}memory;

typedef struct
{
    memory data;    //data
    int state;      //if memory is empty it's 0 but if the memory isn't empty it's can have 1 
    //data type
    enum {
        None,
        Int,
        Float,
        Double,
        Char
    }data_type;
}ANK_memory;


typedef long long size64;    //size type for 64bit
typedef int size32;          //size type for 32bit


//memory pool struct(for define memory pool infos)
typedef struct  {
    ANK_memory *pool;
    size32  pool_size;
    size32  used;
}memory_pool32;
typedef struct  {
    ANK_memory *pool;
    size64  pool_size;
    size64  used;
}memory_pool64;

typedef long long ptr64;    //memory pointer for 64bit
typedef int ptr32;          //memory pointer for 32bit

//memory alloc function
// 0 : Success
// 1 : fail
//it's return the data location(ptr arg) on memory pool
int mempool_save32(memory_pool32 *pool, ANK_memory data, ptr32 *ptr);   //for 32bit
int mempool_save64(memory_pool64 *pool, ANK_memory data, ptr64 *ptr);   //for 64bit

//get data on memory pool function
// 0 : Success
// 1 : fail
//it's return data(use union)
int mempool_gdata32(memory_pool32 *pool, ptr32 ptr, ANK_memory *out_data);
int mempool_gdata64(memory_pool64 *pool, ptr64 ptr, ANK_memory *out_data);

//memory free function
// 0 : Success
// 1 : fail
int mempool_free32(memory_pool32 *pool, ptr32 ptr); //for 32bit
int mempool_free64(memory_pool64 *pool, ptr64 ptr); //for 64bit