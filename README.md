# Museu Multitemático

## Descrição
O Museu Multitemático é um software desenvolvido em C para gerenciamento de um museu fictício. Ele oferece funcionalidades como venda de ingressos, exposição de temas culturais, exibição de obras e coleta de dados de visitantes.

## Funcionalidades

1. **Apresentação dos Temas:** Conheça os temas culturais em destaque no museu, como "100 Anos da Semana de Arte Moderna", "150 Anos de Santos Dumont", "Jogos Olímpicos de Paris 2024" e "Copa do Mundo Catar 2022".

2. **Venda de Ingressos:** Realize a compra de ingressos, informando seus dados como nome, idade e escolha de tema.

3. **Exibição das Obras:** Explore as exposições relacionadas aos temas escolhidos pelos visitantes em um menu intuitivo.

4. **Lista de Ingressos Comprados:** Visualize a lista de ingressos adquiridos, contendo informações como nome, idade, tema escolhido, código do bilhete e status.

5. **Questionário Interativo:** Responda a questionários relacionados a cada obra visitada.

## Pré-requisitos

1. **Compilador C:** Certifique-se de ter um compilador C instalado. Recomenda-se o GCC (GNU Compiler Collection). Se não estiver instalado, você pode baixá-lo <a href="https://sourceforge.net/projects/mingw/">aqui.</a>

2. **Ambiente de Desenvolvimento:** Utilize um ambiente de desenvolvimento que permita a execução de comandos no terminal. Recomenda-se utilizar um terminal.

## Passo a passo

1. Clone o repositório:
```bash
git clone https://github.com/LMoont/ProjetoMuseuCultural.git
cd MuseoSync
```
2. Compile o programa:
```bash
gcc -o MuseoSync main.c bilheteria.c entrada_temas.c arte_moderna.c santos_dumont.c olimpiadas.c copa_catar.c
```

3. Execute o programa:
```bash
./MuseoSync
```

## Demonstração

![MuseoSync_i5xNLhLPgr](https://github.com/LMoont/ProjetoMuseuCultural/assets/116237450/db973412-fc1c-4c3f-a73a-6970f3a76c23)

## Contribuição
Contribuições são bem-vindas! Sinta-se à vontade para abrir issues ou enviar pull requests.

## Licença
Este projeto está licenciado sob a [MIT License](LICENSE).

