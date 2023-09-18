#include "hyComponent.h"


namespace hy
{
    Component::Component(COMPONENTTYPE type)
        : mType(type)
        , mOwner(nullptr)
    {
    }

    Component::~Component()
    {
    }
}
