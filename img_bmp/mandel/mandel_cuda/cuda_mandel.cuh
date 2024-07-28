#ifndef CUDA_MANDEL
#define CUDA_MANDEL

void kernel_wrapper(char *hst_img, int img_size, int iter, double x_min, double y_min, double h_x_step, double h_y_step, int W_x_H, int width, int row_size);
// recordatorio: img_size != W_x_H, img_size = W_x_H * 3 + height * padding = row_size * height

#endif