# K-Means

A clustering problem solution using k-means. K-means clustering is a type of unsupervised learning, which is used when you have unlabeled data (i.e., data without defined categories or groups). The goal of this algorithm is to find groups in the data, with the number of groups represented by the variable K. The algorithm works iteratively to assign each data point to one of K groups based on the features that are provided. Data points are clustered based on feature similarity. In short, in this project, given a file like the one below, the program will be able to find the groups of lines with similar values in the columns:

| Feature 1 | Feature 2 | Feature 3 | Feature 4 | Feature 5 | Feature 6 | ... |
|-----------|-----------|-----------|-----------|-----------|-----------|-----|
| 1         | 1         | 3         | 2         | 2         | 739       | ... |
| 2         | 3         | 2         | 33        | 1         | 628       | ... |
| 2         | 4         | 3         | 3         | 3         | 563       | ... |
| ...       | ...       | ...       | ...       | ...       | ...       | ... |

### Prerequisites

You will need to install the modules below to run the program: 
* [GCC 8.1 or greater](http://gcc.gnu.org/)

### Running

To run this software, we gonna compile in the terminal:
1. Enter the folder and compile all the .cpp files with the following command:
```
$ make
```
2. Enter the bin folder and run the following command:
```
$ ./labfinal <dataframe>
```
An example would be:
```
$ ./labfinal ../input/iris.csv
```
3. From this it only interacts with the system.

## Built With

* [Atom](https://atom.io/) - A code editor used

## Authors
### Developers: 
* **Eric Andrade Siqueira ([ericandrade@ufrn.edu.br](mailto:ericandrade@ufrn.edu.br))** 
* **Larissa Gilliane Melo De Moura ([larissagilliane@ufrn.edu.br](mailto:larissagilliane@ufrn.edu.br))** 
* **Luan Santos De Carvalho ([luansnts@ufrn.edu.br](mailto:luansnts@ufrn.edu.br))** 
* **Luís Eduardo Anunciado Silva ([cruxiu@ufrn.edu.br](mailto:cruxiu@ufrn.edu.br))** 
* **Renan Bezerra Kimura ([renankimura@ufrn.edu.br](mailto:renankimura@ufrn.edu.br))** 
### Project Advisor: 
* **Leonardo Cesar Teonacio Bezerra ([leobezerra@imd.ufrn.br](mailto:leobezerra@imd.ufrn.br))** 

See also the list of [contributors](https://github.com/cruxiu/IMD0030-K-Means/contributors) who participated in this project.

## Refference

* [Introduction to K-means Clustering](https://www.datascience.com/blog/k-means-clustering)

## License

This project is licensed under the GPL 3.0 - see the [LICENSE](LICENSE) file for details
