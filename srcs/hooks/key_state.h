
#ifndef KEY_STATE_H
# define KEY_STATE_H

#include <stdbool.h>

typedef struct s_key_state {
    bool w;
    bool a;
    bool s;
    bool d;
    bool left;
    bool right;
} t_key_state;

#endif