#include <common-defines.h>
#include <libopencm3/stm32/memorymap.h>
#include <libopencm3/cm3/vector.h>

#define BOOTLOADER_SIZE             (0x8000U)
#define MAIN_APP_START_ADDRESS      (FLASH_BASE + BOOTLOADER_SIZE)


static void jump_to_main(void) {
    // typedef void (*void_fn)(void);
    //
    // uint32_t* reset_vector_entry = (uint32_t*)(MAIN_APP_START_ADDRESS + 4U);
    // uint32_t* reset_vector = (uint32_t*)(*reset_vector_entry);
    // void_fn jump_fn = (void_fn)reset_vector;

    // jump_fn();

    vector_table_t* main_vector_table = (vector_table_t*)MAIN_APP_START_ADDRESS;
    main_vector_table->reset();

}

int main(void) {
    jump_to_main();

    return 0;
}
