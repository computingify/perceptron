#include "trainer.h"
#include "randomFloat.h"
#include <iostream>
static int count;

trainer::trainer(int width, int height) {
    randomFloat r(width, height);
    x = r.get();
    y = r.get();
    count++;

    // std::cout << "trainer value " << count << " : " << x << " | " << y << std::endl;

    label = -1;
    if (y > f(x)) {
        label = 1;
    }
}

float trainer::f(float x) {
    return x;
}
