#include <stdio.h>
#include "ag-ffi-header/runtime.h"
#include "ag-ffi-header/blob.h"
#include "<anything from vcpkg>.h"

typedef struct {
    AgObject header;
    StructFromVcpkg* handle;
} MyClass;

typedef struct {
    AgObject header;
    AnotherStructFromVcpkg* handle;
} Result;

void ag_m_myModule_MyClass_myModule_internalMethod(
    MyClass* thiz,
    Result* res,
    params)
{
    // Do it
    res->handle = someNativePtr;
}

void ag_fn_myModule_disposeMyClass(MyClass* thiz) {
    if (thiz->handle)
        nativeDispose(thiz->handle);
}

void ag_m_myModule_Result_myModule_getAttr(Result* thiz) int{
    return thiz
        ? extract(thiz->handle)
        : 0;
}

void ag_fn_myModule_disposeResult(Result* thiz) {
    if (thiz->handle)
        nativeDisposeResult(thiz->handle);
}
