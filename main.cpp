#include <lru_cache.h>

using namespace std;




int main(int argc, char *argv[])
{




        LRU_Cache some_cache(10);

        some_cache.put(1, "lol");
        some_cache.put(2, "qwe");
        some_cache.put(3, "dsa");
        some_cache.put(4, "ewq");
        some_cache.put(5, "asd");
        some_cache.put(6, "cxz");
        some_cache.put(7, "zxc");

        some_cache.call_data(6);
        //some_cache.remove_elem(3);

        some_cache.show_list();
        cout << "============" << endl;
        some_cache.show_cache();


























    return 0;
}

//кешы
