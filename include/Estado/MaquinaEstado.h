#pragma once

#include "Estado.h"
#include <map>

namespace Estados{

    class MaquinaEstados{

    protected:
        Estados::IDestado idEstadoAtual;
        Estados::IDestado idUltimoEstado;

        std::map<IDestado,Estado*> mapaEstados;

    public:
        MaquinaEstados();

        virtual ~MaquinaEstados();

        void mudaEstadoAtual(Estados::IDestado ID);

        void atualizaEstadoAtual(const float dt);

        void renderizaEstadoAtual();

        Estados::IDestado getIDEstadoAtual() const;

        void insereEstadoAtual(Estados::Estado* pEstado);

        Estados::IDestado getUltimoID() const;        

    };
}