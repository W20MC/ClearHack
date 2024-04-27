#include "Hacks.hpp"

Modules& Modules::get() {
    static Modules inst;
    return inst;
}