/*
 * Copyright (c) 2022 Tim Herreijgers
 */

#pragma once

#include "data_types.h"

class DataEntry
{
public:
    DataEntry(DataType type, void *data);

    DataType type();

    template<class T>
    T as()
    {
        return *((T *) m_data);
    }

private:
    DataType m_type;
    void *m_data;
};
