/**
 * @brief   Definição dos atributos e protótipos dos métodos da classe Dataframe.
 * @author  Eric Andrade Siqueira, Larissa Gilliane Melo De Moura, Luan Santos De Carvalho, Luís Eduardo Anunciado Silva, Renan Bezerra Kimura
 * @since   25/05/2017
 * @date    27/06/2017
 */
#ifndef __DATAFRAME_H__
#define __DATAFRAME_H__

/**
 * @class   Dataframe dataFrame.h
 * @brief   Classe usada para para fazer a leitura e conversão dos dataframes recebidos
 * @details Os atributos de um objeto KMeans são: sep, auxState, elements
 */
template <typename T>
class DataFrame
{
private:
    char sep = ',';
    bool auxState;
    std::vector< std::vector<T> > elements;
public:
  bool state ();
  size_t size_DataFrameRow ();
  size_t size_DataFrameCol ();
  int size_Clusters ();
  std::vector <T> observation(int i);
  void print (std::ostream & output, const DataFrame &dt, const char &sep) const;
    void read (std::istream & input, DataFrame & dt, const char &sep) const;
    friend std::ostream& operator<< (std::ostream & output, const DataFrame &dt)
    {
    	dt.print(output, dt, dt.sep);
      return output;
    }
    friend std::istream& operator>> (std::istream & input, DataFrame &dt)
    {
      dt.read(input, dt, dt.sep);
      return input;
    }
};

template <typename T>
bool DataFrame<T>::state ()
{
  return auxState;
}

template <typename T>
size_t DataFrame<T>::size_DataFrameRow ()
{
  return elements.size();
}

template <typename T>
size_t DataFrame<T>::size_DataFrameCol ()
{
  return elements[0].size();
}

template <typename T>
int DataFrame<T>::size_Clusters ()
{
  return elements[elements.size()-1][elements[0].size()-1];
}

template <typename T>
std::vector <T> DataFrame<T>::observation(int i)
{
  std::vector <T> output (elements[i].begin(), elements[i].end() - 1);
  return output;
}

template <typename T>
void DataFrame<T>::print (std::ostream & output, const DataFrame &dt, const char &sep) const
{
  /*Imprimir os valores da matriz do dataframe. */
  for(size_t i = 0; i < dt.elements.size(); i++)
  {
    for(size_t j = 0; j <	dt.elements[i].size(); j++)
    {
      if(j == dt.elements[i].size() - 1)
        output << dt.elements[i][j];
      else
      {
        output << dt.elements[i][j] << sep;
      }
    }
    output << std::endl;
  }
}

template <typename T>
void DataFrame<T>::read (std::istream & input, DataFrame & dt, const char &sep) const
{
  std::string lines, stringElement;
  /* Função para receber a parte dos valores da matriz do dataframe. */

  std::vector <T> row;
  size_t rowAux = 0;
  /* Receber em uma string todas as linha da matriz. */
  while(std::getline (input, lines))
  {
    /* Procura pela variável sep e extrai os elementos. */
    std::istringstream inputStream(lines);
    while(inputStream.good())
    {
      getline(inputStream, stringElement, sep);
      row.push_back(std::stof(stringElement));
    }

    /* Colocar os elementos da linha na matriz. */
    if (dt.elements.size() == 0)
    {
      rowAux = row.size();
      dt.elements.push_back(row);
      row.clear();
      dt.auxState = true;
    }
    else if(rowAux != row.size())
    {
        dt.auxState = false;
    }
    else
    {
      dt.elements.push_back(row); row.clear();
    }
  }
}

#endif /* __DATAFRAME_H__ */
