#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

#include "include/mmu.h"
#include "include/memory-map.h"

void fill_memory(unsigned memory_map_size);
void query_memory(unsigned queries);

int main()
{
    unsigned memory_map_size;
    unsigned queries;
    uint64_t root_table_addr;

    scanf("%u %u %" SCNu64 "\n", &memory_map_size, &queries, &root_table_addr);

    fill_memory(memory_map_size);
    set_root_table_addr(root_table_addr);
    query_memory(queries);

    return 0;
}

void fill_memory(unsigned memory_map_size)
{
    uint64_t physical_addr;
    uint64_t memory_value;
    while (memory_map_size--)
    {
        scanf("%" SCNu64 "%" SCNu64 "\n", &physical_addr, &memory_value);
        set_addr_value(physical_addr, memory_value);
    }
}

void query_memory(unsigned queries)
{
    uint64_t logical_addr;
    uint64_t physical_addr;
    while (queries--)
    {
        scanf("%" SCNu64 "\n", &logical_addr);

        if (!get_physical_addr(logical_addr, &physical_addr))
        {
            puts("fault");
            continue;
        }

        if (!has_addr(physical_addr))
        {
            puts("0");
        }

        uint64_t value = get_memory_value(physical_addr);
        printf("%lu\n", value);
    }
}
