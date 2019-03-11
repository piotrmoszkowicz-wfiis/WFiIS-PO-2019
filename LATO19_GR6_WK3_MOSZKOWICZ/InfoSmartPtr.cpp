#include "InfoSmartPtr.h"

InfoSmartPtr& InfoSmartPtr::operator=(const InfoSmartPtr& ic) {
    del();
    copy(ic);
    return *this;
}

void InfoSmartPtr::copy(const InfoSmartPtr& isp) {
    m_ptr = isp.getPtr();
    m_counter = isp.getCounterPtr();
    (*m_counter)++;
}

void InfoSmartPtr::del() {
    if (*m_counter == 1) {
        delete m_ptr;
        delete m_counter;
    } else {
        (*m_counter)--;
    }
}

