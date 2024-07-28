add_executable(timsort_cpp timsort.cpp)
add_executable(timsort_c timsort.c)
add_jar(timsort_java timsort.java ENTRY_POINT timsort)
configure_file(timsort.py timsort.py COPYONLY)
