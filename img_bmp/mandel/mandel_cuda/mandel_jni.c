#include <jni.h>
#include <stdio.h>
#include "mandel_jni.h"

// llamada al kernel donde se encuantra el el fichero .cu
void kernel_wrapper(char *hst_img, int img_size, int iter, double x_min, double y_min, double h_x_step, double h_y_step, int W_x_H, int width, int row_size);

JNIEXPORT void JNICALL Java_mandel_kernelWrapper
  (JNIEnv *env, jobject obj, jbyteArray hst_img, jint img_size, jint iter, jdouble x_min, jdouble y_min, jdouble h_x_step, jdouble h_y_step, jint W_x_H, jint width, jint row_size){
    // (data, img_size, iter, x_min, y_min, h_x_step, h_y_step, W_x_H, width, row_size);
    printf("img_size: %d\n", (int)img_size);
    printf("iter: %d\n", (int)iter);
    printf("x_min: %f\n", (double)x_min);
    printf("y_min: %f\n", (double)y_min);
    printf("h_x_step: %f\n", (double)h_x_step);
    printf("h_y_step: %f\n", (double)h_y_step);
    printf("W_x_H: %d\n", (int)W_x_H);
    printf("width: %d\n", (int)width);
    printf("row_size: %d\n", (int)row_size);

    // asigna valorea a data al array de bytes del 0 al longitud del array
    jbyte *img_ptr = (*env)->GetByteArrayElements(env, hst_img, NULL);
    // Asignar valores al array de bytes
    kernel_wrapper(img_ptr, (int)img_size, (int)iter, (double)x_min, (double)y_min, (double)h_x_step, (double)h_y_step, (int)W_x_H, (int)width, (int)row_size);

    // libera el array de bytes
    (*env)->ReleaseByteArrayElements(env, hst_img, img_ptr, 0);


  }