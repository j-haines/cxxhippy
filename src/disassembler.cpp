#include "disassembler.hpp"

#include <fmt/core.h>

#include "mem.hpp"

namespace cxxhippy {

void disassembler::disassemble() const {
    if (auto membuffer = membuffer_.lock()) {
        disassemble_locked(std::move(membuffer));
    }
}

void disassembler::load(memory_space::shared_ptr_t buffer) {
    membuffer_ = buffer;
}

void disassembler::disassemble_locked(memory_space::shared_ptr_t&& membuffer) const {
    for (auto program_counter = 0; program_counter < kMaxMemoryBytes; ++program_counter) {
        auto opcode = membuffer->read_byte(program_counter);

        fmt::print("{:04x} {:02x} {:02x} ", program_counter, opcode, membuffer->read_byte(program_counter+1));
        disassemble_word(opcode);
        fmt::print("\n");

        ++program_counter;
    }
}

void disassembler::disassemble_word(memory_space::word_t word) const {
    auto msb = word >> 8;
    auto lsb = word & 0xff;
    auto nibble = word >> 12;

    switch (nibble) {
        case 0x00:
        case 0x01:
        case 0x02:
        case 0x03:
        case 0x04:
        case 0x05:
            fmt::print("unhandled");
            break;
        case 0x06: {
            auto reg = msb & 0x0f;
            fmt::print("{:-10s} V{:01X},#${:02x}", "LD", reg, lsb);
            break;
        }
        case 0x07:
        case 0x08:
        case 0x09:
            fmt::print("unhandled");
            break;
        case 0x0a: {
            auto address = msb & 0x0f;
            fmt::print("{:-10s} I,#${:01x}{:02x}", "LD", address, lsb);
            break;
        }
        case 0x0b:
        case 0x0c:
        case 0x0d:
        case 0x0e:
        case 0x0f:
        default:
            fmt::print("unhandled");
            break;
    }
}

}
