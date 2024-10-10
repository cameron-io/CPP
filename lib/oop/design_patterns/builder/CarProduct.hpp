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
    std::vector<std::string> parts;

    void ListParts() const
    {
        std::cout << "Product materials:\n";
        
        for (int i = 0; i < parts.size(); i++) {
            std::cout << "-> " << parts[i] << "\n";
        }

        std::cout << "\n" << std::endl;
    }
};

#endif