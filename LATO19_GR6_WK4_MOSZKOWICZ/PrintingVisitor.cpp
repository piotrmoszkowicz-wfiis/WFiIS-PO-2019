#include "PrintingVisitor.h"
#include "ElData.h"

void PrintingVisitor::visit(IntData* d) noexcept {
    std::cout << " " << d->get();
};

void PrintingVisitor::visit(FloatData* d) noexcept {
    std::cout << " " << d->getFloat();
};