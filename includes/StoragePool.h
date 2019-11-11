#ifndef STORAGEPOOL_H
#define STORAGEPOOL_H
#include "cstdio"   // use the size_t

class StoragePool{
    public:
        using byte = unsigned char;
        virtual ~StoragePool(){};
        /*
         *  Requisita uma quantidade de memoria em bytes a ser alocada e passada como argumento
         *  e retornando o espaço requisitado.
         */ 
        virtual void* Allocate( size_t ) = 0;
        /*
         *  Libera o bloco de memória que se encontra em um endereço passado como parâmetro.
         */
        virtual void Free( void * ) = 0;

};

#endif