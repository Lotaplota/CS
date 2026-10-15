## Notas
- Modularidade: característica de um software que é constituido por unidades denominadas módulos
- Legibilidade: capacidade de leitura e alguma coisa...
- Encapsulamento: a habilidade de ocultar parte do código

### Java
Linguagem criada em 1991, fortemente baseada em C e C++. O bytecode é uma camada intermediária, onde você cria uma JVM (Java Virtual Machine) faz interface com sistema operacional.
Extensões em .java e .class.
#### Tipos
byte
int
: inteiro de 32 bits

short
inteiro de 16 bits
long
: inteiro de 64 bits
boolean
float
: finaliza com f se não é lido como double
double
: 
char
- String
    é uma classe pré-definida

#### Operadores
Os mesmos do C.

#### Pacotes
Classes são organizadas em pacotes

`static` significa que o método é da classe em si

Atributos de classes
- final
- public
- static
- protected
- static

## Aula 06

Métodos da classe object:
- clone()
- finalize()
- toString()
- hashCode()
- getClass()
- equals()

!! Classes abstratas não possuem instanciações;

## Aula 07
> I didn't actually went to class this day, so this is just me trying to learn at home from the material.

Caixas de diálogo modais são aquelas que não saem da sua tela enquanto você não interagir com elas.

## Aula 10 - Design Patterns
### Padrões criacionais
- **Singleton** garante que uma classe tenha apenas uma instância e fornece um ponto de acesso global a ela.
    `if (instance == null) {return new Singleton}`
- **Factory Method** define uma interface para criar um objeto, mas permite que as subclasses alterem o tipo de objeto que será criado.

### Padrões estruturais
- **Adapter** permite que interfaces incompatíveis trabalhem juntas, convertendo a interface de uma classe em outra que o cliente espera.
- **Facade** fornece uma interface simplificada para um subsistema complexo.

### Padrões comportamentais
- **Observer** define uma dependência um-para-muitos entre objetos, e quando um é alterado, todos os seus dependentes são acionados.
- **State** simula uma máquina com diversos estados possíveis, e em cada um desses estados, a máquina se comporta de uma maneira diferente.
- **Strategy** define classes que possuem uma ação em comum *(ex: `execute()`)*, mas cada uma possui sua maneria própria de manifestar essa ação.
- **Template Method** define o esqueleto de um algoritmo em uma operação, adiando alguns passos para a subclasse(?)