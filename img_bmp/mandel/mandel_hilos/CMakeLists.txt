find_package(Threads REQUIRED)

add_executable(mandel_hilos_cpp mandel.cpp)
target_link_libraries(mandel_hilos_cpp Threads::Threads)

add_executable(mandel_hilos_c mandel.c)
target_link_libraries(mandel_hilos_c Threads::Threads)

add_jar(mandel_hilos_java mandel.java ENTRY_POINT mandel)

configure_file(mandel.py mandel_hilos.py COPYONLY)
