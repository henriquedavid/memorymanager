#ifndef SLPOOL_H
#define SLPOOL_H

#include <new>      // std::bad_alloc()
#include <cmath>    // std::ceil()
#include <iomanip>  // std::setw(), std::setfill()
#include <iostream>
#include <cstring>

#include "StoragePool.h"
namespace MemoryPool
{
    class SLPool : public StoragePool
    {
    public:

        // Construtores e destrutor

        explicit SLPool(size_t);
        ~SLPool();

        // Métodos que podem ser chamados pelo cliente

        void * Allocate( size_t );
        void Free( void * );
        void storageView();

        friend std::ostream& operator<<(std::ostream& os, SLPool& pool)
        {
            pool.storageView();
            return os;
        }


    private:

        // Estruturas internas (desconhecidas pelo cliente)

        struct Header
        {
            unsigned m_lenght;
            Header() : m_lenght(0u) {}
        };
        struct Block : Header
        {
            enum {BlockSize = 16};
            union{
                Block* m_next;
                unsigned char m_raw[BlockSize - sizeof(Header)];
            };

            Block() : m_next( nullptr ) { /* Empty */}
        };

        Block* m_sentinel;
        Block* m_pool;

        bool verificaLivre(Block * block_);

    };
}
#endif