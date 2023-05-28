/**************************
@file meio.h
@brief arquivo header de listas de meios eletronicos
@author Joao G
@date  Junho 2023

******************************/


 /**
  * @brief Estrutura de dados para armazenar informações sobre um registro.
  */
typedef struct registo
{
    int codigo; /**< Código do registro. */
    int codigo_local;
    char tipo[50]; /**< Tipo do registro. */
    float bateria; /**< Bateria do registro. */
    float autonomia; /**< Autonomia do registro. */
    float aluguer; /**< Aluguer do registro. */
    struct registo* seguinte; /**< Ponteiro para o próximo registro na lista. */
} Meio;

/**
 * @brief Insere um novo registro na lista de registros.
 *
 * @param[in] inicio Ponteiro para o início da lista.
 * @param[in] cod Código do novo registro.
 * @param[in] nif NIF do novo registro.
 * @param[in] nom Nome do novo registro.
 * @param[in] mor Morada do novo registro.
 * @param[in] tipo Tipo do novo registro.
 * @param[in] bat Bateria do novo registro.
 * @param[in] aut Autonomia do novo registro.
 * @param[in] sal Saldo do novo registro.
 * @param[in] alu Aluguer do novo registro.
 *
 * @return Ponteiro para o início da lista atualizado.
 */
Meio* inserirMeio(Meio* inicio, int cod, int cod_local, char tipo[], float bat, float aut, float alu);

/**
 * @brief Lista todos os registros na lista.
 *
 * @param[in] inicio Ponteiro para o início da lista.
 */
void listarMeios(Meio* inicio);

/**
 * @brief Verifica se um registro com o código especificado já existe na lista.
 *
 * @param[in] inicio Ponteiro para o início da lista.
 * @param[in] codigo Código do registro a ser verificado.
 *
 * @return 1 se o registro existe na lista, 0 caso contrário.
 */
int existeMeio(Meio* inicio, int codigo);

/**
 * @brief Remove um registro com o código especificado da lista.
 *
 * @param[in] inicio Ponteiro para o início da lista.
 * @param[in] cod Código do registro a ser removido.
 *
 * @return Ponteiro para o início da lista atualizado.
 */
Meio* removerMeio(Meio* inicio, int cod);

/**
 * @brief Salva os registros na lista em um arquivo.
 *
 * @param[in] inicio Ponteiro para o início da lista.
 *
 * @return 1 se a operação foi bem sucedida, 0 caso contrário.
 */
int guardarMeios(Meio* inicio);

/**
 * @brief Lê os registros de um arquivo e os armazena em uma lista.
 *
 * @return Ponteiro para o início da lista de registros.
 */
Meio* lerMeios();

/**
 * @brief Adiciona uma localização na lista de locais.
 *
 * @param[in] inicio Ponteiro para o início da lista.
 * @param[in] cod Código do novo registro.
 * @param[in] cod_local Código local de novo registro.
 *
 * @return Ponteiro para o início da lista atualizado.
 */
Meio* adicionarLocalizacao(Meio* inicio, int cod, int cod_local);

/**
 * @brief Lista os meios pelos locais inseridos.
 *
 * @param[in] inicio Ponteiro para o início da lista.
 * 
 * @param[in] cod_local Código local de novo registro.
 * 
 */
void listarMeiosporLocalizacao(Meio* inicio, int cod_local);

