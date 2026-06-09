# TP01 - Manipulando arquivos

Este programa foi elaborado com o intuito de processar os dados contidos em arquivos `.csv` na pasta `/data/`. É capaz de criar um arquivo de resumo *(resumo.csv)* dos dados ou filtrá-los pelo município inserido pelo usuário no console, devolvendo um arquivo *(MUNICIPIO.csv)* com todas as ocorrências referentes ao município.

## Execução
### Criando o resumo
&emsp;O programa acessa a pasta `/data/` e conta todos os arquivos `.csv` nela contidos, guardando os seus nomes em um vetor. A partir deste vetor, cria um novo arquivo denominado `dados.csv`, acessa os dados de cada um dos arquivos e os concatena ao `dados.csv`, evitando reescrever o cabeçalho de cada arquivo.
&emsp;A partir dos dados armazenados nesse arquivo, o programa tentará criar o arquivo `resumo.csv`. O programa lerá, linha por linha, o arquivo com os dados, armazenando o valor da sigla da instituição à qual os dados da linha se referem. Até que o programa identifique uma mudança dessa sigla, ele adiciona os valores dos campos numéricos a um somatório e passa para a linha seguinte. Ao identificar uma mudança de sigla, ele adiciona os valores dos somatórios a uma linha e a insere no arquivo `resumo.csv`. Em seguida, o valor da nova sigla é armazenado e o programa se baseia nela para continuar este ciclo.
&emsp;Lidas todas as linhas dos dados, o programa registra as informações da última instutição e fecha o arquivo.
### Gerando arquivos de municípios
&emsp;Assim que o programa encerra a criação dos arquivos anteriores, o programa entrará em um loop, pedindo para que o usuário insira o nome de um município para filtrar suas ocorrências. A depender da entrada do usuário, o programa pode reagir de três maneiras:
- Ao receber o nome de um município que consta nos dados, o programa gerará um arquivo nomeado `MUNICIPIO.csv` contendo todas as ocorrências deste município. A geração deste arquivo é simples, pois o programa abre o arquivo `dados.csv` em modo leitura, e o `MUNICIPIO.csv` em modo escrita. Para cada linha lida, ele verifica se o campo `municipio_oj` equivale ao nome do município. Se sim, adiciona-a ao arquivo, se não, passa para a próxima. O programa então torna a pedir outro valor para o usuário.
- Ao receber o nome de um município que não consta nos dados, o programa apenas informa o usuário que não há nenhuma ocorrência para o município informado.
- Ao receber a palavra `sair`, o programa se encerra.

## Structs
### `LinhaDados`
Comporta todos os valores contidos em uma linha dos arquivos `.csv`.
Os nomes de suas variáveis estão de acordo com as chaves dos arquivos de dados, para facilitar o seu uso.

### `Somas`
Comporta os somatórios necessários para a montagem de um [`LinhaResumo`](#linharesumo).
É inicializado com todos os seus valores sendo 0, exceto a variável `sigla_tribunal`, que é inicializada como `NULL`, pois comportará a string referente ao nome do tribunal.
Ao ser utilizada, deve ser resetada logo em seguida para armazenar novos valores.
Os nomes de suas variáveis estão de acordo com as chaves necessárias para o cálculo dos valores no arquivo `resumo.csv`, para facilitar o seu uso.

### `LinhaResumo`
Comporta os valores a serem escritos em uma nova linha do arquivo `resumo.csv`.
Seus dados são inseridos a partir da função [`MontarLinhaResumo()`](#montarlinharesumo).

## Funções principais
### `ConcatArquivos()`
*`int ConcatArquivos(char * pasta)`*
*Recebe o nome da pasta que contém os dados e devolve a quantidade de arquivos concatenados com sucesso.*
&emsp;Primeiro armazena os nomes dos arquivos `.csv` detectados, e então, através de um loop, acessa cada um desses arquivos, concatenando-os ao arquivo `dados.csv`, que possui o mesmo cabeçalho.
&emsp;Todos os cálculos e processamentos que o programa faz utilização os dados *deste arquivo* em específico, evitando assim outros loops pelos arquivos da pasta `/data/`.

### `GerarResumo()`
*`void GerarResumo(int qt_arquivos)`*
*Recebe a quantidade de arquivos a serem lidos.*
&emsp;Esta função abre o arquivo `dados.csv` em modo leitura, e o `resumo.csv` em modo escrita. Ela guarda na variável `ultima_sigla` a sigla da linha atual que está lendo.
&emsp;Cria o struct [`Somas`](#somas) para adicionar os valores numéricos de cada linha, [`LinhaDados`](#linhadados) para armazenar os dados lidos, e [`LinhaResumo`](#linharesumo) para armazenar os dados a serem escritos.
&emsp;Para cada LinhaDados lida, uma comparação com a `ultima_sigla` é feita. Se for equivalente, os dados são adicionados ao [`Somas`](#somas). Ao detectar uma mudança na sigla, os dados armazenados no [`Somas`](#somas) são passados para o [`LinhaResumo`](#linharesumo), seus valores são resetados, e a [`LinhaResumo`](#linharesumo) é escrita no arquivo `resumo.csv`.
&emsp;Assim que todas as linhas são lidas, a função fecha os arquivos e se encerra.

### `GerarOcorrencias()`
*`char * GerarOcorrencias(char * municipio)`*
*Recebe o nome do município inserido pelo usuário e retorna uma frase informando se a função foi executada corretamente.*
&emsp;A função recebe o nome do município a partir da entrada do usuário, abre o arquivo `dados.csv` em modo leitura, e o arquivo `MUNICIPIO.csv`(o nome do arquivo depende da entrada do usuário) em modo de escrita. Em seguida, compara o valor da variável `municipio_oj` da linha atual com o nome informado. Caso sejam equivalentes, transcreve toda a linha para o arquivo `MUNICIPIO.csv`.
A função incrementa a variável `qt_ocorrencias` sempre que detecta uma equivalência. Caso nenhuma ocorrência seja detectada, o programa informa o usuário de que não foram encontradas ocorrências. 
&emsp;Assim que todas as linhas são lidas, a função retorna uma frase informando a execução da função, fecha os arquivos e se encerra.

## Funções auxiliares
### `terminaCom()`
*`int terminaCom(char * extensao, char * nome)`*
Verifica se os últimos caracteres da string `nome` equivalem aos caracteres da string `extensao`.
É chamada na função [`GetNomesArquivos()`](#getnomesarquivos).

### `GetNomesArquivos()`
*`int GetNomesArquivos(char * pasta, char vtr[MAX_ARQUIVOS][TAM_NOME_ARQUIVO])`*
Acessa a `pasta` e adiciona os nomes de todos os arquivos com extensão `.csv` nela contidos ao vetor bidimensional `vtr`.
Utiliza a biblioteca `dirent.h` para processar os dados da pasta.
É chamada na função [`ConcatArquivos()`](#concatarquivos).

### `MontarLinhaResumo()`
*`void MontarLinhaResumo(LinhaResumo * lr, char * sigla, Somas sms)`*
Recebe um [`Somas`](#somas) e transfere seus valores para seus respectivos campos no[`LinhaResumo`](#linharesumo). Também escreve o nome da `sigla` atual.
É chamada na função [`GerarResumo()`](#gerarresumo).

### `IncrementarSomatorios()`
`void IncrementarSomatorios(Somas * sms, LinhaDados Dds)`
Incrementa os valores do [`Somas`](#somas) com os valores do [`LinhaDados`](#linhadados) atual.
É chamada na função [`GerarResumo()`](#gerarresumo).