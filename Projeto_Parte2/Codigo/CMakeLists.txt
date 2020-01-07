cmake_minimum_required(VERSION 3.14)
project(Proj)

set(CMAKE_CXX_STANDARD 14)

add_executable(Proj main.cpp Imovel.cpp Address.cpp Menu.cpp gerirImoveis.cpp utils.cpp
        gerirAddress.cpp OurCompany.cpp Date.cpp Reserva.cpp Contrato.cpp GerirContratos.cpp
        Erro.cpp gerirReservas.cpp gerirRegistrados.cpp FilesInOut.cpp Pessoa.cpp leilao.cpp leilao.h gerirLeilao.cpp gerirLeilao.h)

