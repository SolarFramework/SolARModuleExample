/**
 * Copyright and license notice ......
 */

#ifndef EXAMPLE_API_H
    #define EXAMPLE_API_H
    #if _WIN32
        #ifdef SolARModuleExample_API_DLLEXPORT
            #define EXAMPLE_EXPORT_API __declspec(dllexport)
        #else //Example_API_DLLEXPORT
            #define EXAMPLE_EXPORT_API __declspec(dllimport)
        #endif //Example_API_DLLEXPORT
    #else //_WIN32
        #define EXAMPLE_EXPORT_API
    #endif //_WIN32
    #include "SolARModuleExample_traits.h"
#endif //EXAMPLE_API_H
