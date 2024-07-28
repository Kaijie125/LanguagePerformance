add_executable(aritmetica_cpp aritmetica.cpp)
add_executable(aritmetica_c aritmetica.c)
add_jar(aritmetica_java aritmetica.java ENTRY_POINT aritmetica)
configure_file(aritmetica.py aritmetica.py COPYONLY)
