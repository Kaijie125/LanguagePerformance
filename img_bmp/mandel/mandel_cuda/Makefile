all:mandel_c mandel_cpp

mandel_c:
	gcc -c mandel_c.c
	nvcc -c -ldl -lrt -lm cuda_mandel.cu
	nvcc cuda_mandel.o mandel_c.o -o mandel_c

mandel_cpp:
	g++ -c mandel_cpp.cpp
	nvcc -c -ldl -lrt -lm cuda_mandel.cu
	nvcc cuda_mandel.o mandel_cpp.o -o mandel_cpp

mandel_java:
	gcc -shared -o libmandel.so -I"$JAVA_HOME/include" -I"$JAVA_HOME/include/linux" mandel_jni.c
	export LD_LIBRARY_PATH=.

clean:
	rm *.o mandel_c mandel_cpp *.bmp *.so
