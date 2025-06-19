#include "./work_system.h"

//work system
int ANK_Work(ANK_WORK work)    {
    if (!work.function) return 1; // error
    work.function(work.function_arg);
    return 0; // success
}