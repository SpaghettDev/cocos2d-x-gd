#ifndef __CCPLATFORMDEFINE_H__
#define __CCPLATFORMDEFINE_H__

#if defined(_USRDLL)
    #define CC_DLL     __declspec(dllexport)
#else         // use a DLL library
    #define CC_DLL     __declspec(dllimport)
#endif

// shared library declartor
#define CC_DLL 

#include <assert.h>
#define CC_ASSERT(cond)    assert(cond)
#define CC_UNUSED_PARAM(unusedparam) (void)unusedparam

/* Define NULL pointer value */
#ifndef NULL
#ifdef __cplusplus
#define NULL    0
#else
#define NULL    ((void *)0)
#endif
#endif



#endif /* __CCPLATFORMDEFINE_H__*/
