# Linguagens Formais, Autômatos e Compiladores

## Aula 00
Fortran (1957) foi o primeiro compilador de sucesso comercial (IBM 704)
C for portability
Tipos de processadores de linguagens (CLIMP)
- Compiladores
- Ligadores
- Interpretadores
- Montadores
- Pré-processadores

4 etapas para o código-objeto
: pré-processamento → compilação → assemblagem → linkagem → execução

Interpretador
: Diferente do compilador, o programa é executado a medida que é traduzido, linha por linha.
> I remember when I used to play a little bit with python, some broken bits of my code were never flagged because they were never accessed.

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

O **transpilador** recebe o código-fonte em uma certa linguagem de programação e converte-o em código-fonte de outra linguagem.
O **loader** é responsável por carregar o executável de um código-objeto na memória, e não o compilador.

---
## Aula 01
Alfabeto
: É um conjunto finito de símbolos que são elementos básicos para formar cadeias. É normalmente representado pelo símbolo *Σ*.

São características dos alfabetos: 
- Finitude
- Não-vazio
- Atomicidade
- Unicidade
- Ausência de significado intrínseco

*w* representa uma palavra, e |*w*| representa a quantidade de números utilizados nesta palavra.

## Aula 02
Prefixos da palavra *w* = abcd
<br>&emsp;λ *(prefixo trivial)*, a, ab, abc, *w*
O símbolo λ representa o prefixo trivial

Um **paradigma de programação** é um estilo ou modelo de pensar e estruturar programas, ou seja, um conjunto de conceitos, regras e formas de resolver problemas com uma linguagem de programação.

São paradigmas de programação
- Imperativo (programa como sequência de instruções). *Ex: C, Pascal*
- Declarativa (programador descreve *o que* quer, *não* como) [TALVEZ seja equivalente a uma lookup table. O professor usou o exemplo `fatorial(n, f)`]
- Funcional (baseadas em funções matemáticas, sem estado mutável). *Ex: Haskell, Lisp, F#*.
- Orientadas a objetos (organizadas em classes e objetos, que são representações de abstrações). *Ex. Java, C*.
- Lógicas ()
- Concorrente / paralela (suporta a execução simultânea, a fim de diminuir tempo de execução)

A **linguagem** é um conjunto de cadeias (símbolos) sobre um determinado alfabeto. Pode ser subdividido em linguagens *naturais* ou de *programação*.

## Aula 03
Σ^2 means the dot product (concatenation) *Σ x Σ*, but it can also mean "alphabet with all words of length 2".
Analogicamente, *Σ^(<=3) ≡ Σ^(<3)*  é o alfabeto com todas as palavras de tamanho 2 ou menos.

𝒫(Σ) é o *conjunto das partes* (power set) da linguagem L.

O Fecho de Kleene de um conjunto de palavras (ou de um alfabeto) é o conjunto de todas as sequencias finitas que podem ser formadas a partir das concatenações das linguagens L^n tal que n >= 0, ou seja, todas as palavras de todos os tamanho, ou seja, todas as palavras possíveis de serem formadas a partir de um alfabeto.

{01,1}^* = λ, 01, 1, 0101, 011, 101, 1
> L^0 = λ<br>
> L^1 = 01, 1<br>
> L^2 = 0101, 011, 101, 11<br>
> L^3 = 010101, 01011, 01101, 0111, 10101, 1011, 1101, 111<br>

!! `readall();` is a useful function for the project