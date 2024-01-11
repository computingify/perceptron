#ifndef TRAINER_H
#define TRAINER_H

#include <vector>

class trainer {
public:
    trainer(unsigned int width, unsigned int height);

    virtual ~trainer() = default;

private:
    float x;
    float y;
    int label;

};
#endif // TRAINER_H