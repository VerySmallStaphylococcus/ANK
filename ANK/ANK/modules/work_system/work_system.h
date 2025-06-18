#pragma once

//function pointer
typedef void (*func)(void *p); 


//the work struct
typedef struct
{
    func function;  // function
    void *function_arg; // argument
}ANK_WORK;

void ANK_Work(ANK_WORK work);