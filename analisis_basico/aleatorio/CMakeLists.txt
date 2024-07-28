add_executable(aleatorio_cpp aleatorio.cpp)
add_executable(aleatorio_c aleatorio.c)
add_jar(aleatorio_java aleatorio.java ENTRY_POINT aleatorio)
configure_file(aleatorio.py aleatorio.py COPYONLY)
