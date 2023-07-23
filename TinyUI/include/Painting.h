#ifndef TINYUI_PAINTING_H
#define TINYUI_PAINTING_H

#include <cstdint>

namespace tiny::painting {

    enum class Colors {
        black = 0,
        white = 1,
        inverse = 2,
    };

    struct Paint {
        Colors color = Colors::white;
        int strokeWidth = 1;
    };

} // painting

#endif //TINYUI_PAINTING_H
