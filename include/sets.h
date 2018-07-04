#ifndef __SETS_H__
#define __SETS_H__

#include "pointers.h"

template <typename T> class Set
{
private:
  /* Classe "unordered_set" encapsulada. */
  std::unordered_set <T> us;
public:
  Set();
  ~Set();
  void print();
  void insertion(T data);
  void clear(T data);
  bool pertinancy(T data);
  Set <T> junction(Set A);
  Set <T> difference(Set A);
  Set <T> intersection(Set A);
  bool compare(Set A);
  std::vector <Point> conversion();
  List <Point> order(int parameter);
};

/* Construtor e destrutor da classe. */
template <typename T>
Set<T>::Set() { }
template <typename T>
Set<T>::~Set() { }

/* Impressão de cada vector  */

template <typename T>
void Set<T>::print()
{
  for(const T & x: us)
  {
    for(size_t i = 0; i < x.size(); i++) std::cout << x[i] << "\t";
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

/* Dado o vetor de entrada ou "observação", será colocado no conjunto.  */

template <typename T>
void Set<T>::insertion(T data)
{
	us.insert(data);
}

/* Dado o vetor de entrada ou "observação", será removido do conjunto.  */

template <typename T>
void Set<T>::clear(T data)
{
	us.erase(data);
}

/* Dado o vetor de entrada ou "observação", será visto se ele pertence ao conjunto.  */

template <typename T>
bool Set<T>::pertinancy(T data)
{
  typename std::unordered_set<T>::const_iterator got = us.find(data);
  if (got == us.end()) return false;
  return true;
}

/* Será feito a união entre o conjunto A e B e colocado no C.  */

template <typename T>
Set <T> Set<T>::junction(Set <T> A)
{
  Set <T> B;
  B.us.insert(A.us.begin(), A.us.end());
  B.us.insert(us.begin(), us.end());
  return B;
}

/* Será feito a diferença entre o conjunto A e B e colocado no C.  */

template <typename T>
Set <T> Set<T>::difference(Set <T> A)
{
  Set <T> B;
  B.us.insert(us.begin(), us.end());
  for(const T & x: A.us) B.us.erase(x);
  return B;
}

/* Será feito a intersecção entre o conjunto A e B e colocado no C.  */

template <typename T>
Set <T> Set<T>::intersection(Set <T> A)
{
  Set <T> B;
  for(const T & x: A.us)
  {
    if (us.find(x) != us.end()) B.us.insert(x);
  }
  return B;
}

/* Será feito a comparação de igualdade entre o conjunto A e B.  */
template <typename T>
bool Set<T>::compare(Set <T> A)
{
  for(const T & x: A.us)
  {
    if (us.find(x) == us.end()) return false;
  }
  return true;
}

template <typename T>
std::vector <Point> Set<T>::conversion()
{
  std::vector <Point> output (us.begin(), us.end());
  return output;
}

template <typename T>
List <Point> order(int parameter)
{
  std::vector <Point> outputVector (us.begin(), us.end());
  List <Point> outputList;
  while (outputVector.size() != 0) {
    for (size_t i = 0; i < outputVector.size(); i++) {
      outputList.insert(outputVector[i], 0);
    }
  }
  return outputList;
}

#endif /* __SETS_H__ */
