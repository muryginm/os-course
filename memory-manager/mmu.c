#include "include/mmu.h"

void set_root_table_addr(uint64_t root_table_addr)
{

}

bool get_physical_addr(uint64_t logical_addr, uint64_t *physical_addr)
{
    *physical_addr = logical_addr;

    return true;
}
