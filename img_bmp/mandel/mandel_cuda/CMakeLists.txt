
set(C_SOURCES mandel_c.c)
set(CPP_SOURCES mandel_cpp.cpp)
set(CUDA_SOURCES cuda_mandel.cu)

add_library(mandel_c_obj OBJECT ${C_SOURCES})
add_library(mandel_cpp_obj OBJECT ${CPP_SOURCES})
add_library(cuda_mandel_obj OBJECT ${CUDA_SOURCES})

set(CUDA_LIBRARIES -ldl -lrt -lm)

add_executable(mandel_cuda_c $<TARGET_OBJECTS:cuda_mandel_obj> $<TARGET_OBJECTS:mandel_c_obj>)
target_link_libraries(mandel_cuda_c ${CUDA_LIBRARIES})

add_executable(mandel_cuda_cpp $<TARGET_OBJECTS:cuda_mandel_obj> $<TARGET_OBJECTS:mandel_cpp_obj>)
target_link_libraries(mandel_cuda_cpp ${CUDA_LIBRARIES})



set(JAVA_INCLUDE_PATH "$ENV{JAVA_HOME}/include")
set(JAVA_INCLUDE_PATH2 "$ENV{JAVA_HOME}/include/linux")
include_directories(${JAVA_INCLUDE_PATH} ${JAVA_INCLUDE_PATH2})

add_library(mandel_jni OBJECT mandel_jni.c)
set_property(TARGET mandel_jni PROPERTY POSITION_INDEPENDENT_CODE ON)
add_library(cuda_mandel OBJECT ${CUDA_SOURCES})
set_property(TARGET cuda_mandel PROPERTY POSITION_INDEPENDENT_CODE ON)
add_library(mandel SHARED $<TARGET_OBJECTS:mandel_jni> $<TARGET_OBJECTS:cuda_mandel>)
target_link_libraries(mandel cuda cudart)

add_jar(mandel_cuda_java mandel.java ENTRY_POINT mandel)

configure_file(mandel.py mandel_cuda.py COPYONLY)
