# FORMARQ
Este projeto consiste em desenvolver um programa chamado FORMARQ, cujo objetivo é converter tipos de arquivo, isto é, um arquivo é lido, e é gerado um segundo arquivo, cujo conteúdo é função do conteúdo do primeiro, mas em outro formato. O FORMARQ deverá dar suporte a 3 tipos de conversão:

INVERT

  CN = ~CV (Carácter novo é o complemento de um do carácter velho)

CRIPT

  O usuário fornece uma palavra para funcionar como chave, isto é, o código ASCII de cada caracter da chave é máscara para uma operação XOR (ou exclusivo) com o byte lido do arquivo lido. Por exemplo:

  Conteúdo do arquivo de entrada: BOM DIA, PESSOAL.
  Chave: GAVETA.
  Arquivo de saída:
  ‘B’ ^ ‘G’;
  ‘O’ ^ ‘A’;
  ‘M’ ^ ‘V’;
  ‘ ‘ ^ ‘E’;
  ‘D’ ^ ‘T’;
  ‘I’ ^ ‘A’;
  ‘A’ ^ ‘G’;
  ‘,’ ^ ‘A’;
  ‘ ‘ ^ ‘V’;
  ‘P’ ^ ‘E’;
  ‘E’ ^ ‘T’;
  ‘S’ ^ ‘A’;
  ‘S’ ^ ‘G’;
  ‘O’ ^ ‘A’;
  ‘A’ ^ ‘V’;
  ‘L’ ^ ‘E’;
  ‘.’ ^ ‘T’;

  O caminho de volta é simples: o usuário fornece a chave e as mesmas operações são feitas, fazendo com que o arquivo original seja recuperado.

UNIX to DOS

  Arquivos texto no DOS, o ‘\n’ é representado pelo par de caracteres CR/LF, isto é, 0x0D seguido de 0x0A, enquanto que no UNIX, basta o caracter LF, isto é, 0x0A. Neste modo, os arquivos texto para UNIX deverão ser convertidos para o padrão DOS, ou seja, sempre que for lido um 0x0A, inserir antes um 0x0D. Pode-se desejar também a conversão oposta, isto é, de DOS para UNIX.




O FORMARQ deve ser chamado pela linha de comando pela seguinte sintaxe:

 FORMARQ <nome_do_arquivo> [I][C][D][U]        [chave]
I:    O tipo de conversão deve ser o Invert.
C:    O tipo de conversão deve ser o Cript.
D:    Arquivo texto UNIX, gerar arquivo texto DOS.
U:    Arquivo texto DOS, gerar arquivo texto UNIX.

Obs.: A chave só deverá ser exigida para a conversão Cript. Levar isso em consideração na hora de consistir os parâmetros de entrada. O usuário deve escolher somente um dos métodos de conversão.

Conversão Invert:
É um tipo de conversão que se for feita duas vezes, o arquivo volta à forma original. Assim, adotaremos o seguinte critério: o arquivo resultante da 1ª conversão deverá ter como extensão “.INV”. Se for invertido o arquivo “dados.DAT”, deverá ser gerado o arquivo “dados.INV”. Se for invertido o arquivo “dados.INV”, será gerado o arquivo “dados.DNV”, igual ao original (“.DNV” é a extensão do arquivo “desinvertido”).

Conversão Cript:
Deve gerar um arquivo com extensão “.CRP”. O caminho inverso pode ser feito: criptografar o criptografado com a mesma chave.

Ex.: foi criptografado o arquivo “dados.DAT”, gerando assim o arquivo “dados.CRP”. Para descriptografar, vamos criptografar novamente “dados.CRP” com a mesma chave, gerando assim o arquivo “dados.DRP”. (“.DRP” é a extensão do arquivo “descriptografado”).

Obs.: a chave é como uma senha para o usuário.

UNIX to DOS:
Seja qual for a extensão do arquivo texto para UNIX, o arquivo para DOS deverá ter como extensão “.DOS”. Ao se fazer o processo inverso, o arquivo para UNIX deverá ter a extensão “.UNX”.

Todas essas características devem ser checadas antes de proceder qualquer conversão, e sempre que for constatada qualquer anormalidade, o programa FORMARQ deve ser cancelado, notificando o usuário com mensagens. Ex.: o arquivo de entrada não existe.

O usuário deve escolher um único tipo de conversão, caso contrário, cancelar o programa, notificando o usuário com mensagens. Além disso, o tipo de conversão escolhido deve estar entre os citados. Ex.:

$ FORMARQ    dados.DAT    G

O tipo de conversão G não existe, portanto, o programa deve ser cancelado.
