#ifndef INC_RING_BUFFER_H
#define INC_RING_BUFFER_H
#include "common-defines.h"
#include <stdint.h>

typedef struct ring_buffer_t {
    uint8_t* buffer;
    uint32_t mask;
    uint32_t read_index;
    uint32_t write_index;
} ring_buffer_t;

void ring_buffer_setup(ring_buffer_t* rb, uint8_t* buffer, uint32_t size);
bool ring_buffer_emtpy(ring_buffer_t* rb);
bool ring_buffer_write(ring_buffer_t* rb, uint8_t byte);

// Result is for success, insert ptr to read data
bool ring_buffer_read(ring_buffer_t* rb, uint8_t* byte);


#endif // INC_RING_BUFFER_H
