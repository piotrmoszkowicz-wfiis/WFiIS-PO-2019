#include "Calc_error.h"

int LicznikPoziomow::level = 0; // Not the most fancy way, but we don't need to make special cpp file for LicznikPoziomow class

void Calc_error::handler() {
    try {
        std::cout << " Zlapano wyjatek:" << std::endl;
        throw;
    } catch (std::runtime_error* err) {
        auto isOut = dynamic_cast<Calc_error*>(err);
        auto nErr = isOut->nextError;
        while (isOut) {
            std::cout << " -- z powodu: " << isOut->what() << std::endl;
            nErr = isOut->nextError;
            delete isOut;
            isOut = dynamic_cast<Calc_error*>(nErr);
            if (!isOut) {
                std::cout << " -- z powodu: " << nErr->what() << std::endl;
                delete nErr;
                break;
            }
        }
    }
}