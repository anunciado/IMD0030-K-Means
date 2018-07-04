#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>
#include "pointers.h"

template<typename T>
class List {
private:
    T *data;                                            /**< Dado */
    List *next;                                        /**< Próximo */
public:
    List();                                            /**< Construtor padrão */
    ~List();                                           /**< Destrutor padrão */
    void insert(T value, int pos);                     /**< Insere um valor em uma posição da lista */
    void clear(int pos);                               /**< Remove um vallor da posição informada */
    void print();                                      /**< Imprime a lista */
};

    /**
    * @details Os valuees next são inicializados com NULL
    */
    template<typename T>
    List<T>::List() {
        next = NULL;
    }

    /**
    * @details Destrutor padrão
    */
    template<typename T>
    List<T>::~List() {
        if(next)
            delete next;
    }

    /**
    * @details Insere um value em uma posição da List
    */
    template<typename T>
    void List<T>::insert(T value, int pos) {
        List<T> *novo = new List<T>(value);
        if(!novo) {
            std::cout << "Sem memoria disponivel!" << std::endl;
        }
        //BUSCAR A POSIÇÃO PARA INSERIR
        List *tmp = this;
        List *ant = this;
        int i = 0;
        while((tmp->next) && (i < pos)) {
            if(novo->data > tmp->next->data) {
                ant = tmp;
                tmp = tmp->next;
            } else {
                break;
            }
            i++;
        }

        novo->next = tmp->next;
        ant->next = novo;
    }

    /**
    * @details Remove um value na posição informada
    */
    template<typename T>
    void List<T>::clear(int pos) {
        if(pos < 0)
            return;
        List *atual = this;
        List *remove = next;
        for(int i = 0; i < pos; i++) {
            if(remove) {
                atual = remove;
                remove = remove->next;
            }
        }
        if(remove) {
            atual->next = remove->next; //Relinka o anterior ao próximo
            remove->next = NULL;        //Para não remover todos os próximos através do destrutor padrão
            delete remove;
        }
    }

    /**
    * @details      Imprime a lista completa
    */
    template<typename T>
    void List<T>::print() {
        if(!next){
            std::cout << "List vazia!" << std::endl;
        }

        List *tmp;
        tmp = next;

        while( tmp != NULL){
          std::cout << *tmp->data << std::endl;
          tmp = tmp->next;
        }
    }

    /**
    * @details      Imprime a lista completa de pointers
    */
    template<>
    void List<Point>::print() {
        if(!next){
            std::cout << "List vazia!" << std::endl;
        }

        List *tmp;
        tmp = next;
/*
        while( tmp != NULL){
          int point = *tmp->data.id_point;
          std::cout << "Ponto: " << point << std::endl;
          for (size_t i = 0; i < *tmp->data->values.size(); i++) {
            std::cout << *tmp->data->values[i] << std::endl;
          }
          tmp = tmp->next;
        }
*/
    }

#endif /* __LIST_H__ */
