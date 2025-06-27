
#ifndef DDA_H
# define DDA_H
#include <stdlib.h>
#include <math.h>

typedef struct s_vector {
    double x;
    double y;
} t_vector;

int dda(t_dda_test *dda_data, t_data *img_data);

#endif