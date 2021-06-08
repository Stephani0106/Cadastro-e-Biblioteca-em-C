//Cabe�alho (Header) -> Vari�veis e atributos

//Estruturas para salvar as informa��es dos usu�rios e dos livros
typedef struct listaUsuarios ListaCAD;
typedef struct livros Acervo;

//Prototipos de fun��es para manipula��o de dados para cadastro de usu�rio
ListaCAD *iniciarDados(char *nome, int cadastro);
ListaCAD *inserirDados(ListaCAD *dados, char *nome, int cadastro);
void exibirDados(ListaCAD *dados);
void buscarDados(ListaCAD *dados, char *chave);
ListaCAD *excluirDados(ListaCAD *dados);
int vazio(ListaCAD *dados);

//Prototipos de fun��es para o menu principal do usuario
void inserirUser(void);
void exibirUser(void);
void buscarUser(void);
void deletarUser(void);
void menuCadastro();

//Prototipos de fun��es para manipula��o do acervo
Acervo *iniciarAcervo(char *nome, char *autor, char *editora, int ano, int cod_livro);
Acervo *inserirAcervo(Acervo *livros, char *nome, char *autor, char *editora, int ano, int cod_livro);
void exibirAcervo(Acervo *livros);
void buscarAcervo(Acervo *livros, char *chave);
Acervo *excluirLivro(Acervo *livros);
int acervoVazio(Acervo *livros);

//Prototipos de fun��es para o menu principal da biblioteca
void inserirNoAcervo(void);
void exibirLivros(void);
void buscarLivro(void);
void deletarLivro(void);
void menuBiblio();


