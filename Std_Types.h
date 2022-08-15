#ifndef STD_TYPES_H
#define STD_TYPES_H

#include "Platform_Types.h"

typedef enum
{
    E_OK =0,
    E_NOT_OK,
}Std_ReturnType;

#define TRUE    1u
#define FALSE   0u

#define ENABLE    1u
#define DISABLE   0u

#define NULL_PTR          ((void*)0)

#define STD_HIGH  1u
#define STD_LOW   0u

typedef void (*Ptr2FuncType)(void);
#endif /*STD_TYPES_H*/