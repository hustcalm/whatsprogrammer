void* handle  = dlopen("libtest.so", RTLD_LAZY);
void (*test)() = dlsym(handle, "my_function");
(*test)();
dlclose(handle);
