#pragma once

namespace Estados{

    class MaquinaEstados;

    enum IDestado{
        none = -1,
        menuPrincipal = 0,
        jogando,
        menuPausa,
        config,
        leaderboard,
        fimDeJogo
    };

    class Estado{
    
    protected:
        MaquinaEstados* pMaqEstado;
        IDestado id;

    public:
        Estado(MaquinaEstados* pMaqEstado = nullptr, Estados::IDestado ID = none);

        virtual ~Estado();

        void setMaquinaEstado(MaquinaEstados* pMaqEStado);

        void mudaEstado(Estados::IDestado novoEstado);

        IDestado getID() const;

        virtual void update(const float dt) = 0;

        virtual void render() = 0;

        virtual void resetaEstado() = 0;

    };
}