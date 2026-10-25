# Plano e Casos de Teste — Gest

Gerenciador de Manutenção de Equipamentos de um Laboratório (C, lista simplesmente encadeada).

Este documento descreve **como o projeto foi testado** e registra os resultados. Os testes estão organizados em três camadas:

| Camada | O que verifica | Onde está |
| :--- | :--- | :--- |
| 1. Testes automáticos | Lógica das bibliotecas (inserção ordenada, busca, remoção, validações, liberação) | `tests/test_lista.c` |
| 2. Testes manuais (roteiro) | Comportamento do menu e das entradas do usuário | Seção 3 deste documento |
| 3. Verificação de memória | Vazamentos e acessos inválidos à memória | Seção 4 deste documento e `tests/entradas/` |

---

## 1. Ambiente de teste

Preencha antes de executar:

| Item | Valor |
| :--- | :--- |
| Sistema operacional | |
| Compilador e versão (`gcc --version`) | |
| IDE / terminal | |
| Data da execução | |
| Responsável | |

---

## 2. Testes automáticos (`tests/test_lista.c`)

O arquivo inclui as bibliotecas do projeto e verifica o resultado de cada função com `CHECK(...)`, que imprime `[OK]` ou `[FALHOU]` e mostra a linha do erro. O programa termina com código `0` somente se todas as verificações passarem.

**Compilar** (a partir da raiz do projeto):

```
gcc -g -Wall tests/test_lista.c -o tests/test_lista
```

**Executar:**

```
./tests/test_lista          (Linux / WSL)
tests\test_lista.exe        (Windows)
```

**O que é coberto:**

| Grupo | Verificações |
| :--- | :--- |
| Criação e lista vazia | `CriaLista`, `VaziaLista`, busca em lista vazia |
| Inserção ordenada | primeiro item, fim, início, meio, entrada desordenada |
| Dados gravados | campos do nó, nome com 20 caracteres (limite) |
| Busca | posição (`Achapos`), `BuscaItem` com código existente e inexistente |
| Remoção | primeiro, meio, último, único item, lista vazia, reutilização da lista |
| Edição | alteração de prioridade e período, código inexistente |
| Validações | código de solicitação (limites 1 e 9999, repetido), código do equipamento, prioridade × período (limites 7/8, 15/16, 20/21), retorno do `scanf` |
| Fila de manutenção | a lista principal não é alterada pela operação |
| Liberação | `XapiskaLista` com lista vazia, 1 item e 200 itens |

**Limitação conhecida:** `ListaManutencao` imprime a fila e libera a lista temporária, então a **ordem** da fila é verificada nos casos manuais CT-31 a CT-33 (e o teste automático confere que a lista principal permaneceu intacta).

**Resultado da última execução:**

| Total | Passaram | Falharam |
| :---: | :---: | :---: |
| | | |

---

## 3. Testes manuais (roteiro)

**Como usar:** execute o programa, siga a coluna *Passos* e compare com *Resultado esperado*. Anote o que aconteceu e marque o status (✔ passou / ✘ falhou).

Menu do sistema: `1` criar · `2` apagar · `3` consultar · `4` editar · `5` fila de manutenção · `6` exibir todas · `0` sair.

### 3.1 Menu e encerramento

| ID | Passos | Resultado esperado | Obtido | Status |
| :--- | :--- | :--- | :--- | :---: |
| CT-01 | Digitar `9` no menu | Mensagem de código inválido; o menu é exibido de novo | | ☐ |
| CT-02 | Digitar `abc` no menu | Mensagem de entrada inválida e nova tentativa, sem travar | | ☐ |
| CT-03 | Digitar `0` e responder `n` | Volta ao menu sem encerrar | | ☐ |
| CT-04 | Digitar `0` e responder `s` | Mostra "Até mais!" e encerra | | ☐ |

### 3.2 Criar solicitação (opção 1)

| ID | Passos | Resultado esperado | Obtido | Status |
| :--- | :--- | :--- | :--- | :---: |
| CT-05 | Código `1407`, equipamento `OSC023`, nome `Osciloscopio`, prioridade `2`, período `10` | Solicitação criada; aparece na opção 6 com os mesmos dados | | ☐ |
| CT-06 | Repetir o código `1407` | Mensagem de código já existente; pede o código novamente | | ☐ |
| CT-07 | Código `0` | Mensagem de formato incorreto; pede novamente | | ☐ |
| CT-08 | Código `10000` | Mensagem de formato incorreto; pede novamente | | ☐ |
| CT-09 | Código `abc` e, em seguida, `xyz`, e então `25` | Cada tentativa inválida gera aviso; o programa **não trava** e aceita `25` | | ☐ |
| CT-10 | Equipamento `OS1023` | Entrada inválida; pede o código do equipamento novamente | | ☐ |
| CT-11 | Equipamento `OSC023` na primeira tentativa | Aceito **sem** pedir uma segunda digitação | | ☐ |
| CT-12 | Prioridade `1` com período `8` | Recusado (limite da prioridade 1 é 7 dias); pede novamente | | ☐ |
| CT-13 | Prioridade `3` com período `20` | Aceito (limite da prioridade 3) | | ☐ |
| CT-14 | Prioridade `5` | Recusada; pede novamente | | ☐ |
| CT-15 | Nome com exatamente 20 caracteres (`12345678901234567890`) | Aceito e exibido por inteiro | | ☐ |
| CT-16 | Criar os códigos `30`, `10`, `20` nessa ordem e usar a opção 6 | Exibição na ordem `10`, `20`, `30` | | ☐ |

### 3.3 Consultar (opção 3)

| ID | Passos | Resultado esperado | Obtido | Status |
| :--- | :--- | :--- | :--- | :---: |
| CT-17 | Consultar um código existente | Mostra código, equipamento, nome, prioridade e prazo corretos | | ☐ |
| CT-18 | Consultar um código inexistente | "Solicitação não encontrada." sem encerrar o programa | | ☐ |
| CT-19 | Consultar com a lista vazia | "Solicitação não encontrada." sem encerrar o programa | | ☐ |

### 3.4 Editar (opção 4)

| ID | Passos | Resultado esperado | Obtido | Status |
| :--- | :--- | :--- | :--- | :---: |
| CT-20 | Editar um item para prioridade `1`, prazo `4` | Mostra a solicitação alterada | | ☐ |
| CT-21 | Editar para prioridade `1`, prazo `10` | Recusado (incompatível); pede os valores novamente | | ☐ |
| CT-22 | Editar um código inexistente | Avisa que não foi encontrado e **não** pede novos valores | | ☐ |
| CT-23 | Editar um item e usar a opção 5 | A fila reflete a nova prioridade e o novo prazo | | ☐ |

### 3.5 Apagar (opção 2)

| ID | Passos | Resultado esperado | Obtido | Status |
| :--- | :--- | :--- | :--- | :---: |
| CT-24 | Apagar com a lista vazia | Avisa que não há itens e volta ao menu | | ☐ |
| CT-25 | Com `10`, `20`, `30` cadastrados: apagar `10` (primeiro) e confirmar com `s` | Restam `20`, `30` | | ☐ |
| CT-26 | Com `10`, `20`, `30`: apagar `20` (meio) | Restam `10`, `30` | | ☐ |
| CT-27 | Com `10`, `20`, `30`: apagar `30` (último) | Restam `10`, `20` | | ☐ |
| CT-28 | Com um único item: apagar e confirmar | Lista vazia ("Lista vazia." na opção 6) | | ☐ |
| CT-29 | Apagar e responder `n` na confirmação | "Operação cancelada"; o item continua na lista | | ☐ |
| CT-30 | Apagar um código inexistente | Avisa "Solicitação não encontrada" e permite tentar de novo | | ☐ |

### 3.6 Fila de manutenção (opção 5)

Cadastre estas solicitações (equipamento e nome livres):

| Código | Prioridade | Período |
| :---: | :---: | :---: |
| 10 | 3 | 9 |
| 20 | 1 | 5 |
| 30 | 2 | 2 |
| 40 | 1 | 5 |
| 50 | 1 | 2 |

| ID | Passos | Resultado esperado | Obtido | Status |
| :--- | :--- | :--- | :--- | :---: |
| CT-31 | Opção 5 com os dados acima | Ordem: prioridade 1 antes de 2, e 2 antes de 3 → `50`, `20`, `40`, `30`, `10` | | ☐ |
| CT-32 | Observar `50` (prioridade 1, 2 dias) e `20` (prioridade 1, 5 dias) | Mesma prioridade: menor período primeiro (`50` antes de `20`) | | ☐ |
| CT-33 | Observar `20` e `40` (prioridade 1, 5 dias) | Empate total: menor código primeiro (`20` antes de `40`) | | ☐ |
| CT-34 | Opção 5 e depois opção 6 | A opção 6 continua mostrando a ordem original por código: `10`, `20`, `30`, `40`, `50` | | ☐ |
| CT-35 | Opção 5 com a lista vazia | "Nenhuma solicitação cadastrada." | | ☐ |

### 3.7 Exibir todas (opção 6)

| ID | Passos | Resultado esperado | Obtido | Status |
| :--- | :--- | :--- | :--- | :---: |
| CT-36 | Opção 6 com a lista vazia | "Lista vazia." | | ☐ |
| CT-37 | Opção 6 com vários itens | Todos os itens, em ordem crescente de código, com o código com 4 dígitos (ex.: `0010`) | | ☐ |

---

## 4. Verificação de memória

O enunciado exige que toda memória alocada dinamicamente seja liberada antes do encerramento. Para comprovar isso usamos uma ferramenta que monitora o programa enquanto ele roda e, no fim, informa se ficou algum bloco sem `free` ou se houve acesso inválido.

As entradas estão prontas em `tests/entradas/`, para que o programa rode sem digitação:

| Arquivo | Cenário |
| :--- | :--- |
| `01_sair_direto.txt` | Abre e sai (lista vazia) |
| `02_criar_consultar_apagar.txt` | Cria 3 itens, consulta, apaga um do meio, o primeiro e o último, exibe e sai |
| `03_fila_e_edicao.txt` | Cria 5 itens, exibe a fila, edita um item, exibe a fila de novo e sai com a lista cheia |
| `04_lista_vazia_e_cancelar.txt` | Apagar, fila e consulta com a lista vazia; cancela a saída e sai |

> As entradas assumem que o programa aceita valores válidos **na primeira tentativa**. Se algum cenário parecer "bagunçado", confira se a limpeza de buffer do `case 1` está correta.

### 4.1 Opção A (recomendada): WSL + Valgrind

O Valgrind roda em Linux; no Windows isso é feito pelo WSL.

1. **Instalar o WSL.** Abra o PowerShell como administrador, execute `wsl --install` e reinicie o computador. Depois abra o aplicativo **Ubuntu** e crie um usuário e uma senha.
2. **Instalar as ferramentas.** No Ubuntu, execute:
   ```
   sudo apt update
   sudo apt install gcc valgrind
   ```
3. **Entrar na pasta do projeto.** Os discos do Windows ficam em `/mnt/`. Por exemplo, para uma pasta em `C:\Users\seu_usuario\Gest`:
   ```
   cd /mnt/c/Users/seu_usuario/Gest
   ```
4. **Compilar com símbolos de depuração.** A opção `-g` faz o relatório mostrar o número da linha:
   ```
   gcc -g main.c -o gest_debug
   ```
5. **Executar com o Valgrind e uma das entradas:**
   ```
   valgrind --leak-check=full --show-leak-kinds=all ./gest_debug < tests/entradas/01_sair_direto.txt
   ```
6. **Ler o resultado.** Procure no final do relatório:

   | Mensagem | Significado |
   | :--- | :--- |
   | `All heap blocks were freed -- no leaks are possible` | Toda a memória foi liberada ✔ |
   | `ERROR SUMMARY: 0 errors from 0 contexts` | Nenhum acesso inválido ✔ |
   | `definitely lost: N bytes` | Há `malloc` sem `free`; o relatório indica a linha de origem |
   | `Invalid read` / `Invalid write` | Acesso fora dos limites ou a memória já liberada |
   | `Conditional jump ... uninitialised value` | Uso de variável não inicializada |

7. **Repetir** o passo 5 para os arquivos `02`, `03` e `04` e anotar os resultados na tabela abaixo.

> No Linux, os comandos `system("cls")` e `system("pause")` aparecem como `command not found` no relatório. Isso é esperado e não afeta o resultado: são comandos do Windows.

### 4.2 Opção B: Dr. Memory (direto no Windows)

1. Baixe e instale o **Dr. Memory** (site oficial: drmemory.org).
2. Compile o programa com `-g` e gere o `.exe`.
3. No terminal, execute o programa através do Dr. Memory, usando uma das entradas:
   ```
   drmemory -- gest_debug.exe < tests\entradas\01_sair_direto.txt
   ```
4. Leia o resumo ao final (`NO ERRORS FOUND` ou a lista de erros com a linha de origem).

### 4.3 Registro dos resultados de memória

| Entrada | Ferramenta | Vazamentos | Erros de acesso | Status |
| :--- | :--- | :---: | :---: | :---: |
| `01_sair_direto.txt` | | | | ☐ |
| `02_criar_consultar_apagar.txt` | | | | ☐ |
| `03_fila_e_edicao.txt` | | | | ☐ |
| `04_lista_vazia_e_cancelar.txt` | | | | ☐ |

---

## 5. Resumo final

| Camada | Total de casos | Passaram | Falharam |
| :--- | :---: | :---: | :---: |
| Automáticos | | | |
| Manuais (CT-01 a CT-37) | 37 | | |
| Memória | 4 cenários | | |

**Defeitos encontrados e corrigidos durante os testes:**

| # | Descrição | Correção |
| :---: | :--- | :--- |
| 1 | | |
