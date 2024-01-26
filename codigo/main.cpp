#include <iostream>
#include <string.h>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <iomanip>

using namespace std;
const int NUM = 50;
//---------------FORCA------------------------------------------------------------------------------------
void desenhaForca(int erros){
    switch (erros){
    case 0:{
        cout << "\n";
        break;}
    case 1:{
        cout << "\n\n\n\n\n\n\n\n\n\n\n";
        cout << "-------------" << endl;
        break;}
    case 2:{
        cout << endl;
        cout << "     |  /" << endl;
        cout << "     | /" << endl;
        cout << "     |" << endl;
        cout << "     |" << endl;
        cout << "     |" << endl;
        cout << "     |" << endl;
        cout << "     |" << endl;
        cout << "     |" << endl;
        cout << "     |"<< endl;
        cout << "     |"<< endl;
        cout << "-------------" << endl;
        break;}
    case 3:{
        cout << endl;
        cout << "--------------------------" << endl;
        cout << "     |  /             |" << endl;
        cout << "     | /              |" << endl;
        cout << "     |" << endl;
        cout << "     |" << endl;
        cout << "     |" << endl;
        cout << "     |" << endl;
        cout << "     |" << endl;
        cout << "     |" << endl;
        cout << "     |"<< endl;
        cout << "     |"<< endl;
        cout << "-------------" << endl;
        break;}
    case 4:{
        cout << endl;
        cout << "--------------------------" << endl;
        cout << "     |  /             |" << endl;
        cout << "     | /              |" << endl;
        cout << "     |                O" << endl;
        cout << "     |" << endl;
        cout << "     |" << endl;
        cout << "     |" << endl;
        cout << "     |" << endl;
        cout << "     |" << endl;
        cout << "     |"<< endl;
        cout << "     |"<< endl;
        cout << "-------------" << endl;
        break;}
    case 5:{
        cout << endl;
        cout << "--------------------------" << endl;
        cout << "     |  /             |" << endl;
        cout << "     | /              |" << endl;
        cout << "     |                O" << endl;
        cout << "     |                |" << endl;
        cout << "     |                |" << endl;
        cout << "     |                |" << endl;
        cout << "     |" << endl;
        cout << "     |" << endl;
        cout << "     |"<< endl;
        cout << "     |"<< endl;
        cout << "-------------" << endl;
        break;}
    case 6:{
        cout << endl;
        cout << "--------------------------" << endl;
        cout << "     |  /             |" << endl;
        cout << "     | /              |" << endl;
        cout << "     |                O" << endl;
        cout << "     |                |" << endl;
        cout << "     |            ----|" << endl;
        cout << "     |                |" << endl;
        cout << "     |" << endl;
        cout << "     |" << endl;
        cout << "     |"<< endl;
        cout << "     |"<< endl;
        cout << "-------------" << endl;
        break;}
    case 7:{
        cout << endl;
        cout << "--------------------------" << endl;
        cout << "     |  /             |" << endl;
        cout << "     | /              |" << endl;
        cout << "     |                O" << endl;
        cout << "     |                |" << endl;
        cout << "     |            ----|----" << endl;
        cout << "     |                |" << endl;
        cout << "     |" << endl;
        cout << "     |" << endl;
        cout << "     |"<< endl;
        cout << "     |"<< endl;
        cout << "-------------" << endl;
        break;}
    case 8:{
        cout << endl;
        cout << "--------------------------" << endl;
        cout << "     |  /             |" << endl;
        cout << "     | /              |" << endl;
        cout << "     |                O" << endl;
        cout << "     |                |" << endl;
        cout << "     |            ----|----" << endl;
        cout << "     |                |" << endl;
        cout << "     |               /" << endl;
        cout << "     |              /" << endl;
        cout << "     |"<< endl;
        cout << "     |"<< endl;
        cout << "-------------" << endl;
        break;}
    case 9:{
        cout << endl;
        cout << "--------------------------" << endl;
        cout << "     |  /             |" << endl;
        cout << "     | /              |" << endl;
        cout << "     |                O" << endl;
        cout << "     |                |" << endl;
        cout << "     |            ----|----" << endl;
        cout << "     |                |" << endl;
        cout << "     |               / \\" << endl;
        cout << "     |              /   \\" << endl;
        cout << "     |"<< endl;
        cout << "     |"<< endl;
        cout << "-------------" << endl;
        break;}
    }
}

//---------------Funções Variadas------------------------------------------------------------------------------------
bool procuraLetranoArray(char tab[], char c, int n){
    //Recebe uma letra e vê se a letra está no array tab ou não
    for (int i = 0 ; i < n ; i++)
        if (tab[i] == c)
            return (true);

    return (false);
}

bool leEescreveFicheiros (char nome[], double pontos){
    string dadosLidos, aux;
    string cpp_nome = nome;

    //Abrir os dois ficheiros que vão ser necessários e garantir que tal é feito de forma sucedida
    ifstream ficheiro("MiniProjeto1.txt");                      //abrir o ficheiro para leitura
    if ( !ficheiro.is_open()){
        cout << "\nOcorreu um problema!...\n";
        return (false);
    }
    ofstream ficheiroAux("FicheiroAuxiliar.txt");               //abrir o ficheiro para escrita
    if ( !ficheiroAux.is_open()){
        cout << "\nOcorreu um problema!...\n";
        return (false);
    }

    //Vai copiar todos os dados do ficheiro original para um auxiliar, exceto o do jogador atual, caso já exista
    ficheiro.seekg (0, ficheiro.beg);     //coloca o "cursor" no início do ficheiro
    while (getline(ficheiro, dadosLidos)){   //lê uma linha do ficheiro de texto
        aux = dadosLidos;
        aux.resize(NUM, ' ');
        cpp_nome.resize(NUM, ' ');
        if (cpp_nome == aux)                //é o nome do jogador => já tem uma pontuação atribuída => não escreve os dados no novo ficheiro
            continue;
        ficheiroAux << dadosLidos << endl; //não é o nome do jogador => escreve os dados no novo ficheiro
    }

    //Escreve os dados novos do jogador no final do ficheiro
    ficheiroAux << left << setw(50) << nome;
    ficheiroAux << left << setw(10) << pontos << endl;

    //Fecha os ficheiros, elimina o ficheiro inicial e altera o nome do ficheiro auxiliar
    ficheiro.close();
    ficheiroAux.close();
    remove("MiniProjeto1.txt");
    rename ("FicheiroAuxiliar.txt", "MiniProjeto1.txt");
    return (true);
}

void ordenaInsercao (int tab[], int dim, string tabNomes[]){
    for (int i = 1 ; i < dim ; i++){
        int aux = tab[i];
        string aux2 = tabNomes[i];
        int j;
        for (j = i ; (j>0) && (aux < tab[j-1]) ; j--){
            tab[j] = tab[j-1];
            tabNomes[j] = tabNomes[j-1];
        }
        tab[j] = aux;
        tabNomes[j] = aux2;
    }
}

bool leFicheiro (){
    string dadosLidos, aux;
    string *nomes, *pontuacao;
    int *auxPontuacao;
    int i = 0, linhas = 0;

    //Abrir o ficheiro necessário e garantir que tal é feito de forma sucedida
    ifstream ficheiro("MiniProjeto1.txt");                      //abrir o ficheiro para leitura
    if ( !ficheiro.is_open()){
        cout << "\nOcorreu um problema!...\n";
        return (false);
    }

    //Conta o número de linhas do ficheiro
    ficheiro.seekg (0, ficheiro.end);
    linhas = ficheiro.tellg();
    ficheiro.seekg (0, ficheiro.beg);

    //Alocar memória para as tabelas dos nomes e das pontuações
    nomes = new string[linhas];
    pontuacao = new string[linhas];
    auxPontuacao = new int[linhas];

    //Lê cada linha do ficheiro, uma a uma, e imprime-a no ecrã
    while (getline(ficheiro, dadosLidos)){   //lê uma linha do ficheiro de texto
        nomes[i] = dadosLidos.substr(0, NUM);
        pontuacao[i] = dadosLidos.substr(NUM-1, 10);
        auxPontuacao[i] = stoi(pontuacao[i]);       //transforma a strings de pontuacao num inteiro
        i = i+1;
    }

    //ordena por ordem crescente a tabela de pontuações utilizando o método da insercão
    ordenaInsercao(auxPontuacao, i, nomes);

    //Cabeçalho para a tabela
    cout << left << setw(50) << "\nNome do jogador:" << setw(10) << "Pontuacao:\n";

    for (int j = i-1 ; j>=0 ; j--){     //começamos a imprimir a tabela pelo fim para imprimir em ordem decrescente
        cout << setw(NUM) << nomes[j] << setw(10) << auxPontuacao[j] << endl;
    }

    //Fecha os ficheiros, elimina o ficheiro inicial e as alocações de memória
    ficheiro.close();
    delete []nomes;
    delete []pontuacao;
    delete []auxPontuacao;
    return (true);
}
//---------------PALAVRAS------------------------------------------------------------------------------------
class CPalavra{
private:
    char palavra[15];
    int numletras;
    char tema[10];

public:
    //Construtores
    CPalavra(int t){
        if(t == NUM){ //se for o modo Elementar
            escolhePalavra();
            numletras = strlen(palavra);
        }
        else {
            escolhePalavraDeTema(t);
            numletras = strlen(palavra);}
    }

    //Método que escolhe ateatoriamente uma das palavras
    void escolhePalavra(void);
    //Método que escolhe ateatoriamente uma das palavras de um dado tema
    void escolhePalavraDeTema(int t);
    //Método para imprimir no ecrã a palavra, apenas com as letras já descobretas
    void imprimePalavraDescoberta(const char letrasdescobertas[], const int n);
            //letrasdescobertas -> array com todas as letras que já foram adivinhadas até ao momento
            //n -> inteiro com o número de letras descobertas
    //Método que imprime o tema
    void imprimeTema(void) {cout << tema;}
    //Método que devolve o número de letras da palavra
    int devolveNumLetras(void) {return (numletras);}
    //Método que verifica se uma letra se encontra na palavra definida, ou não
    int procuraLetra(char ch);
    //Método que define o tempo máximo para o jogador adivinhar a palavra
    double defineTempoMax(int dif);
        //dif é a constante para o valor de dificuldade
        //devolve o valor em segundos
    //Método que atribui a pontuação para uma ronda do jogo
    double atruibuiPontos(double t, double tmax, int numErros, int mod);
};

//Definição do método que escolhe ateatoriamente uma das palavras
void CPalavra :: escolhePalavra(void){
    char temas [3][10] = {"alimentos", "cores", "animais"};
    char t0[8][15] = {"BANANA", "ARROZ", "BOLO", "MARMELADA", "LIMONADA", "OVO", "PANQUECA", "TORRADA"};
    char t1[8][15] = {"AMARELO", "VERMELHO", "VERDE", "AZUL" ,"PRETO", "VIOLETA", "BRANCO", "DOURADO"};
    char t2[8][15] = {"BACALHAU", "ROUXINOL", "TEXUGO", "FORMIGA", "ZEBRA", "GALINHA", "ORNITORRINCO", "GATO"};

    int nAleatorio1 = rand() % 3;       //gera um número aleatório entre 0 e 2
    int nAleatorio2 = rand() % 8;       //gera um número aleatório entre 0 e 7

    switch (nAleatorio1){
    case 0:{
        strncpy(palavra, t0[nAleatorio2], sizeof(palavra));
        strncpy(tema, temas[0], sizeof(tema));
        break;}
    case 1:{
        strncpy(palavra, t1[nAleatorio2], sizeof(palavra));
        strncpy(tema, temas[1], sizeof(tema));
        break;}
    case 2:{
        strncpy(palavra, t2[nAleatorio2], sizeof(palavra));
        strncpy(tema, temas[2], sizeof(tema));
        break;}
    }
}

//Definição do método que escolhe ateatoriamente uma das palavras de um dado tema
void CPalavra :: escolhePalavraDeTema(int t){
    char temas [3][10] = {"alimentos", "cores", "animais"};
    char t0[8][15] = {"BANANA", "ARROZ", "BOLO", "MARMELADA", "LIMONADA", "OVO", "PANQUECA", "TORRADA"};
    char t1[8][15] = {"AMARELO", "VERMELHO", "VERDE", "AZUL" ,"PRETO", "VIOLETA", "BRANCO", "DOURADO"};
    char t2[8][15] = {"BACALHAU", "ROUXINOL", "TEXUGO", "FORMIGA", "ZEBRA", "GALINHA", "ORNITORRINCO", "GATO"};

    int nAleatorio = rand() % 8;       //gera um número aleatório entre 0 e 7

    switch (t){
    case 0:{
        strncpy(palavra, t0[nAleatorio], sizeof(palavra));
        strncpy(tema, temas[0], sizeof(tema));
        break;}
    case 1:{
        strncpy(palavra, t1[nAleatorio], sizeof(palavra));
        strncpy(tema, temas[1], sizeof(tema));
        break;}
    case 2:{
        strncpy(palavra, t2[nAleatorio], sizeof(palavra));
        strncpy(tema, temas[2], sizeof(tema));
        break;}
}
}

//Definição do método para imprimir no ecrã a palavra, apenas com as letras já descobretas
void CPalavra :: imprimePalavraDescoberta(const char letrasdescobertas[], const int n){
    for (int i=0 ; i<numletras ; i++){
        bool descoberta = false;
        for (int j=0 ; j<n ; j++){
            if (palavra[i] == letrasdescobertas[j])
                descoberta = true;
        }
        if (descoberta == true)
            cout << palavra[i] << " ";
        else
            cout << "__ ";
    }
}

//Definição do método que verifica se uma letra se encontra na palavra definida, ou não
int CPalavra :: procuraLetra(char ch){
    int num = 0;
    for (int i=0 ; i<numletras ; i++){
        if (palavra[i] == ch)
            num = num + 1;
    }
    return (num);
}

//Definição do método que define o tempo máximo para o jogador adivinhar a palavra
double CPalavra :: defineTempoMax(int dif){
    switch (dif){
    case 0:    //0 - nível de dificuldade = fácil
        return (numletras * 100 / 15.0);
        break;
    case 1:
        return (numletras * 100 / 25.0);
        break;
    case 2:
        return (numletras * 100 / 30.0);
        break;
    default:
        return (0.0);
    }
}

//Definição do método que atribui a pontuação para uma ronda do jogo
double CPalavra :: atruibuiPontos(double t, double tmax, int numErros, int mod){
    switch (mod){
    case 1:
    case 4:{    //em modo elementar / sem contagem de tempo
        return (50 - 5*numErros);
        break;}
    case 2:
    case 3:
    case 5:{
        if (t<tmax)
            return (150 - t - 5*numErros);
        break;}
    }
    return (0);
}

//---------------TEMPO------------------------------------------------------------------------------------
class CTempo{
private:
    double segundos;

public:
    //Construtor
    CTempo () {segundos = 0.0;}

    //Método que obtém o tempo no momento exato do código
    void tempoAgora(void);
    //Método que devolve o atributo "segundos" da classe
    double devolveSegundos (void){return segundos;}
};

//Definição do método que obtém o tempo no momento exato do código
void CTempo :: tempoAgora(void){  //devolve no atributo segundos da classe chamada
    time_t tempo;
    struct tm tzero = {0};
    tzero.tm_hour = 0; tzero.tm_min = 0; tzero.tm_sec = 0;
    tzero.tm_year = 0; tzero.tm_mon = 0; tzero.tm_mday = 0;

    tempo = time(NULL);     //lê o tempo neste exato momento
    segundos = difftime(tempo, mktime(&tzero));
}

//---------------MAIN----------------------------
int main()
{
//Variáveis a utilizar
    int t1, t2;
    string cs;
    int cron = 0, tema = 0;
    char nome[NUM];
    bool aux;

MENU:
//MENU --------------------------------------------------------------------------------------------------------
    cout << "MENU: \n1 - Iniciar novo jogo \n2 - Sair \n3 - Modo de funcionamento \n4 - Mostrar pontuacoes totais de jogadores\n";
    cin >> t1;
    switch (t1){
    case 1:{
        cout <<"INICIAR NOVO JOGO \n1 - Modo Elementar \n2 - Modo Basico\n3 - Modo Medio\n";
        cin >> t2;
        goto MODOS;
        break;}
    case 2:{
        //Perguntar ao utilizador se quer continuar a jogar ou se quer sair
        cout << "\nSe quiser continuar a jogar, introduza S/s. Caso contrario, introduza qualquer outro caracter: ";
        cin >> cs;
        if ((cs == "s") || (cs == "S"))
            goto MENU;
        else
            return 0;
        break;}
    case 3:{
    //Pergunta ao utilizador se deseja selecionar o tema e se deseja que o tempo seja cronometrado
        cout << "\n\nDeseja selecionar o tema do jogo? Se sim, introduza S/s. ";
        cin >> cs;
        if ((cs == "s") || (cs == "S"))
            tema = 1;
        cout << "\n\nDeseja cronometrar o jogo? Se sim, introduza S/s. ";
        cin >> cs;
        if ((cs == "s") || (cs == "S"))
            cron = 1;

        if ((tema == 1) && (cron ==1)){
            t2 = 2;
            goto MODOS;}
        else if((tema == 0) && (cron == 0)){
            t2 = 1;
            goto MODOS;}
        else if ((tema == 1) && (cron == 0)){
            t2 = 4;
            goto MODOS;}
        else if ((tema == 0) && (cron == 1)){
            t2 = 5;
            goto MODOS;}
        break;}
    case 4:{
        aux = leFicheiro();
        if (aux == false){
            cout << "\n\n OCORREU UM ERRO A ABRIR OS FICHEIROS....\n\n";
            return (-1);
        }
        cout << "\nSe quiser continuar a jogar, introduza S/s. Caso contrario, introduza qualquer outro caracter: ";
        cin >> cs;
        if ((cs == "s") || (cs == "S"))
            goto MENU;
        else
            return 0;
        break;}
    }

//PROGRAMAÇÃO DOS MODOS ELEMENTAR, BÁSICO E MÉDIO
    //Definição das variáveis a utilizar
MODOS:
    char c;
    int numLetrasCorretas, numErros, numCaracteresCorretos, numRepeticoesLetra, valorLido, numLetrasErradas;
    char LetrasCorretas[13] = " "; //13 porque a maior palavra tem 12 letras
    char LetrasErradas[27] = " ";  //27, tendo em conta que existem 26 letras no alfabeto
    CTempo temp;
    double tempoMax, tempoInicial, tempoAqui, pontos=0;

AtribuirValoresIniciais:
    numLetrasCorretas = 0;
    numCaracteresCorretos = 0;
    numLetrasErradas = 0;
    strcpy (LetrasCorretas, " ");
    numErros = 0;
//"Salta" para o modo que foi selecionado
    if (t2 == 1){
        cout << "\n\n-------------------JOGO EM MODO ELEMENTAR--------------------\n";
        valorLido = NUM;
        goto RONDAdoJOGO;}
    else if (t2 == 2){
        cout << "\n\n-------------------JOGO EM MODO BASICO--------------------\n";
        goto EscolherTema;}
    else if (t2 == 3){
        cout << "\n\n-------------------JOGO EM MODO MEDIO--------------------\n";
        goto EscolherTema;}
    else if (t2 == 4){
        cout << "\n\n-------------------JOGO A ESCOLHER O TEMA, MAS SEM CONTAR TEMPO--------------------\n";
        goto EscolherTema;}
    else if (t2 == 5){
        cout << "\n\n-------------------JOGO A CONTAR TEMPO, MAS SEM ESCOLHER O TEMA--------------------\n";
        valorLido = NUM;
        goto RONDAdoJOGO;}

EscolherTema:
    cout << "Escolha um dos seguintes temas: ";
    cout << "\n0 - Alimentos \n1- Cores \n2- Animais\n";
    cin >> valorLido;
    goto RONDAdoJOGO;

RONDAdoJOGO:
    CPalavra P(valorLido);     //Escolhe automaticamente e aleatoriamente qual a palavra a ser utilizada
    //Informar o utilizador o tema
    cout << "\nTEMA: ";
    P.imprimeTema();
    cout << endl;

    if ((t2 == 2) || (t2 == 3) || (t2 == 5)){
    //Define o tempo máximo que o jogador vai ter para adivinhar a palavra
        cout << "\nQual o nivel de dificuldade que pretende? \n0 - Facil \n1 - Medio \n2 - Dificil\n";
        cin >> valorLido;
        tempoMax = P.defineTempoMax(valorLido);
        cout << "\n\nTem " << tempoMax << " segundos para descobrir a palavra!\n\n";

    //Definir o tempo no início deste jogo
        temp.tempoAgora();
        tempoInicial = temp.devolveSegundos();
    }
    else{
        tempoAqui = 0;
        tempoInicial = 0;
        tempoMax = 0;
    }

    while (1){
        //Verifica se a palavra já foi descoberta ou se já foram cometidos 9 erros
        if (numErros == 9){
            desenhaForca(numErros);
            cout << "\n\nPERDEU...\n";
            goto End2;}
        if (numCaracteresCorretos == P.devolveNumLetras()){
            cout << "                                       ";
            P.imprimePalavraDescoberta(LetrasCorretas, numLetrasCorretas);
            cout << "\n\nCONSEGUIU ADIVINHAR!!!\n";
            break;}

        if ((t2 == 2) || (t2 == 3) || (t2 == 5)){
        //Verifica se o tempo já foi excedidio
            temp.tempoAgora();
            tempoAqui = temp.devolveSegundos();
            if ((tempoAqui-tempoInicial) > tempoMax){
                cout << "\n\nFOI EXCEDIDIO O TEMPO...";
                goto End2;}
        }

        cout << "                                       ";
        P.imprimePalavraDescoberta(LetrasCorretas, numLetrasCorretas);
        desenhaForca(numErros);

        if (t2 == 3){
        //Mostra as letras já erradas
            cout << "\n\n                        ";
            for (int i = 0 ; i<numLetrasErradas ; i++)
                cout << LetrasErradas[i] << "       ";
        }

        cout << "\n\n" << "Introduza uma letra (em maiusculas): ";
        cin >> c;

        if (c == '0'){
            cout << "\n\nDeseja mesmo terminar o jogo agora? Se sim, introduza S/s. ";
            cin >> cs;
            if ((cs == "s") || (cs == "S"))
                goto End2;
        }

        if(procuraLetranoArray(LetrasCorretas, c, numLetrasCorretas) == false){
            numRepeticoesLetra = P.procuraLetra(c);
            if (numRepeticoesLetra == 0){
                numErros = numErros + 1;
                if(procuraLetranoArray(LetrasErradas, c, numLetrasErradas) == false){
                    numLetrasErradas = numLetrasErradas + 1;
                    LetrasErradas[numLetrasErradas-1] = c;
                }
            }
            else{
                numLetrasCorretas = numLetrasCorretas + 1;
                numCaracteresCorretos = numCaracteresCorretos + numRepeticoesLetra;
                LetrasCorretas[numLetrasCorretas-1] = c;
            }
        }
    }
    //Atribuir os pontos conseguidos na ronda jogada
    pontos = pontos + P.atruibuiPontos(tempoAqui-tempoInicial, tempoMax, numErros, t2);     //(double t, double tmax, int mod)
    cout << "\nPontuacao: " << pontos;

End:
    //Perguntar ao utilizador se quer continuar a jogar ou se quer sair
    cout << "\nSe quiser continuar a jogar, introduza S/s. Caso contrario, introduza qualquer outro caracter: ";
    cin >> cs;
    if ((cs == "s") || (cs == "S"))
        goto AtribuirValoresIniciais;
    else
        goto End2;

End2:
    if (pontos > 0){
        //Pede o nome ao utilizador e escreve os seus dados (ou substitui a pontuação) no ficheiro de texto
        cout << "\nIntroduza o seu nome: ";
        cin >> nome;

        //Escreve os dados no ficheiro
        aux = leEescreveFicheiros (nome, pontos);
        if (aux == false){
            cout << "\n\n OCORREU UM ERRO A ABRIR OS FICHEIROS....\n\n";
            return (-1);
        }
    }

    cout << "\nPONTUACAO FINAL: " << pontos << "!!!";
    cout << "\n\n";
}
