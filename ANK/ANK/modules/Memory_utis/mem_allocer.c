#include "./mem_allocer.h"


//memory alloc function
// 0 : Success
// 1 : fail
//it's return the data location on memory pool
ptr32 mempool_save32(memory_pool32 *pool, memory data)  {

}   //for 32bit
ptr64 mempool_save64(memory_pool64 *pool, memory data)  {

}   //for 64bit

//get data on memory pool function
// 0 : Success
// 1 : fail
//it's return data(use union)
int mempool_gdata32(memory_pool32 *pool, ptr32 ptr, ANK_memory *out_data)   {}
int mempool_gdata64(memory_pool64 *pool, ptr64 ptr, ANK_memory *out_data)   {

}

//memory free function
// 0 : Success
// 1 : fail
int mempool_free32(memory_pool32 *pool, ptr32 ptr)  {} //for 32bit
int mempool_free64(memory_pool64 *pool, ptr64 ptr)  {} //for 64bit