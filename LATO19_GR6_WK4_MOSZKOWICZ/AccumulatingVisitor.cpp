#include "AccumulatingVisitor.h"
#include "ElData.h"

void AccumulatingVisitor::visit(IntData* d) noexcept {
    float toAdd = static_cast<float>(d->get());
    m_sum += toAdd;
};

void AccumulatingVisitor::visit(FloatData* d) noexcept {
    m_sum += d->getFloat();
};