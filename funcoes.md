## Funcionalidades 
|Assinatura| O que faz?|
| :--- | :---|
|void NovaSolic(lista *L, int cods, char *codeq, char *nome, int pri, int per)|Recebe as informações de uma nova solicitação e cria uma nova na lista de solicitações.| 
|void ConsultarSolic(lista *L, int cod)|Recebe um código de solicitação e exibe as informações daquele item|
|void EditarSolic(lista *L, int cod, int pri, int pra)|Recebe um código de solicitação e novos valores para prioridade e prazo e faz a alteração no item na lista de solicitação|
|void ListaManutencao(lista *L)|Recebe a lista de manutenção, cria uma nova lista ordenando a lista de manutenção pela prioridade e prazo e a exibe|

## Verificações de entrada

|Assinatura | O que faz? |
| :---| :---|
|int VerificaTipo(int tipo)| Recebe o retorno do scanf e retorna erro caso o tipo da entrada seja incompativel com o tipo da variável|
|int VerificarCSol(lista *L, int csol)| Recebe o codigo de solicitação e a lista e confere se o código está no intervalo correto para o código de solicitação (<0 e >9999) ou se o código já existe|
|int VerificarIntervalo(int pri, int pra)| Recebe a prioridade e o prazo dados para um a solcitação e conferem se o prazo é coerente com a prioridade|
|int VerificaEquipamento (char c_eq[7])|Recebe o código do equipamento e verifica se está no formato adequado|

## Biblioteca Geral
|Assinatura | O que faz? |
| :---| :---|
|int VaziaLista (lista* L)|Recebe uma lista e verifica se ela está vazia|
|lista* CriaLista()|Cria um espaço lista, insere NULL no espaço 'inicio' e retorna o endereço|
|void InsereLista (lista *L, No *novo)|Recebe uma lista e o endereço de um nó e insere o nó dentro da lista|
|void XapiskaItem (lista *L,int pos)|Recebe a lista e a posição do item que deve ser apagado e o remove da lista e livra o espaço de memoria|
|lista* XapiskaLista (lista *L)|Recebe uma lista, remove todos os itens da lista e retorna NULL|
|void ImprimeLista(lista *L)| Recebe uma lista e imprime todos os seus itens|
|int Achapos (lista *L, int csol)| Recebe uma lista e um código de solicitação e retorna a posição que esse item correspondente|
|No* BuscaItem(lista *L, int csol)|Recebe uma lista e um código de solicitação e retorna o endereço do item correspondente|