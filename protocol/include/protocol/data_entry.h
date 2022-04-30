/*
 * Copyright (c) 2022 Tim Herreijgers
 */

#pragma once

#include "data_types.h"

class DataEntry
{
public:
    DataType type();

    template<class T>
    T as()
    {
        return 10;
    }
};
