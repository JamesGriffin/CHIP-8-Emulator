#ifndef CHIP_8_H
#define CHIP_8_H

#include <stdint.h>

class Chip8 {
private:
    uint16_t stack[16];                 // Stack
    uint16_t sp;                        // Stack pointer

    uint8_t memory[4096];               // Memory (4k)
    uint8_t V[16];                      // V registers (V0-VF)

    uint16_t pc;                        // Program counter
    uint16_t opcode;                    // Current op code
    uint16_t I;                         // Index register

    uint8_t delay_timer;                // Delay timer
    uint8_t sound_timer;                // Sound timer

    void init();

public:
    uint8_t  gfx[64 * 32];              // Graphics buffer
    uint8_t  key[16];                   // Keypad
    bool drawFlag;                      // Indicates a draw has occurred

    Chip8();
    ~Chip8();

    void emulate_cycle();               // Emulate one cycle
    bool load(const char *file_path);   // Load application
};

#endif // CHIP_8_H