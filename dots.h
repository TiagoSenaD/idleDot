#ifndef DOTS_H
#define DOTS_H

struct coordinate{
    int x;
    int y;
};

typedef struct dot_t{
    struct coordinate position;
    struct coordinate velocity;
}dot ;

typedef struct vertex_t {
    struct coordinate data;
    struct vertex_t * next;
}vertex;

#endif