#include <dlfcn.h>
#include <stdbool.h>
#include <stdio.h>

void (*hello_ariel)();

bool init_library()
{
    void *handle;
    void *result (int);
    handle = dlopen("./libhello_ariel.so", RTLD_LAZY);
    if(NULL==handle)
        return false;
    hello_ariel = (void(*)())dlsym(handle, "hello_ariel");
    if(NULL==hello_ariel)
        return false;
    return true;


    
}
int main()
{
   if(init_library())
        hello_ariel();
    else
        printf("failed to load library.\n");

    return 0;
}
