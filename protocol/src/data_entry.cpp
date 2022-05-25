#include "protocol/data_entry.h"

DataEntry::DataEntry(DataType type, void *data): m_type(type), m_data(data)
{

}


DataType DataEntry::type()
{
    return m_type;
}
