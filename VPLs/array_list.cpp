// Copyright [2019] <Micael Presotto>
#ifndef STRUCTURES_ARRAY_LIST_H
#define STRUCTURES_ARRAY_LIST_H

#include <cstdint>


namespace structures {

template<typename T>
class ArrayList {
 public:
    ArrayList();
    explicit ArrayList(std::size_t max_size);
    ~ArrayList();
    void clear();
    void push_back(const T& data);
    void push_front(const T& data);
    void insert(const T& data, std::size_t index);
    void insert_sorted(const T& data);
    T pop(std::size_t index);
    T pop_back();
    T pop_front();
    void remove(const T& data);
    bool full() const;
    bool empty() const;
    bool contains(const T& data) const;
    std::size_t find(const T& data) const;
    std::size_t size() const;
    std::size_t max_size() const;
    T& at(std::size_t index);
    T& operator[](std::size_t index);
    const T& at(std::size_t index) const;
    const T& operator[](std::size_t index) const;
    // descricao do 'operator []' na FAQ da disciplina

 private:
    T* contents;
    std::size_t size_;
    std::size_t max_size_;
    static const auto DEFAULT_SIZE = 10u;
};

}  // namespace structures

#endif

template<typename T>
structures::ArrayList<T>::ArrayList() {
    max_size_ = DEFAULT_SIZE;
    contents = new T[max_size_];
    clear();
}

template<typename T>
structures::ArrayList<T>::ArrayList(std::size_t max) {
    max_size_ = max;
    contents = new T[max_size_];
    clear();
}

template<typename T>
structures::ArrayList<T>::~ArrayList() {
    delete [] contents;
}

template<typename T>
void structures::ArrayList<T>::clear() {
    size_ = 0;
}


template<typename T>
void structures::ArrayList<T>::push_back(const T& data) {
    if (full()) {
        throw std::out_of_range("Lista cheia");
    }
    contents[size_] = data;
    size_++;
}

template<typename T>
void structures::ArrayList<T>::push_front(const T& data) {
    if (full()) {
        throw std::out_of_range("Lista cheia");
    }
    size_++;
    for (int i = static_cast<int>(size_)-1; i > 0; i--) {
        contents[i] = contents[i-1];
    }
    contents[0] = data;
}

template<typename T>
void structures::ArrayList<T>::insert(const T& data, std::size_t index) {
    if (full()) {
        throw std::out_of_range("Lista cheia");
    }
    if (index < 0 || index > size_) {
        throw std::out_of_range("Index fora do intervalo");
    }
    size_++;
    for (int i = static_cast<int>(size_) - 1;
    i >= static_cast<int>(index); i--) {
        contents[i] = contents[i - 1];
    }
    contents[index] = data;
}

template<typename T>
void structures::ArrayList<T>::insert_sorted(const T& data) {
    if (full()) {
        throw std::out_of_range("Lista cheia");
    }
    int atual = 0;
    for (int i = 0; i < static_cast<int>(size_); i++) {
        if (data > contents[i]) {
            atual++;
        }
    }
    this->insert(data, atual);
}

template<typename T>
T structures::ArrayList<T>::pop(std::size_t index) {
    if (empty()) {
        throw std::out_of_range("Lista vazia");
    }
    if (index < 0 || index >= size_) {
        throw std::out_of_range("Index fora do intervalo");
    }
    T var = contents[index];
    for (int i = index; i < static_cast<int>(size_)-1; i++) {
        contents[i] = contents[i+1];
    }
    size_--;
    return var;
}

template<typename T>
T structures::ArrayList<T>::pop_back() {
    if (empty()) {
        throw std::out_of_range("Lista vazia");
    }
    T var = contents[size_ - 1];
    size_--;
    return var;
}

template<typename T>
T structures::ArrayList<T>::pop_front() {
    if (empty()) {
        throw std::out_of_range("Lista vazia");
    }
    T var = contents[0];
    for (int i = 0; i < static_cast<int>(size_); i++) {
        contents[i] = contents[i+1];
    }
    size_--;
    return var;
}

template<typename T>
void structures::ArrayList<T>::remove(const T& data) {
    for (int i = 0; i < static_cast<int>(size_); i++) {
        if (contents[i] == data) {
            pop(i);
        }
    }
}

template<typename T>
bool structures::ArrayList<T>::full() const {
    return size() == max_size();
}

template<typename T>
bool structures::ArrayList<T>::empty()const {
    return size() == 0;
}

template<typename T>
bool structures::ArrayList<T>::contains(const T& data) const {
    for (int i = 0; i < static_cast<int>(size_); i++) {
        if (contents[i] == data) {
            return true;
        }
    }
    return false;
}

template<typename T>
std::size_t structures::ArrayList<T>::find(const T& data) const {
    for (int i = 0; i < static_cast<int>(size_); i++) {
        if (contents[i] == data) {
            return i;
        }
    }
    return size();
}

template<typename T>
std::size_t structures::ArrayList<T>::size() const {
    return size_;
}
template<typename T>
std::size_t structures::ArrayList<T>::max_size() const {
    return max_size_;
}
template<typename T>
T& structures::ArrayList<T>::at(std::size_t index)  {
    if ((index >= 0) && (index < size_)) {
        return contents[index];
    }
    throw std::out_of_range("Não está no intervalo!");
}
template<typename T>
T& structures::ArrayList<T>::operator[](std::size_t index) {
    return contents[index];
}

template<typename T>
const T& structures::ArrayList<T>::at(std::size_t index) const {
    if (index >= 0 && index < size_) {
        return contents[index];
    }
}
template<typename T>
const T& structures::ArrayList<T>::operator[](std::size_t index) const {
    return contents[index];
}