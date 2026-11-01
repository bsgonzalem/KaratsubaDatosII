#include <iostream>
#include <vector>
#include "brute_force.hpp"

struct Instance {
    std::string name;
    std::string targetHash;
    std::string alphabet;
    int minLength;
    int maxLength;
};

int main() {

    std::vector<Instance> instances = {

        // Instancia de referencia
        {
            "Reference",
            "8d51feb34e3e69f6fa6dffc577e2c60490cf9a7fcd835f9f6af1505b71d74773",
            "abcdefghijklmnopqrstuvwxyz0123456789",
            5,
            5
        },

        // Instancia 1
        {
            "Instance 1",
            "66e1d4275a8a5fd2217668edc4c54b6c829ff6d6d494f7e7511893d203563675",
            "abcdefghijklmnopqrstuvwxyz0123456789",
            4,
            4
        },

        // Instancia 2
        {
            "Instance 2",
            "d1a9abb327ce2e38e015c7a5281b22a20a9c17995d229236fc4be4bffcf55bfb",
            "abcdefghijklmnopqrstuvwxyz0123456789",
            4,
            4
        },

        // Instancia 3
        {
            "Instance 3",
            "6ad8c85bcc833fefa084eaec1f4a09bf202e980101ac3519d161fd1d7aa2abc2",
            "abcdefghijklmnopqrstuvwxyz0123456789",
            5,
            5
        },

        // Instancia 4
        {
            "Instance 4",
            "98578d7a24c39dc99afd0582bfd0ba4308afb16e12ca5bb52b6fb1f9f65c85b7",
            "abcdefghijklmnopqrstuvwxyz0123456789",
            5,
            5
        },

        // Instancia 5
        {
            "Instance 5",
            "fdd4d308ba56aca1ca0b17461a19bd39a95dc80027d242b6ae64d69a83c7cba6",
            "abcdefghijklmnopqrstuvwxyz0123456789",
            6,
            6
        }
    };


    for (const Instance& instance : instances) {

        std::cout << "\n=============================\n";
        std::cout << instance.name << std::endl;
        std::cout << "=============================\n";

        BruteForce::Algorithm bruteForce;

        std::string result = bruteForce.find(
            instance.targetHash,
            instance.alphabet,
            instance.minLength,
            instance.maxLength
        );

        if (!result.empty()) {
            std::cout << "Result: Found" << std::endl;
            std::cout << "Password: " << result << std::endl;
        } else {
            std::cout << "Result: Not found" << std::endl;
        }

        std::cout << "Candidates evaluated: "
                  << bruteForce.getCandidates()
                  << std::endl;

        std::cout << "Execution time: "
                  << bruteForce.getTime() * 1000
                  << " ms"
                  << std::endl;
    }

    return 0;
}