#include "lru_cache.h"
#include <cassert>

LRU_Cache::LRU_Cache(int size_cache_): cache_size(size_cache_)
{
    assert(size_cache_ > 0);
}


void LRU_Cache::clean(void)
{

        while(item_map.size()>cache_size)
        {
            auto last_it = item_list.end(); last_it --;
            item_map.erase(last_it->first);
            item_list.pop_back();
        }
}



void LRU_Cache::put(int key, std::string val){
    auto it = item_map.find(key);
    if(it != item_map.end()){
            item_list.erase(it->second);
            item_map.erase(it);
    }
    item_list.push_front(make_pair(key,val));
    item_map.insert(make_pair(key, item_list.begin()));
    clean();
}

bool LRU_Cache::is_empty(int key)
{
    return (item_map.count(key)>0);
}

void LRU_Cache::show_cache()
{
    for(auto it = item_map.begin(); it != item_map.end(); it++)
    {
      std::cout << it->first << ' ' << it->second->second << std::endl;
    }

}

void LRU_Cache::remove_elem(int key)
{
    auto it = item_map.find(key);
    if(it != item_map.end()){
            item_list.erase(it->second);
            item_map.erase(it);
    }
}

Data_class LRU_Cache::call_data(int key)
{
    //assert(is_empty(key));  // way with removing element and insert again to the head of cache
    //item_map.erase(key);
    //item_map.insert(*it);

    auto it = item_map.find(key);

    item_list.splice(item_list.begin(), item_list, it->second); // way with splice
    return it->second->second;
}













