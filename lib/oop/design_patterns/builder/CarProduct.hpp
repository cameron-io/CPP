#ifndef BUILDER_PATTERN_H
#define BUILDER_PATTERN_H

#include <iostream>
#include <string>
#include <vector>

/*
    Unlike Factory & other patterns, the builders
    can produce unrelated products.

    Thus, the results from builders may not follow the
    same interface
*/
class CarProduct{
public:
    std::string chassis = "";
    std::string drivetrain = "";
    std::string engine = "";
    std::string wheels = "";
    std::string seats = "";
    std::string dashboard = "";
    std::string wiring = "";

    int CountParts() const
    {
        std::string parts[7] = {
            this->chassis,
            this->drivetrain,
            this->engine,
            this->wheels,
            this->seats,
            this->dashboard,
            this->wiring
        };

        int c = 0;
        for (std::string p : parts) {
            if (p != "") c++;
        }
        return c;
    }
};

#endif