#include "./mem_allocer.h"


//memory alloc function
// 0 : Success
// 1 : fail
//it's return the data location on memory pool
//for 32bit
int mempool_save32(memory_pool32 *pool, ANK_memory data, ptr32 *ptr) {
    for (size32 i = 0; i < pool->pool_size; i++) {
        if (pool->pool[i].state == 0) {
            // 빈 공간 발견 → 데이터 복사
            switch (data.data_type) {
                case None:
                    return 1;
                case Int:
                    pool->pool[i].data.INT = data.data.INT;
                    break;
                case Float:
                    pool->pool[i].data.FLOAT = data.data.FLOAT;
                    break;
                case Double:
                    pool->pool[i].data.DOUBLE = data.data.DOUBLE;
                    break;
                case Char:
                    pool->pool[i].data.CHAR = data.data.CHAR;
                    break;
                default:
                    return 1;
            }

            // ✅ 상태 설정 및 포인터 저장
            pool->pool[i].state = 1;
            *ptr = i;
            pool->used++;
            return 0;  // 성공
        }
    }

    return 1; // 할당 실패 (빈 공간 없음)
}
//for 64bit
int mempool_save64(memory_pool64 *pool, ANK_memory data, ptr64 *ptr) {
    for (size64 i = 0; i < pool->pool_size; i++) {
        if (pool->pool[i].state == 0) {
            switch (data.data_type) {
                case None:
                    return 1;
                case Int:
                    pool->pool[i].data.INT = data.data.INT;
                    break;
                case Float:
                    pool->pool[i].data.FLOAT = data.data.FLOAT;
                    break;
                case Double:
                    pool->pool[i].data.DOUBLE = data.data.DOUBLE;
                    break;
                case Char:
                    pool->pool[i].data.CHAR = data.data.CHAR;
                    break;
                default:
                    return 1;
            }

            pool->pool[i].state = 1;
            *ptr = i;
            pool->used++;
            return 0;
        }
    }

    return 1;
}


//get data on memory pool function
// 0 : Success
// 1 : fail
//it's return data(use union)
int mempool_gdata32(memory_pool32 *pool, ptr32 ptr, ANK_memory *out_data) {
    if (ptr < 0 || ptr >= pool->pool_size) return 1;  //range check

    if (pool->pool[ptr].state != 1) return 1;         //Check if memory is in use

    switch (pool->pool[ptr].data_type) {
        case Int:
            out_data->data.INT = pool->pool[ptr].data.INT;
            out_data->data_type = Int;
            break;

        case Float:
            out_data->data.FLOAT = pool->pool[ptr].data.FLOAT;
            out_data->data_type = Float;
            break;

        case Double:
            out_data->data.DOUBLE = pool->pool[ptr].data.DOUBLE;
            out_data->data_type = Double;
            break;

        case Char:
            out_data->data.CHAR = pool->pool[ptr].data.CHAR;
            out_data->data_type = Char;
            break;

        default:
            return 1;  //undefined type
    }

    return 0; //Success ✅ 
}

int mempool_gdata64(memory_pool64 *pool, ptr64 ptr, ANK_memory *out_data)   {
if (ptr < 0 || ptr >= pool->pool_size) return 1;  //range check

    if (pool->pool[ptr].state != 1) return 1;         //Check if memory is in use

    switch (pool->pool[ptr].data_type) {
        case Int:
            out_data->data.INT = pool->pool[ptr].data.INT;
            out_data->data_type = Int;
            break;

        case Float:
            out_data->data.FLOAT = pool->pool[ptr].data.FLOAT;
            out_data->data_type = Float;
            break;

        case Double:
            out_data->data.DOUBLE = pool->pool[ptr].data.DOUBLE;
            out_data->data_type = Double;
            break;

        case Char:
            out_data->data.CHAR = pool->pool[ptr].data.CHAR;
            out_data->data_type = Char;
            break;

        default:
            return 1;  //undefined type
    }

    return 0; //Success 
}

//memory free function
// 0 : Success
// 1 : fail
int mempool_free32(memory_pool32 *pool, ptr32 ptr) {
    //Check range
    if (ptr < 0 || ptr >= pool->pool_size) return 1;

    //Verify that you are using it
    if (pool->pool[ptr].state != 1) return 1;  // 이미 비어 있음

    //Memory Release: Create status to 0 and data clips
    pool->pool[ptr].state = 0;
    pool->pool[ptr].data = (memory){0};
    pool->pool[ptr].data_type = None;     
    pool->used--;              

    return 0;  //Success
}//for 32bit
int mempool_free64(memory_pool64 *pool, ptr64 ptr)  {
    //Check range
    if (ptr < 0 || ptr >= pool->pool_size) return 1;

    //Verify that you are using it
    if (pool->pool[ptr].state != 1) return 1;

    //Memory Release: Create status to 0 and data clips
    pool->pool[ptr].state = 0;
    pool->pool[ptr].data = (memory){0};
    pool->pool[ptr].data_type = None;
    pool->used--;

    return 0;  //Success
} //for 64bit