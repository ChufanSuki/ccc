#include "sobel.h"

#include <stdio.h>
PIXEL kernelx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};

PIXEL kernely[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

void sobel(PIXEL src[HEIGHT * WIDTH], PIXEL dst[(HEIGHT - 2) * (WIDTH - 2)],
           int rows, int cols) {
  for (int row = 0; row < HEIGHT - 2; row++) {
    for (int col = 0; col < WIDTH - 2; col++) {
      int magX = 0;
      int magY = 0;
      for (int a = 0; a < 3; a++) {
        for (int b = 0; b < 3; b++) {
          magX += src[(row + a) * WIDTH + col + b] * kernelx[a][b];
        }
      }
      for (int a = 0; a < 3; a++) {
        for (int b = 0; b < 3; b++) {
          magY += src[(row + a) * WIDTH + col + b] * kernely[a][b];
        }
      }
      if (magX > 255)
        magX = 255;
      else if (magX < 0)
        magX = 0;
      if (magY > 255)
        magY = 255;
      else if (magY < 0)
        magY = 0;
      int res = magX + magY;
      if (res > 255) {
        dst[row * (WIDTH - 2) + col] = 255;
      } else if (res < 0) {
        dst[row * (WIDTH - 2) + col] = 0;
      } else {
        dst[row * (WIDTH - 2) + col] = (PIXEL)magX + (PIXEL)magY;
      }
    }
  }
  printf("get %d", dst[917604]);
}
