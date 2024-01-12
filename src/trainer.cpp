#include "trainer.h"
#include "randomFloat.h"
#include <iostream>

trainer::trainer(unsigned int width, unsigned int height) {
    randomFloat r(width, height);
    x = r.get();
    y = r.get();

    label = -1;

    std::cout << "trainer value : " << x << " | " << y << std::endl;
    if (x > y) {
        label = 1;
    }
}
