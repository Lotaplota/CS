Fortran (1957) foi o primeiro compilador de sucesso comercial (IBM 704)
C for portability
Tipos de processadores de linguagens (CLIMP)
- Compiladores
- Ligadores
- Interpretadores
- Montadores
- Pré-processadores

4 etapas para o código-objeto
**pré-processamento → compilação → assemblagem → linkagem → execução**
---
Interpretador
: Diferente do compilador, o programa é executado a medida que é traduzido, linha por linha.
> I remember when I used to play a little bit with python, some broken bits of my code were never flagged because they were never accessed.
---
Linkador
: Combina vários arquivos objeto gerados pelo montador em um único executável.

Este é responsável por **combinar todas as partes compiladas** + **resolver referências entre essas partes** + **ajustar endereços e relocação** + **gerar o código binário final**
SSão funções dos ligadores:
- Resolução de símbolos (`extern int x`, por exemplo)
- Ajustar endereços absolutos
- Montagem do segmento e imagem finais
- Inclusão de bibliotecas

Pré-processador
: É a limpeza inicial do código-fonte, definindo constantes e macros, desativando partes não-executáveis and fodder like whitespaces and comments.

**!!** O código `gcc -E arquivo.c - o arquivo.i` roda a etapa de pré-processamento, sem compilar o `arquivo.i` gerado.