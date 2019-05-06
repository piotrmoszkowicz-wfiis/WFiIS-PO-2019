#include "lab08.h"

void ObiektMiotajacy::Rzuc() const  {
    throw new ExceptType4(this);
}