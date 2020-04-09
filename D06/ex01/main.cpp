#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>

struct Data {
    std::string     s1;
    int             n;
    std::string     s2;
};

void *      serialize(void){
    std::srand(std::time(NULL));
    char        alphanum[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *      c = new char[2 * 8 + sizeof(int)];

    for (int i = 0; i < 8; i++)
        c[i] = alphanum[std::rand() % (sizeof(alphanum) - 1)];
    
    *reinterpret_cast<int*>(c + 8) = std::rand();

    for (int i = 0; i < 8; i++)
        c[i + 8 + sizeof(int)] = alphanum[std::rand() % (sizeof(alphanum) - 1)];

    return c;
}

Data * deserialize(void * raw){
    Data *      data = new Data;
    char *      str = reinterpret_cast<char*>(raw);
    
    data->s1 = std::string(str, 8);
    data->n = *reinterpret_cast<int *>(str + 8);
    data->s2 = std::string(str + 8 + sizeof(int), 8);

    return data;

}

int main(void){
    Data *  data = deserialize(serialize());
    std::cout << data->s1 << std::endl;
    std::cout << data->n << std::endl;
    std::cout << data->s2 << std::endl;
}