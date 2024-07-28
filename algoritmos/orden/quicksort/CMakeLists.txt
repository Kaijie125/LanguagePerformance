add_executable(quicksort_cpp orden.cpp)
add_executable(quicksort_c orden.c)
add_jar(quicksort_java orden.java ENTRY_POINT orden)
configure_file(orden.py quicksort.py COPYONLY)
