# SA-MP Advanced Hunting System

*Hunter System - Sistema de Caça para SA-MP*

Este é um sistema de caça para SA-MP (San Andreas Multiplayer) que permite aos jogadores participar de atividades de caça no servidor.

## Dependências

Este sistema requer as seguintes dependências:

### Streamer Plugin v2.9.6 v1.0.0
- Download: [Streamer Plugin](https://github.com/samp-incognito/samp-streamer-plugin/releases)

### YSI-Includes
- Download: [YSI-Includes](https://github.com/pawn-lang/YSI-Includes)

### Pawn.CMD 3.4.0
- Download: [Pawn.CMD](https://github.com/katursis/Pawn.CMD/releases)

## Configuração

O sistema pode ser configurado editando as constantes e parâmetros no arquivo `HunterSystem.inc`. Abaixo estão as principais configurações disponíveis:

### Constantes Principais

```pawn
// Número total de posições de animais disponíveis no mapa
#define     E_HUNTER_ANIMAL_COUNT 168

// Modelo 3D usado para os animais
static const E_HUNTER_MODEL_ANIMAL = 19315;

// Tempo em segundos para coletar recursos do animal
static const E_HUNTER_ANIMAL_TIMER = 20;

// Preço de venda por unidade de carne
static const E_HUNTER_PRICE_MEAT = 50;
```

### Posições dos Animais

O sistema utiliza 168 posições pré-definidas para o aparecimento dos animais. Estas posições estão configuradas no array `E_HUNTER_ANIMAL_POS`. Você pode modificar estas coordenadas para adaptar o sistema à sua área de caça preferida.

### Estados dos Animais

O sistema gerencia diferentes estados para os animais:

```pawn
enum {
    HUNTER_STATE_LIFE = 0,  // Animal vivo
    HUNTER_STATE_DEATH = 1,   // Animal abatido
    HUNTER_STATE_OPEN = 2     // Animal sendo processado
}
```

### Comandos Disponíveis

O sistema implementa os seguintes comandos:

- `/assobiar` - Atrai um animal para caçar
- `/vcarne` - Vende toda a carne coletada

### Personalização Adicional

Você pode personalizar ainda mais o sistema modificando:

1. **Mensagens**: Personalize as mensagens exibidas durante a caça
2. **Recompensas**: Ajuste o sistema de recompensas e preços

Para implementar mudanças mais avançadas, você pode modificar as funções principais como `CreateAnimalHunter()`, `DestroyAnimal()`, e `GivePlayerMeat()`.

## Uso

### Como Caçar

1. **Iniciar a Caça**: Use o comando `/assobiar` para atrair um animal. Um animal aparecerá em uma das 168 posições pré-definidas no mapa.

2. **Abater o Animal**: Use a arma fornecida (Rifle de Caça - ID 34) para atirar no animal. Após um tiro bem-sucedido, o animal cairá no chão.

3. **Coletar Recursos**: Aproxime-se do animal abatido para iniciar automaticamente o processo de coleta. Uma animação será exibida e após 20 segundos (configurável), você receberá a carne do animal.

4. **Vender a Carne**: Use o comando `/vcarne` para vender toda a carne coletada. Você receberá $50 (configurável) por unidade de carne.

### Indicadores Visuais

- **Animal Vivo**: O animal aparecerá em pé na posição gerada
- **Animal Abatido**: O animal estará caído no chão e um checkpoint será criado
- **Coleta em Andamento**: Uma animação será exibida e uma ferramenta será anexada ao jogador
- **Carne Coletada**: Um objeto de carne será anexado ao jogador (slot 8)

### Dicas

- Você só pode caçar um animal por vez
- A posição do animal é aleatória entre as 168 posições disponíveis
- Venda a carne coletada para liberar espaço e ganhar dinheiro

## Licença

Este projeto está disponível para uso em servidores SA-MP sob as seguintes condições:

- Você pode utilizar, modificar e distribuir este sistema em seu servidor
- Você deve manter os créditos originais no código-fonte
- Você não pode vender este sistema ou incluí-lo em pacotes comerciais sem autorização
- Modificações e melhorias são encorajadas, mas devem ser compartilhadas com a comunidade quando possível

### Contribuição

Contribuições para melhorar este sistema são bem-vindas! Se você tiver melhorias ou correções:

1. Faça um fork do repositório (se disponível)
2. Implemente suas mudanças
3. Envie um pull request ou compartilhe suas modificações com a comunidade
