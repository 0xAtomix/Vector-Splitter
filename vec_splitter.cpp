
#include <iostream>
#include <vector>

template<typename T>
std::vector<std::vector<T>> split(std::vector<T> main, uint32_t partitions) {

  std::vector<std::vector<T>> vec_collection = {};

  if (partitions < 1) {
    std::cout << "Partion number has to be a positive Non-Zero integer" << std::endl;
  }
  
  if (main.size() < partitions) {
    std::cout << "Too many partitions: Max -> " << main.size() << std::endl;
  }

  for (int i = 0; i < partitions; ++i) {
    std::vector<T> tempvec = {};
    vec_collection.push_back(tempvec);
  }
  // create a collection of vectors/partitions
  
  int current_index = 0;
  
  for (int i = 0; i < main.size(); ++i) {
    if (current_index == partitions) {
      // checks the current subvector positions
      current_index = 0;
      // if its the last vector in the vector collection it will return to the first subvector
    }
    vec_collection.at(current_index).push_back(main.at(i));
    // .at(n) is safer than calling an index of the vector as it will throw an error
    // instead of causing an undefined behaviour and crashing
    current_index++;
  }
  return vec_collection;
}
