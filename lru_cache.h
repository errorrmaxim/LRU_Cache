#ifndef LRU_CACHE_H
#define LRU_CACHE_H
#include <list>
#include <unordered_map>
#include <data_class.h>
#include <memory>
#include <time.h>
#include <stdio.h>

class LRU_Cache
{
private:

    std::list< std::pair<int, Data_class> > item_list;
    std::unordered_map<int, decltype(item_list.begin()) > item_map;
    size_t cache_size;
    void clean(void);   //clean all elements
public:
    LRU_Cache(int);
    void put(int, std::string); //put elem inside cache
    bool is_empty(int);         //verify
    void show_cache();          //
    void remove_elem(int);
    Data_class call_data(int);  //call elem
    void show_list()
    {
        for(auto entry : item_list)
        {
            std::cout << (entry).first << ' ' << (entry).second << std::endl;
        }
    }

};

#endif // LRU_CACHE_H
