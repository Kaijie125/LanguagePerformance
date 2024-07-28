find_package(Threads REQUIRED)

add_executable(aritmetica_hilos_cpp aritmetica.cpp)
target_link_libraries(aritmetica_hilos_cpp Threads::Threads)

add_executable(aritmetica_hilos_c aritmetica.c)
target_link_libraries(aritmetica_hilos_c Threads::Threads)

add_jar(aritmetica_hilos_java aritmetica.java ENTRY_POINT aritmetica)

configure_file(aritmetica.py aritmetica_hilos.py COPYONLY)
