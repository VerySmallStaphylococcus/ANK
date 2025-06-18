#include "./mem_allocer.h"


//memory alloc function
// 0 : Success
// 1 : fail
//it's return the data location on memory pool
int mempool_save32(memory_pool32 *pool, ANK_memory data, ptr32 *ptr)    {
    //Find empty space by repeating the size of the pool
    for (size32 i = 0; i < pool->pool_size; i++)    {
        
        //if memory is used?
        if (pool->pool[i].state == 1)   {
            continue;   //pass
        }else if (pool->pool[i].state == 0)     {   //if find empty memory!
            switch (data.data_type)    {
                
                //if data type isn't define
                case None:
                    return 1;   //return error
                    break;

                case Int:
                    pool->pool[i].data.INT = data.data.INT;
                    return i;
                    break;
                
                case Float:
                    pool->pool[i].data.FLOAT = data.data.FLOAT;
                    return i;
                    break;
                
                case Double:
                    pool->pool[i].data.DOUBLE = data.data.DOUBLE;
                    return i;
                    break;
                
                case Char:
                    pool->pool[i].data.CHAR = data.data.CHAR;
                    return i;
                    break;

                //other problems
                default:
                    return 1;   //return error
                    break;
                }
        }
        
        //If you don't find any empty space by the end of the arrangement (The comment is a bit weird. Please understand)
        if (i >= pool->pool_size)   {
            return 1;   //return error
        }
        
    }
    
}   //for 32bit
int mempool_save64(memory_pool64 *pool, ANK_memory data, ptr64 *ptr)    {
    //Find empty space by repeating the size of the pool
    for (size64 i = 0; i < pool->pool_size; i++)    {
        
        //if memory is used?
        if (pool->pool[i].state == 1)   {
            continue;   //pass
        }else if (pool->pool[i].state == 0)     {   //if find empty memory!
            switch (data.data_type)    {
                
                //if data type isn't define
                case None:
                    return 1;   //return error
                    break;

                case Int:
                    pool->pool[i].data.INT = data.data.INT;
                    return i;
                    break;
                
                case Float:
                    pool->pool[i].data.FLOAT = data.data.FLOAT;
                    return i;
                    break;
                
                case Double:
                    pool->pool[i].data.DOUBLE = data.data.DOUBLE;
                    return i;
                    break;
                
                case Char:
                    pool->pool[i].data.CHAR = data.data.CHAR;
                    return i;
                    break;

                //other problems
                default:
                    return 1;   //return error
                    break;
                }
        }
        
        //If you don't find any empty space by the end of the arrangement (The comment is a bit weird. Please understand)
        if (i >= pool->pool_size)   {
            return 1;   //return error
        }
        
    }
}   //for 64bit

//get data on memory pool function
// 0 : Success
// 1 : fail
//it's return data(use union)
int mempool_gdata32(memory_pool32 *pool, ptr32 ptr, ANK_memory *out_data)   {

}
int mempool_gdata64(memory_pool64 *pool, ptr64 ptr, ANK_memory *out_data)   {

}

//memory free function
// 0 : Success
// 1 : fail
int mempool_free32(memory_pool32 *pool, ptr32 ptr)  {} //for 32bit
int mempool_free64(memory_pool64 *pool, ptr64 ptr)  {} //for 64bit